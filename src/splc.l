%{
	#include "splc.tab.h"
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
{WHITE}		{ }
\n		{ }
{INT}		{ printf("<INT, %s>\n", yytext); return INT; }
{FLOAT}		{ printf("<FLOAT, %s>\n", yytext); return FLOAT; }
{CHAR}		{ printf("<CHAR, %s>\n", yytext); return CHAR; }
{TYPE}		{ printf("<TYPE, %s>\n", yytext); return TYPE; }
"struct"	{ printf("<STRUCT, %s>\n", yytext); return STRUCT; }
"if"		{ printf("<IF, %s>\n", yytext); return IF; }
"else"		{ printf("<ELSE, %s>\n", yytext); return ELSE; }
"while"		{ printf("<WHILE, %s>\n", yytext); return WHILE; }
"return"	{ printf("<RETURN, %s>\n", yytext); return RETURN; }
"."		{ printf("<DOT, %s>\n", yytext); return DOT; }
";"		{ printf("<SEMI, %s>\n", yytext); return SEMI; }
","		{ printf("<COMMA, %s>\n", yytext); return COMMA; }
"="		{ printf("<ASSIGN, %s>\n", yytext); return ASSIGN; }
"<"		{ printf("<LT, %s>\n", yytext); return LT; }
"<="		{ printf("<LE, %s>\n", yytext); return LE; }
">"		{ printf("<GT, %s>\n", yytext); return GT; }
">="		{ printf("<GE, %s>\n", yytext); return GE; }
"!="		{ printf("<NE, %s>\n", yytext); return NE; }
"=="		{ printf("<EQ, %s>\n", yytext); return EQ; }
"+"		{ printf("<PLUS, %s>\n", yytext); return PLUS; }
"-"		{ printf("<MINUS, %s>\n", yytext); return MINUS; }
"*"		{ printf("<MUL, %s>\n", yytext); return MUL; }
"/"		{ printf("<DIV, %s>\n", yytext); return DIV; }
"&&"		{ printf("<AND, %s>\n", yytext); return AND; }
"||"		{ printf("<OR, %s>\n", yytext); return OR; }
"!"		{ printf("<NOT, %s>\n", yytext); return NOT; }
"("		{ printf("<LP, %s>\n", yytext); return LP; }
")"		{ printf("<RP, %s>\n", yytext); return RP; }
"["		{ printf("<LB, %s>\n", yytext); return LB; }
"]"		{ printf("<RB, %s>\n", yytext); return RB; }
"{"		{ printf("<LC, %s>\n", yytext); return LC; }
"}"		{ printf("<RC, %s>\n", yytext); return RC; }
{ID}		{ printf("<ID, %s>\n", yytext); return ID; }
<<EOF>>		{ printf("END OF THE FILE\n"); return 0; }
.		{ printf("Unknown character\n"); return 0; }


%%
/* int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
		return 1;
	} else if (argc == 2) {
		if (!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return 1;
		}
		while(yylex());
		return 0;
	} else {
		fputs("Too many arguments! Expected: 2\n", stderr);
		return 1;
	}

} */