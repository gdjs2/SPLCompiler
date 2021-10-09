%{
	#include "splc.tab.h"

	typedef struct tree_node tree_node;
	typedef struct child_list_node child_list_node;

	tree_node* make_tree_node(const char*, int, int);
	child_list_node* make_child_list_node(tree_node*);
	void add_child(tree_node*, tree_node*);
	void show_tree(tree_node*, int);

	struct tree_node {
		const char *name;
		int line_no;
		int is_terminate;
		child_list_node *child_first_ptr;
	};

	struct child_list_node {
		tree_node *tree_node;
		child_list_node *next_child;
	};

%}

%option yylineno
digit 		[0-9]
letter		[a-zA-Z]
letter_		_|{letter}
hex_integer	-?0x[0-9a-fA-F]*
decimal_integer	-?(0|[1-9][0-9]*)
float		-?[0-9]+\.[0-9]+
char		'.'
hex_char '\\[xX][0-9a-fA-F]{2}'
id		{letter_}({letter_}|[0-9])*
white		[\t\r ]
invalid_dec    {digit}+
invalid_hex    0(X|x)({digit}|{letter})*
invalid_char   (''|'\\x({digit}|{letter})*')
invalid_id     {digit}({letter}|{digit}|_)+
lexical_err   ({invalid_dec}|{invalid_hex}|{invalid_char}|{invalid_id})


FLOAT		{float}
CHAR		{char}
ID		{id}
TYPE		(int|float|char)
WHITE		{white}

%%
{WHITE} { }
\n { }
{decimal_integer} { 
#ifdef DEBUG
	printf("<INT, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("INT: ") + strlen(yytext) + 1);
	sprintf(str, "INT: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1);
	return INT; 
}
{hex_integer} {
#ifdef DEBUG
	printf("<INT, %s>\n", yytext);
#endif
	int val = 0;
    int l = strlen(yytext), base = 1, dight;
    for (int i = l - 1; i > 1; --i) {
        char now = *(yytext + i);
        if (now >= 'A')
            dight = now - 'A' + 10;
        else
            dight = now - '0';
        val += dight * base;
        base *= 16;
    }
	char *str = (char*)malloc(4);
    sprintf(str, "INT: %d", val);
	yylval.tree_node = make_tree_node(str, 0, 1);
	return INT; 
}
{FLOAT} { 
#ifdef DEBUG
	printf("<FLOAT, %s>\n", yytext); 
#endif
	char *str = (char*)malloc(sizeof("FLOAT: ") + strlen(yytext) + 1);
	sprintf(str, "FLOAT: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1);
	return FLOAT; 
}

{hex_char} {
#ifdef DEBUG
	printf("<CHAR, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("CHAR: ") + strlen(yytext) + 1);
	sprintf(str, "CHAR: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1);
	return CHAR; 
}

{CHAR} {
#ifdef DEBUG
	printf("<CHAR, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("CHAR: ") + strlen(yytext) + 1);
	sprintf(str, "CHAR: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1);
	return CHAR; 
}
{TYPE} {
#ifdef DEBUG
	printf("<TYPE, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("TYPE: ") + strlen(yytext) + 1);
	sprintf(str, "TYPE: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1);
	return TYPE;
}
"struct" { 
#ifdef DEBUG
	printf("<STRUCT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("STRUCT", 0, 1);
	return STRUCT; 
}
"if" { 
#ifdef DEBUG
	printf("<IF, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("IF", 0, 1);
	return IF; 
}
"else" {
#ifdef DEBUG
	printf("<ELSE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("ELSE", 0, 1);
	return ELSE;
}
"while" {
#ifdef DEBUG
	printf("<WHILE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("WHILE", 0, 1);
	return WHILE; 
}
"return" {
#ifdef DEBUG
	printf("<RETURN, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("RETURN", 0, 1);
	return RETURN; 
}
"." {
#ifdef DEBUG
	printf("<DOT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("DOT", 0, 1);
	return DOT; 
}
";" { 
#ifdef DEBUG
	printf("<SEMI, %s>\n", yytext); 
#endif
	yylval.tree_node = make_tree_node("SEMI", 0, 1);
	return SEMI; 
}
"," {
#ifdef DEBUG
	printf("<COMMA, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("COMMA", 0, 1);
	return COMMA;
}
"=" {
#ifdef DEBUG
	printf("<ASSIGN, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("ASSIGN", 0, 1);
	return ASSIGN;
}
"<" {
#ifdef DEBUG
	printf("<LT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LT", 0, 1);
	return LT;
}
"<=" {
#ifdef DEBUG
	printf("<LE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LT", 0, 1);
	return LE;
}
">" {
#ifdef DEBUG
	printf("<GT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("GT", 0, 1);
	return GT;
}
">=" {
#ifdef DEBUG
	printf("<GE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("GE", 0, 1);
	return GE;
}
"!=" {
#ifdef DEBUG
	printf("<NE, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("NE", 0, 1);
	return NE;
}
"==" {
#ifdef DEBUG
	printf("<EQ, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("EQ", 0, 1);
	return EQ;
}
"+" {
#ifdef DEBUG
	printf("<PLUS, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("PLUS", 0, 1);
	return PLUS;
}
"-" {
#ifdef DEBUG
	printf("<MINUS, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("MINUS", 0, 1);
	return MINUS;
}
"*" {
#ifdef DEBUG
	printf("<MUL, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("MUL", 0, 1);
	return MUL; 
}
"/" {
#ifdef DEBUG
	printf("<DIV, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("DIV", 0, 1);
	return DIV; 
}
"&&" {
#ifdef DEBUG
	printf("<AND, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("AND", 0, 1);
	return AND; 
}
"||" {
#ifdef DEBUG
	printf("<OR, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("OR", 0, 1);
	return OR; 
}
"!" {
#ifdef DEBUG
	printf("<NOT, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("NOT", 0, 1);
	return NOT; 
}
"(" {
#ifdef DEBUG 
	printf("<LP, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LP", 0, 1);
	return LP; 
}
")" {
#ifdef DEBUG
	printf("<RP, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("RP", 0, 1);
	return RP; 
}
"[" {
#ifdef DEBUG
	printf("<LB, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LB", 0, 1);
	return LB; 
}
"]" {
#ifdef DEBUG
	printf("<RB, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("RB", 0, 1);
	return RB; 
}
"{" {
#ifdef DEBUG
	printf("<LC, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("LC", 0, 1);
	return LC; 
}
"}" {
#ifdef DEBUG
	printf("<RC, %s>\n", yytext);
#endif
	yylval.tree_node = make_tree_node("RC", 0, 1);
	return RC; 
}
{ID} {
#ifdef DEBUG
	printf("<ID, %s>\n", yytext); 
#endif
	char *str = (char*)malloc(sizeof("ID: ") + strlen(yytext) + 1);
	sprintf(str, "ID: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1);
	return ID; 
}
"//" {
	char c;
	while ((c = input()) != '\n');
	// return 0;
}
<<EOF>> {
#ifdef DEBUG
	printf("END OF THE FILE\n"); 
#endif
	return 0; 
}

{lexical_err}|. {
	fprintf(stdout, "Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext);
	return INVALID;
}

%%

tree_node* make_tree_node(const char *name, int line_no, int is_terminate) {
	tree_node* node = (tree_node*)malloc(sizeof(tree_node));
	node->name = name;
	node->line_no = line_no ? line_no : yylineno;
	node->child_first_ptr = (child_list_node*)NULL;
	node->is_terminate = is_terminate;
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