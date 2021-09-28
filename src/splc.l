%{
	// Declarations, this part will be copied to source file directly.

%}
%option yylineno
letter		[a-zA-Z]
letter_		_|{letter}
number		[0-9]
hex_integer	-?0x[0-9a-fA-F]*
decimal_integer	-?(0|[1-9][0-9]*)

INT		{hex_integer}|{decimal_integer}
FLOAT		TODO
char		TODO
ID		TODO
TYPE		int | float | char
STRUCT		struct
IF		if
ELSE		else
WHILE		while
RETURN		return
DOT		.
SEMI		;
COMMA		,
ASSIGN		=
LT		<
LE		<=
GT		>
GE		>=
NE		!=
EQ		==
PLUS		+
MINUS		-
MUL		*
DIV		/
AND		&&
OR		||
NOT		!
LP		(
RP		)
LB		[
RB		]
LC		{
RC		}
%%
.		{ return TODO; }
%%
/* User Subroutines */