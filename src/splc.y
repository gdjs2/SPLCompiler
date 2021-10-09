%{
	#include "lex.yy.c"
	void yyerror(const char*);
	int has_error = 0;
%}
%union {
	struct tree_node *tree_node;
}

%token	<tree_node>	INT FLOAT CHAR ID TYPE STRUCT IF WHILE RETURN SEMI COMMA LC RC 
%nonassoc <tree_node> INVALID
%right  <tree_node>	ASSIGN
%left	<tree_node>	OR
%left	<tree_node>	AND
%left	<tree_node>	LT LE GT GE EQ NE
%left	<tree_node>	PLUS MINUS
%left	<tree_node>	MUL DIV
%right	<tree_node>	NOT
%left	<tree_node>	LP RP LB RB DOT
%left	<tree_node>	ELSE

%type	<tree_node>	Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args 

/* %type	<tree_node>	INT FLOAT CHAR ID TYPE STRUCT IF ELSE WHILE RETURN DOT SEMI COMMA NOT LC RC */

%%
/* high-level definition */
Program: 
	ExtDefList {
		$$ = make_tree_node("Program", $1->line_no, 0);
		add_child($$, $1);
		if (!has_error)
			show_tree($$, 0);
	}
	;
ExtDefList: {
		$$ = NULL;
	}
	| ExtDef ExtDefList {
		$$ = make_tree_node("ExtDefList", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	;
ExtDef:
	Specifier ExtDecList SEMI {
		$$ = make_tree_node("ExtDef", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Specifier SEMI {
		$$ = make_tree_node("ExtDef", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Specifier FunDec CompSt {
		$$ = make_tree_node("ExtDef", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Specifier error{
		printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no);
	}
	| Specifier ExtDecList error {
		printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no);
	}
	| error SEMI{
		printf("Error type B at Line %d: Missing specifier\n", $2->line_no-1);
	} 
	;
ExtDecList:
	VarDec {
		$$ = make_tree_node("ExtDecList", $1->line_no, 0);
		add_child($$, $1);
	}
	| VarDec COMMA ExtDecList {
		$$ = make_tree_node("ExtDecList", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	;

/* specifier */
Specifier:
	TYPE {
		$$ = make_tree_node("Specifier", $1->line_no, 0);
		add_child($$, $1);
	}
	| StructSpecifier {
		$$ = make_tree_node("Specifier", $1->line_no, 0);
		add_child($$, $1);
	}
	;
StructSpecifier:
	STRUCT ID LC DefList RC {
		$$ = make_tree_node("StructSpecifier", $1->line_no, 0);
		add_child($$, $5);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| STRUCT ID {
		$$ = make_tree_node("StructSpecifier", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	;

/* declarator */
VarDec:
	ID {
		$$ = make_tree_node("VarDec", $1->line_no, 0);
		add_child($$, $1);
	}
	| INVALID {
		$$ = make_tree_node("VarDec", $1->line_no, 0);
		add_child($$, $1);
		has_error=1;
	}
	| VarDec LB INT RB {
		$$ = make_tree_node("VarDec", $1->line_no, 0);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	;
FunDec:
	ID LP VarList RP {
		$$ = make_tree_node("FunDec", $1->line_no, 0);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| ID LP RP {
		$$ = make_tree_node("FunDec", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| ID LP VarList error    {
        printf("Error type B at Line %d: Missing closing parenthesis ')'\n",$1->line_no);
    }
    | ID LP error    {
        printf("Error type B at Line %d: Missing closing parenthesis ')'\n",$1->line_no);
    }
	;
VarList:
	ParamDec COMMA VarList {
		$$ = make_tree_node("VarList", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| ParamDec {
		$$ = make_tree_node("VarList", $1->line_no, 0);
		add_child($$, $1);
	}
	;
ParamDec:
	Specifier VarDec {
		$$ = make_tree_node("ParamDec", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	;

/* statement */
CompSt:
	LC DefList StmtList RC {
		$$ = make_tree_node("CompSt", $1->line_no, 0);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	;
StmtList: {
		$$ = NULL;
	}
	| Stmt StmtList {
		$$ = make_tree_node("StmtList", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	;
Stmt:
	Exp SEMI {
		$$ = make_tree_node("Stmt", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	| CompSt {
		$$ = make_tree_node("Stmt", $1->line_no, 0);
		add_child($$, $1);
	}
	| RETURN Exp SEMI {
		$$ = make_tree_node("Stmt", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| IF LP Exp RP Stmt {
		$$ = make_tree_node("Stmt", $1->line_no, 0);
		add_child($$, $5);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| IF LP Exp RP Stmt ELSE Stmt {
		$$ = make_tree_node("Stmt", $1->line_no, 0);
		add_child($$, $7);
		add_child($$, $6);
		add_child($$, $5);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| WHILE LP Exp RP Stmt {
		$$ = make_tree_node("Stmt", $1->line_no, 0);
		add_child($$, $5);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp error {
		printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no);
	}
    | RETURN Exp error {
		printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no);
	}
	| IF LP Exp error Stmt    { 
        printf("Error type B at Line %d: Missing closing parenthesis ')'\n",$1->line_no);
    }
    | WHILE LP Exp error Stmt    {
        printf("Error type B at Line %d: Missing closing parenthesis ')'\n",$1->line_no);
    }
	;

/* local definition */

DefList: {
		$$ = NULL; 
	}
	| Def DefList {
		$$ = make_tree_node("DefList", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	;
Def:
	Specifier DecList SEMI {
		$$ = make_tree_node("Def", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Specifier DecList error{
		printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no);	
	}
	| error DecList SEMI{
		printf("Error type B at Line %d: Missing specifier\n",$2->line_no-1);
	}
	;
DecList:
	Dec {
		$$ = make_tree_node("DecList", $1->line_no, 0);
		add_child($$, $1);
	}
	| Dec COMMA DecList {
		$$ = make_tree_node("DecList", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	;
Dec:
	VarDec {
		$$ = make_tree_node("Dec", $1->line_no, 0);
		add_child($$, $1);
	}
	| VarDec ASSIGN Exp {
		$$ = make_tree_node("Dec", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	;

/* Expression */
Exp:
	Exp ASSIGN Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp AND Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp OR Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp LT Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp LE Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp GT Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp GE Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp NE Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp EQ Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp PLUS Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp MINUS Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp MUL Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp DIV Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| LP Exp RP {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| MINUS Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	| NOT Exp {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	| ID LP Args RP {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| ID LP RP {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp LB Exp RB {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp DOT ID {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| ID {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $1);
	}
	| INT {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $1);
	}
	| FLOAT {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $1);
	}
	| CHAR {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $1);
	}
	| Exp INVALID Exp {
		has_error = 1;
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| INVALID {
		has_error = 1;
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $1);
	}
	| LP Exp error{
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",$1->line_no);
    }
    | ID LP Args error{
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",$1->line_no);
    }
    | ID LP error{
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",$1->line_no);
    }
	;
Args:
	Exp COMMA Args {
		$$ = make_tree_node("Args", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp {
		$$ = make_tree_node("Args", $1->line_no, 0);
		add_child($$, $1);
	}
	;

%%

void yyerror(const char* msg) {
	has_error=1;
}

void show_tree(tree_node *node, int level) {
	if (!node) return ;
	for (int i = 0; i < (level<<1); ++i) printf(" ");
	if (node->is_terminate) printf("%s\n", node->name);
	else printf("%s (%d)\n", node->name, node->line_no);
	for (child_list_node *cur = node->child_first_ptr; cur; cur = cur->next_child) {
		show_tree(cur->tree_node, level+1);
	}
	return ;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
		return 1;
	} else if (argc == 2) {
		if (!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return 1;
		}
		yyparse();
		return 0;
	} else {
		fputs("Too many arguments! Expected: 2\n", stderr);
		return 1;
	}

}