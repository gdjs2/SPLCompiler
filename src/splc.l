%{
	#include "splc.tab.h"

	typedef struct tree_node tree_node;
	typedef struct child_list_node child_list_node;

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

%option yylineno
letter		[a-zA-Z]
letter_		_|{letter}
hex_integer	-?0x[0-9a-fA-F]*
decimal_integer	-?(0|[1-9][0-9]*)
float		-?[0-9]+\.[0-9]+
char		'.'
id		{letter_}({letter_}|[0-9])*
white		[\t\r ]

INT		{hex_integer}|{decimal_integer}
FLOAT		{float}
CHAR		{char}
ID		{id}
TYPE		(int|float|char)
WHITE		{white}

%%
{WHITE} { }
\n { }
{INT} { 
#ifdef DEBUG
	printf("<INT, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("INT: ") + strlen(yytext) + 1);
	sprintf(str, "INT: %s", yytext);
	yylval.tree_node = make_tree_node(str);
	return INT; 
}
{FLOAT} { 
#ifdef DEBUG
	printf("<FLOAT, %s>\n", yytext); 
#endif
	char *str = (char*)malloc(sizeof("FLOAT: ") + strlen(yytext) + 1);
	sprintf(str, "FLOAT: %s", yytext);
	yylval.tree_node = make_tree_node(str);
	return FLOAT; 
}
{CHAR} {
#ifdef DEBUG
	printf("<CHAR, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("CHAR: ") + strlen(yytext) + 1);
	sprintf(str, "CHAR: %s", yytext);
	yylval.tree_node = make_tree_node(str);
	return CHAR; 
}
{TYPE} {
#ifdef DEBUG
	printf("<TYPE, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("TYPE: ") + strlen(yytext) + 1);
	sprintf(str, "TYPE: %s", yytext);
	yylval.tree_node = make_tree_node(str);
	return TYPE;
}
"struct" { 
#ifdef DEBUG
	printf("<STRUCT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("STRUCT");
	return STRUCT; 
}
"if" { 
#ifdef DEBUG
	printf("<IF, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("IF");
	return IF; 
}
"else" {
#ifdef DEBUG
	printf("<ELSE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("ELSE");
	return ELSE;
}
"while" {
#ifdef DEBUG
	printf("<WHILE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("WHILE");
	return WHILE; 
}
"return" {
#ifdef DEBUG
	printf("<RETURN, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("RETURN");
	return RETURN; 
}
"." {
#ifdef DEBUG
	printf("<DOT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("DOT");
	return DOT; 
}
";" { 
#ifdef DEBUG
	printf("<SEMI, %s>\n", yytext); 
#endif
	yylval.tree_node = make_tree_node("SEMI");
	return SEMI; 
}
"," {
#ifdef DEBUG
	printf("<COMMA, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("COMMA");
	return COMMA;
}
"=" {
#ifdef DEBUG
	printf("<ASSIGN, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("ASSIGN");
	return ASSIGN;
}
"<" {
#ifdef DEBUG
	printf("<LT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LT");
	return LT;
}
"<=" {
#ifdef DEBUG
	printf("<LE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LT");
	return LE;
}
">" {
#ifdef DEBUG
	printf("<GT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("GT");
	return GT;
}
">=" {
#ifdef DEBUG
	printf("<GE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("GE");
	return GE;
}
"!=" {
#ifdef DEBUG
	printf("<NE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("NE");
	return NE;
}
"==" {
#ifdef DEBUG
	printf("<EQ, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("EQ");
	return EQ;
}
"+" {
#ifdef DEBUG
	printf("<PLUS, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("PLUS");
	return PLUS;
}
"-" {
#ifdef DEBUG
	printf("<MINUS, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("MINUS");
	return MINUS;
}
"*" {
#ifdef DEBUG
	printf("<MUL, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("MUL");
	return MUL; 
}
"/" {
#ifdef DEBUG
	printf("<DIV, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("DIV");
	return DIV; 
}
"&&" {
#ifdef DEBUG
	printf("<AND, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("AND");
	return AND; 
}
"||" {
#ifdef DEBUG
	printf("<OR, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("OR");
	return OR; 
}
"!" {
#ifdef DEBUG
	printf("<NOT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("NOT");
	return NOT; 
}
"(" {
#ifdef DEBUG 
	printf("<LP, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LP");
	return LP; 
}
")" {
#ifdef DEBUG
	printf("<RP, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("RP");
	return RP; 
}
"[" {
#ifdef DEBUG
	printf("<LB, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LB");
	return LB; 
}
"]" {
#ifdef DEBUG
	printf("<RB, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("RB");
	return RB; 
}
"{" {
#ifdef DEBUG
	printf("<LC, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LC");
	return LC; 
}
"}" {
#ifdef DEBUG
	printf("<RC, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("RC");
	return RC; 
}
{ID} {
#ifdef DEBUG
	printf("<ID, %s>\n", yytext); 
#endif
	char *str = (char*)malloc(sizeof("ID: ") + strlen(yytext) + 1);
	sprintf(str, "ID: %s", yytext);
	yylval.tree_node = make_tree_node(str);
	return ID; 
}
<<EOF>> {
#ifdef DEBUG
	printf("END OF THE FILE\n"); 
#endif
	return 0; 
}
. {
	printf("Unknown character\n");
	return 0;
}

%%

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