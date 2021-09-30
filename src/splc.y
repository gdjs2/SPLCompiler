%{
	#include "lex.yy.c"

	typedef struct tree_node tree_node;
	typedef struct child_list_node child_list_node;

	void yyerror(const char*);
	tree_node* make_tree_node(const char*);
	child_list_node* make_child_list_node(tree_node*);
	void add_child(tree_node*, tree_node*);
	void show_tree(tree_node*, int);

	struct tree_node {
		const char *name;
		int line_no;
		child_list_node *child_first_ptr;
	};

	struct child_list_node {
		tree_node *tree_node;
		child_list_node *next_child;
	};
%}
%union {
	struct tree_node *tree_node;
}

%token	INT FLOAT CHAR ID TYPE STRUCT IF ELSE WHILE RETURN DOT SEMI COMMA NOT LC RC
%right  ASSIGN
%left	OR
%left	AND
%left	LT LE GT GE EQ NE
%left	PLUS MINUS
%left	MUL DIV
%right	NOT
%left	LP RP LB RB DOT
%left	ELSE

%type	<tree_node>	Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%%
Program: 
	ExtDefList {
		$$ = make_tree_node("Program");
		add_child($$, $1);
		show_tree($$, 0);
	}
	;
ExtDefList: {
		$$ = make_tree_node("ExtDefList");
	}
	| ExtDef ExtDefList {
		$$ = make_tree_node("ExtDefList");
		add_child($$, $2);
		add_child($$, $1);
	}
	;
ExtDef:
	Specifier ExtDecList SEMI {
		$$ = make_tree_node("ExtDef");
		add_child($$, make_tree_node("SEMI"));
		add_child($$, $2);
		add_child($$, $1);
	}
	| Specifier SEMI {
		$$ = make_tree_node("ExtDef");
		add_child($$, make_tree_node("SEMI"));
		add_child($$, $1);
	}
	| Specifier FunDec CompSt {
		$$ = make_tree_node("ExtDef");
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	;
ExtDecList:
	VarDec {
		$$ = make_tree_node("ExtDecList");
		add_child($$, $1);
	}
	| VarDec COMMA ExtDecList {
		$$ = make_tree_node("ExtDecList");
		add_child($$, $3);
		add_child($$, make_tree_node("COMMA"));
		add_child($$, $1);
	}
	;

Specifier:
	TYPE {
		$$ = make_tree_node("Specifier");
		add_child($$, make_tree_node("TYPE"));
	}
	| StructSpecifier {
		$$ = make_tree_node("Specifier");
		add_child($$, $1);
	}
	;
StructSpecifier:
	STRUCT ID LC DefList RC {
		$$ = make_tree_node("StructSpecifier");
		add_child($$, make_tree_node("RC"));
		add_child($$, $4);
		add_child($$, make_tree_node("LC"));
		add_child($$, make_tree_node("ID"));
		add_child($$, make_tree_node("STRUCT"));
	}
	| STRUCT ID {
		$$ = make_tree_node("StructSpecifier");
		add_child($$, make_tree_node("ID"));
		add_child($$, make_tree_node("STRUCT"));
	}
	;

VarDec:
	ID {
		$$ = make_tree_node("VarDec");
		add_child($$, make_tree_node("ID"));
	}
	| VarDec LB INT RB {
		$$ = make_tree_node("VarDec");
		add_child($$, make_tree_node("RB"));
		add_child($$, make_tree_node("INT"));
		add_child($$, make_tree_node("LB"));
		add_child($$, $1);
	}
	;
FunDec:
	ID LP VarList RP {
		$$ = make_tree_node("FunDec");
		add_child($$, make_tree_node("RP"));
		add_child($$, $3);
		add_child($$, make_tree_node("LP"));
		add_child($$, make_tree_node("ID"));
	}
	| ID LP RP {
		$$ = make_tree_node("FunDec");
		add_child($$, make_tree_node("RP"));
		add_child($$, make_tree_node("LP"));
		add_child($$, make_tree_node("ID"));
	}
	;
VarList:
	ParamDec COMMA VarList {
		$$ = make_tree_node("VarList");
		add_child($$, $3);
		add_child($$, make_tree_node("COMMA"));
		add_child($$, $1);
	}
	| ParamDec {
		$$ = make_tree_node("VarList");
		add_child($$, $1);
	}
ParamDec:
	Specifier VarDec {
		$$ = make_tree_node("ParamDec");
		add_child($$, $2);
		add_child($$, $1);
	}
	;

CompSt:
	LC DefList StmtList RC {
		$$ = make_tree_node("CompSt");
		add_child($$, make_tree_node("RC"));
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, make_tree_node("LC"));
	}
	;
StmtList: {
		$$ = make_tree_node("StmtList");
	}
	|  Stmt StmtList {
		$$ = make_tree_node("StmtList");
		add_child($$, $2);
		add_child($$, $1);
	}
	;
Stmt:
	Exp SEMI {
		$$ = make_tree_node("Stmt");
		add_child($$, make_tree_node("SEMI"));
		add_child($$, $1);
	}
	| CompSt {
		$$ = make_tree_node("Stmt");
		add_child($$, $1);
	}
	| RETURN Exp SEMI {
		$$ = make_tree_node("Stmt");
		add_child($$, make_tree_node("SEMI"));
		add_child($$, $2);
		add_child($$, make_tree_node("RETURN"));
	}
	| IF LP Exp RP Stmt {
		$$ = make_tree_node("Stmt");
		add_child($$, $5);
		add_child($$, make_tree_node("RP"));
		add_child($$, $3);
		add_child($$, make_tree_node("LP"));
		add_child($$, make_tree_node("IF"));
	}
	| IF LP Exp RP Stmt ELSE Stmt {
		$$ = make_tree_node("Stmt");
		add_child($$, $7);
		add_child($$, make_tree_node("ELSE"));
		add_child($$, $5);
		add_child($$, make_tree_node("RP"));
		add_child($$, $3);
		add_child($$, make_tree_node("LP"));
		add_child($$, make_tree_node("IF"));
	}
	| WHILE LP Exp RP Stmt {
		$$ = make_tree_node("Stmt");
		add_child($$, $5);
		add_child($$, make_tree_node("RP"));
		add_child($$, $3);
		add_child($$, make_tree_node("LP"));
		add_child($$, make_tree_node("WHILE"));
	}
	;

DefList: {
		$$ = make_tree_node("DefList");
	}
	| Def DefList {
		$$ = make_tree_node("DefList");
		add_child($$, $2);
		add_child($$, $1);
	}
	;
Def:
	Specifier DecList SEMI {
		$$ = make_tree_node("Def");
		add_child($$, make_tree_node("SEMI"));
		add_child($$, $2);
		add_child($$, $1);
	}
	;
DecList:
	Dec {
		$$ = make_tree_node("DecList");
		add_child($$, $1);
	}
	| Dec COMMA DecList {
		$$ = make_tree_node("DecList");
		add_child($$, $3);
		add_child($$, make_tree_node("COMMA"));
		add_child($$, $1);
	}
	;
Dec:
	VarDec {
		$$ = make_tree_node("Dec");
		add_child($$, $1);
	}
	| VarDec ASSIGN Exp {
		$$ = make_tree_node("Dec");
		add_child($$, $3);
		add_child($$, make_tree_node("ASSIGN"));
		add_child($$, $1);
	}
	;

Exp:
	Exp ASSIGN Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("ASSIGN"));
		add_child($$, $1);
	}
	| Exp AND Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("AND"));
		add_child($$, $1);
	}
	| Exp OR Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("OR"));
		add_child($$, $1);
	}
	| Exp LT Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("LT"));
		add_child($$, $1);
	}
	| Exp LE Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("LE"));
		add_child($$, $1);
	}
	| Exp GT Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("GT"));
		add_child($$, $1);
	}
	| Exp GE Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("GE"));
		add_child($$, $1);
	}
	| Exp NE Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("NE"));
		add_child($$, $1);
	}
	| Exp EQ Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("EQ"));
		add_child($$, $1);
	}
	| Exp PLUS Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("PLUS"));
		add_child($$, $1);
	}
	| Exp MINUS Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("MINUS"));
		add_child($$, $1);
	}
	| Exp MUL Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("MUL"));
		add_child($$, $1);
	}
	| Exp DIV Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $3);
		add_child($$, make_tree_node("DIV"));
		add_child($$, $1);
	}
	| LP Exp RP {
		$$ = make_tree_node("Exp");
		add_child($$, make_tree_node("RP"));
		add_child($$, $2);
		add_child($$, make_tree_node("LP"));
	}
	| MINUS Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $2);
		add_child($$, make_tree_node("MINUS"));
	}
	| NOT Exp {
		$$ = make_tree_node("Exp");
		add_child($$, $2);
		add_child($$, make_tree_node("NOT"));
	}
	| ID LP Args RP {
		$$ = make_tree_node("Exp");
		add_child($$, make_tree_node("RP"));
		add_child($$, $3);
		add_child($$, make_tree_node("LP"));
		add_child($$, make_tree_node("ID"));
	}
	| ID LP RP {
		$$ = make_tree_node("Exp");
		add_child($$, make_tree_node("RP"));
		add_child($$, make_tree_node("LP"));
		add_child($$, make_tree_node("ID"));
	}
	| Exp LB Exp RB {
		$$ = make_tree_node("Exp");
		add_child($$, make_tree_node("RB"));
		add_child($$, $3);
		add_child($$, make_tree_node("LB"));
		add_child($$, $1);
	}
	| Exp DOT ID {
		$$ = make_tree_node("Exp");
		add_child($$, make_tree_node("ID"));
		add_child($$, make_tree_node("DOT"));
		add_child($$, $1);
	}
	| ID {
		$$ = make_tree_node("Exp");
		char *str = (char*)malloc(sizeof("ID: ") + strlen(yytext) + 1);
		sprintf(str, "ID: %s", yytext);
		add_child($$, make_tree_node((const char*)str));
	}
	| INT {
		$$ = make_tree_node("Exp");
		char *str = (char*)malloc(sizeof("INT: ") + strlen(yytext) + 1);
		sprintf(str, "INT: %s", yytext);
		add_child($$, make_tree_node((const char*)str));
	}
	| FLOAT {
		$$ = make_tree_node("Exp");
		char *str = (char*)malloc(sizeof("FLOAT: ") + strlen(yytext) + 1);
		sprintf(str, "FLOAT: %s", yytext);
		add_child($$, make_tree_node((const char*)str));
	}
	| CHAR {
		$$ = make_tree_node("Exp");
		char *str = (char*)malloc(sizeof("CHAR: ") + strlen(yytext) + 1);
		sprintf(str, "CHAR: %s", yytext);
		add_child($$, make_tree_node((const char*)str));
	}
	;
Args:
	Exp COMMA Args {
		$$ = make_tree_node("Args");
		add_child($$, $3);
		add_child($$, make_tree_node("COMMA"));
		add_child($$, $1);
	}
	| Exp {
		$$ = make_tree_node("Args");
		add_child($$, $1);
	}
	;

%%

void yyerror(const char* msg) {
	fprintf(stderr, "%s", msg);
}

tree_node* make_tree_node(const char *name) {
	tree_node* node = (tree_node*)malloc(sizeof(tree_node));
	node->name = name;
	node->line_no = yylineno;
	node->child_first_ptr = (child_list_node*)NULL;
	return node;
}

child_list_node* make_child_list_node(tree_node *tree_node) {
	child_list_node *list_node = (child_list_node*)malloc(sizeof(child_list_node));
	list_node->tree_node = tree_node;
	list_node->next_child = (child_list_node*)NULL;
	return list_node;
}

void add_child(tree_node *father, tree_node *child) {
	child_list_node *new_child = make_child_list_node(child);
	new_child->next_child = father->child_first_ptr;
	father->child_first_ptr = new_child;
}

void show_tree(tree_node *node, int level) {
	for (int i = 0; i < (level<<1); ++i) printf(" ");
	printf("%s\n", node->name);
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