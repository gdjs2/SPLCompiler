%{
	#include "lex.yy.c"
	#include "type.h"
	#include <map>
	#include <string>
	#include <list>
	#include <unordered_map>
	using std::map;
	using std::string;
	using std::pair;
	using std::list;
	void yyerror(const char*);
	int has_error = 0;

	map<string, string> var_table;
	map<string, func_t*> func_table;
	map<string, type_t*> type_table;
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

		// printf("Find global type: %s\n", type_name.c_str());
		string type_name = parse_Specifier($1);
		std::list<string> var_name_list = parse_ExtDecList($2);
		// std::for_each(var_name_list.begin(), var_name_list.end(), [](const string str) { printf("%s ", str.c_str()); });
		if (type_table.count(type_name)) {
			std::for_each(var_name_list.begin(), var_name_list.end(), [&](const string var_name) { 
				if (var_table.count(var_name)) {
					printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", $1->line_no, var_name.c_str());
				} else {
					var_table.insert({var_name, type_name});
				}
			});
		} else {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $1->line_no, type_name.c_str());
		}
		
		
	}
	| Specifier SEMI {
		$$ = make_tree_node("ExtDef", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);

		string struct_name = parse_Specifier($1);
		type_t *ptr = new type_t();
		strcpy(ptr->name, struct_name.c_str());
		ptr->category = type_t::STRUCTURE;

		field_list_t *head = 0;
		list<pair<string, list<string>>> vars_table = parse_DefList(
			$1	->child_first_ptr->node
				->child_first_ptr->next_child->next_child
				->next_child->node
		);
		// printf("====vars_table.size() = %d\n", vars_table.size());
		std::for_each(vars_table.rbegin(), vars_table.rend(), [&](const pair<string, list<string>> vars) { 
			string type_name = vars.first;
			list<string> var_list = vars.second;
			if (!type_table.count(type_name)) {
				printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $1->line_no, type_name.c_str());
			} else {
				type_t *type = type_table[type_name];
				for (list<string>::reverse_iterator it = var_list.rbegin(); it != var_list.rend(); ++it) {
					field_list_t *new_node = new field_list_t();
					strcpy(new_node->name, (*it).c_str());
					new_node->type = type;
					new_node->next = head;
					head = new_node;
				}
			}
		});
		ptr->data.structure = head;
		type_table.insert({struct_name, ptr});
#ifdef DEBUG
		printf("Find user-defined struct: %s:\n", struct_name.c_str());
		field_list_t *cur = head;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif
	}
	| Specifier FunDec CompSt {
		$$ = make_tree_node("ExtDef", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);

		bool is_valid = 1;
		func_t *func = new func_t();
		// check return type
		string ret_type_name = parse_Specifier($1);
		if (!type_table.count(ret_type_name)) {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $1->line_no, ret_type_name.c_str());
			is_valid = 0;
		} else {
			func->ret_type = type_table[ret_type_name];
		}
		// check name
		string func_name = $2->child_first_ptr->node->name+4;
		if (func_table.count(func_name)) {
			printf("Error Type 4 at Line %d: function \"%s\" is redefined.\n", $2->line_no, func_name.c_str());
			is_valid = 0;
		}
		// check para's type & name
		field_list_t *head = 0, *tail = head;

		if ($2->children_number == 4) {
			list<pair<string, string>> var_list = parse_VarList(
				$2->child_first_ptr
				->next_child
				->next_child
				->node
			);
			std::for_each(var_list.begin(), var_list.end(), [&](const pair<string, string> var) { 
				string para_type_name = var.first;
				string para_name = var.second;
				if (!type_table.count(para_type_name)) {
					printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $2->line_no, para_type_name.c_str());
					is_valid = 0;
				} if (var_table.count(para_name)) {
					printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", $2->line_no, para_name.c_str());
					is_valid = 0;
				} else {
					field_list_t *new_node = new field_list_t();
					strcpy(new_node->name, para_name.c_str());
					new_node->type = type_table[para_type_name];
					new_node->next = 0;
					if (!head) head = tail = new_node;
					else tail->next = new_node, tail = new_node;
				}
			});
			func->args_num = var_list.size();
		} else if ($2->children_number == 3) {
			func->args_num = 0;
		}

		func->args_list = head;
		if (is_valid) func_table.insert({func_name, func});

#ifdef DEBUG
		printf("Find user-defined function %s:\n", func_name.c_str());
		printf("Return type: %s\n", func->ret_type->name);
		field_list_t *cur = func->args_list;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif

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
	Dec {
		$$ = make_tree_node("ExtDecList", $1->line_no, 0);
		add_child($$, $1);
	}
	| Dec COMMA ExtDecList {
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

		bool is_valid = 1;
		// check type
		string type_name = parse_Specifier($1);
		if (!type_table.count(type_name)) {
			is_valid = 0;
		}
		// check names
		list<string> var_name_list = parse_DecList($2);
		std::for_each(var_name_list.begin(), var_name_list.end(), [&](const string var_name) { 
			if (var_table.count(var_name)) {
				printf("Error type 3 at Line %d: variable \"%s\" is redefined.\n", $1->line_no, var_name.c_str());
			} else if (is_valid) {
				var_table.insert({var_name, type_name});
			}
		});
#ifdef DEBUG
		printf("Find local variables of type \"%s\": ", type_name.c_str());
		std::for_each(var_name_list.begin(), var_name_list.end(), [&](const string var_name) { 
			printf("%s ", var_name.c_str());
		});
		puts("");
#endif
		
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

		const char *func_name = $1->name+4;
		if (!func_table.count(func_name)) {
			printf("Error type 2 at Line %d: function \"%s\" is not defined.\n", $1->line_no, func_name);
		}
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

		const char *var_name = $1->name+4;
		if (!var_table.count(var_name)) {
			printf("Error type 1 at Line %d: variable \"%s\" is used without definition.\n", $1->line_no, var_name);
		}
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
		show_tree(cur->node, level+1);
	}
	return ;
}

void init() {
	type_t *ptr = new type_t();
	strcpy(ptr->name, "INT");
	ptr->category = type_t::PRIMITIVE;
	ptr->data.primitive = type_t::data_t::ENUM_INT;
	type_table.insert({string("int"), ptr});

	ptr = new type_t();
	strcpy(ptr->name, "FLOAT");
	ptr->category = type_t::PRIMITIVE;
	ptr->data.primitive = type_t::data_t::ENUM_FLOAT;
	type_table.insert({string("float"), ptr});

	ptr = new type_t();
	strcpy(ptr->name, "CHAR");
	ptr->category = type_t::PRIMITIVE;
	ptr->data.primitive = type_t::data_t::ENUM_CHAR;
	type_table.insert({string("char"), ptr});
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
		init();
		yyparse();
		return 0;
	} else {
		fputs("Too many arguments! Expected: 2\n", stderr);
		return 1;
	}

}