%{
	#include "splc.tab.hh"
	#include "tree_node.h"
	#include <cstdlib>
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
	yylval.tree_node = make_tree_node(str, 0, 1, atoi(yytext));
	return INT; 
}
{hex_integer} {
#ifdef DEBUG
	printf("<INT, %s>\n", yytext);
#endif
	int val = (int)strtol(yytext, 0, 16);
	char *str = (char*)malloc(sizeof("INT: ") + strlen(yytext) + 1);
    	sprintf(str, "INT: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1, val);
	return INT; 
}
{FLOAT} { 
#ifdef DEBUG
	printf("<FLOAT, %s>\n", yytext); 
#endif
	char *str = (char*)malloc(sizeof("FLOAT: ") + strlen(yytext) + 1);
	sprintf(str, "FLOAT: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1, (float)atof(yytext));
	return FLOAT; 
}

{hex_char} {
#ifdef DEBUG
	printf("<CHAR, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("CHAR: ") + strlen(yytext) + 1);
	sprintf(str, "CHAR: %s", yytext);
	char val = (char)strtol(yytext+3, 0, 16);
	yylval.tree_node = make_tree_node(str, 0, 1, val);
	return CHAR; 
}

{CHAR} {
#ifdef DEBUG
	printf("<CHAR, %s>\n", yytext);
#endif
	char *str = (char*)malloc(sizeof("CHAR: ") + strlen(yytext) + 1);
	sprintf(str, "CHAR: %s", yytext);
	yylval.tree_node = make_tree_node(str, 0, 1, *yytext);
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
	while ((c = yyinput()) != '\n');
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