%{
	#include "lex.yy.c"

	typedef struct tree_node tree_node;
	typedef struct child_list_node child_list_node;

	void yyerror(const char*);
	tree_node* make_tree_node();
	child_list_node* make_child_list_node(tree_node*);
	void add_child(tree_node*, tree_node*);

	struct tree_node {
		enum yytokentype type;
		int line_no;
		child_list_node *child_first_ptr;
	};

	struct child_list_node {
		tree_node *tree_node;
		child_list_node *next_child;
	};
%}
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

%%
Program:
	  ExtDefList
	;
ExtDefList:
	| ExtDef ExtDefList
	;
ExtDef:
	  Specifier ExtDecList SEMI
	| Specifier SEMI
	| Specifier FunDec CompSt
	;
ExtDecList:
	  VarDec
	| VarDec COMMA ExtDecList
	;

Specifier:
	  TYPE
	| StructSpecifier
	;
StructSpecifier:
	  STRUCT ID LC DefList RC
	| STRUCT ID
	;

VarDec:
	  ID
	| VarDec LB INT RB
	;
FunDec:
	  ID LP VarList RP
	| ID LP RP
	;
VarList:
	  ParamDec COMMA VarList
	| ParamDec
ParamDec:
	  Specifier VarDec
	;

CompSt:
	  LC DefList StmtList RC
	;
StmtList:
	|  Stmt StmtList
	;
Stmt:
	  Exp SEMI
	| CompSt
	| RETURN Exp SEMI
	| IF LP Exp RP Stmt
	| IF LP Exp RP Stmt ELSE Stmt
	| WHILE LP Exp RP Stmt
	;

DefList:
	| Def DefList
	;
Def:
	Specifier DecList SEMI
	;
DecList:
	  Dec
	| Dec COMMA DecList
	;
Dec:
	  VarDec
	| VarDec ASSIGN Exp
	;

Exp:
	  Exp ASSIGN Exp
	| Exp AND Exp
	| Exp OR Exp
	| Exp LT Exp
	| Exp LE Exp
	| Exp GT Exp
	| Exp GE Exp
	| Exp NE Exp
	| Exp EQ Exp
	| Exp PLUS Exp
	| Exp MINUS Exp
	| Exp MUL Exp
	| Exp DIV Exp
	| LP Exp RP
	| MINUS Exp
	| NOT Exp
	| ID LP Args RP
	| ID LP RP
	| Exp LB Exp RB
	| Exp DOT ID
	| ID
	| INT
	| FLOAT
	| CHAR
	;
Args:
	  Exp COMMA Args
	| Exp
	;

%%

void yyerror(const char* msg) {
	fprintf(stderr, "%s", msg);
}

tree_node* make_tree_node(enum yytokentype type) {
	tree_node* node = (tree_node*)malloc(sizeof(tree_node));
	node->type = type;
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