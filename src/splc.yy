%{
	#include "lex.yy.cc"
	#include "type.h"
	#include "inter_code.h"
	#include <map>
	#include <string>
	#include <list>
	#include <unordered_map>
	#include <algorithm>
	#include <cstring>

	using std::map;
	using std::string;
	using std::list;
	using std::pair;

	void yyerror(const char*);
	string insert_array_type(const char *type_name, int length);
	type_t* parse_instance_type_in_struct(struct_var_list, int);
	type_t *find_type_in_value_node(tree_node *leaf);
	type_t *find_type_in_value_node(tree_node *leaf, bool &is_left);
	map<pair<string, int>, string>::iterator find_var_in_table(string var_name);
	int has_error = 0;
	int scope = 0;
	bool scope_flag = false;
	tree_node* root;
	// pair<string, int>, string string:type
	map<pair<string, int>, string> var_table;
	map<string, func_t*> func_table;
	map<string, type_t*> type_table;
%}
%union {
	struct tree_node *tree_node;
}

%type	<tree_node>	Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args 
%token	<tree_node>	INT FLOAT CHAR TYPE STRUCT IF WHILE RETURN SEMI COMMA LC RC
%nonassoc <tree_node> INVALID
%right  <tree_node>	ASSIGN
%left	<tree_node>	OR
%left	<tree_node>	AND
%left	<tree_node>	LT LE GT GE EQ NE
%left	<tree_node>	PLUS MINUS
%left	<tree_node>	MUL DIV
%right	<tree_node>	NOT
%left	<tree_node>	LP RP LB RB
%left	<tree_node> 	ID DOT
%left	<tree_node>	ELSE



/* %type	<tree_node>	INT FLOAT CHAR ID TYPE STRUCT IF ELSE WHILE RETURN DOT SEMI COMMA NOT LC RC */

%%
/* high-level definition */
Program: 
	ExtDefList {
		$$ = make_tree_node("Program", $1->line_no, 0);
		add_child($$, $1);
		root = $$;
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
		var_info_list var_name_list = parse_ExtDecList($2);
#ifdef DEBUG
		std::for_each(var_name_list.begin(), var_name_list.end(), [](const var_info_entry entry) { 
			printf("[%s, %d, %d]", std::get<0>(entry).c_str(), std::get<1>(entry), std::get<2>(entry));
		});
#endif
		if (type_table.count(type_name)) {
			type_t *type = type_table[type_name];
			std::for_each(var_name_list.begin(), var_name_list.end(), [&](const var_info_entry entry) { 
				string var_name = std::get<0>(entry);
				bool is_array = std::get<1>(entry);
				int length = std::get<2>(entry);
				tree_node *exp_node = std::get<3>(entry);
				if (var_table.count({var_name, scope})) {
					printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", $1->line_no, var_name.c_str());
				} else {
					if (is_array) {
						if (length < 0) {
							printf("Error type 21 at Line %d: the length of array is less than 0.\n", $1->line_no);
						} else {
							var_table.insert({{var_name, scope}, insert_array_type(type_name.c_str(), length)});
						}
					} else {
						if (exp_node != nullptr && !type_is_equal(find_type_in_value_node(find_first_right_value_node(exp_node)), type)) {
							printf("Error type 5 at Line %d: unmatching types appear at both sides of the assignment operator\n", $2->line_no);
						}
						var_table.insert({{var_name, scope}, type_name});
					}
					
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
		dec_list vars_table = parse_DefList(
			$1->child_first_ptr->node
			->child_first_ptr->next_child->next_child
			->next_child->node
		);
		// printf("====vars_table.size() = %d\n", vars_table.size());
		std::for_each(vars_table.rbegin(), vars_table.rend(), [&](const dec_entry vars) { 
			string type_name = vars.first;
			var_info_list var_list = vars.second;
			if (!type_table.count(type_name)) {
				printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $1->line_no, type_name.c_str());
			} else {
				std::for_each(var_list.rbegin(), var_list.rend(), [&](const var_info_entry entry) {
					field_list_t *new_node = new field_list_t();

					string var_name = std::get<0>(entry);
					bool is_array = std::get<1>(entry);
					int length = std::get<2>(entry);

					strcpy(new_node->name, var_name.c_str());
					if (is_array) {
						string type_name_array;
						if (length < 0) {
							printf("Error type 21 at Line %d: the length of array is less than 0\n", $1->line_no);
						} else {
							type_name_array = insert_array_type(type_name.c_str(), length);
							new_node->type = type_table[type_name_array];
						}
					} else {
						new_node->type = type_table[type_name];
					}
					new_node->next = head;
					head = new_node;
				});
			}
		});
		ptr->data.structure = head;
		if (type_table.count(struct_name)) {
			printf("Error type 15 at Line %d: redefine the structure type with same name\n", $1->line_no);
		} else {
			bool is_valid = true;
			std::for_each(type_table.begin(), type_table.end(), [&](pair<string, type_t*> p) {
				type_t *type = p.second;
				if (is_valid && type_is_equal(type, ptr)) {
#ifdef DEBUG
					printf("Find the same structure: %s\n", type->name);
#endif
					is_valid = false;
				}
			});
			type_table.insert({struct_name, ptr});
		}
#ifdef DEBUG
		printf("INSERTED [%s, 0x%lx]", struct_name.c_str(), (long)ptr);
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

		func_t *func = func_table[$2->child_first_ptr->node->name+4];

		bool is_valid = 1;
		// check return type
		string ret_type_name = parse_Specifier($1);
		if (!type_table.count(ret_type_name)) {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $1->line_no, ret_type_name.c_str());
			is_valid = 0;
		} else {
			func->ret_type = type_table[ret_type_name];
		}

		return_list ret_list = find_return_list($3);
#ifdef DEBUG
		printf("DETECTED return list: \n");
		std::for_each(ret_list.begin(), ret_list.end(), [&](const return_entry entry) {
			printf("[%s, %d], ", entry.first->name, entry.second);
		});
		puts("");
#endif
		std::for_each(ret_list.begin(), ret_list.end(), [&](const return_entry entry) {
			tree_node *node = entry.first;
			int line_no = entry.second;

			tree_node *leaf = find_first_right_value_node(node);
			type_t *leaf_type = find_type_in_value_node(leaf);
#ifdef DEBUG
			printf("Find return type: [%s]\n", leaf_type->name);
#endif

			if (leaf_type != func->ret_type) {
				printf("Error Type 8 at Line %d: function’s return value type mismatches the declared type\n", line_no);
			}

		});

		for (auto it = var_table.begin(); it != var_table.end(); ) {
			auto const& [var_name, var_scope] = (*it).first;
			if (scope == var_scope) it = var_table.erase(it);
			else ++it;
		}
		scope_flag = false;
		scope--;

	}
	| Specifier error{
		printf("Error type B at Line %d: Missing semicolon 1';'\n",$1->line_no);
	}
	| Specifier ExtDecList error {
		printf("Error type B at Line %d: Missing semicolon 2';'\n",$1->line_no);
	}
	| error SEMI{
		printf("Error type 2B at Line %d: Missing specifier\n", $2->line_no-1);
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
		for (auto it = var_table.begin(); it != var_table.end(); ) {
			auto const& [var_name, var_scope] = (*it).first;
			if (scope == var_scope) it = var_table.erase(it);
			else ++it;
		}
		scope_flag = false;
		scope--;

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
		++scope;
		scope_flag = true;

		func_t *func = new func_t();
		string func_name = $1->name+4;
		if (func_table.count(func_name)) {
			printf("Error Type 4 at Line %d: function \"%s\" is redefined.\n", $2->line_no, func_name.c_str());
		}
		// check para's type & name
		field_list_t *head = 0, *tail = head;

		list<pair<string, string>> var_list = parse_VarList($3);
		std::for_each(var_list.begin(), var_list.end(), [&](const pair<string, string> var) { 
			string para_type_name = var.first;
			string para_name = var.second;
			if (!type_table.count(para_type_name)) {
				printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $2->line_no, para_type_name.c_str());
			} if (var_table.count({para_name, scope})) {
				printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", $2->line_no, para_name.c_str());
			} else {
				field_list_t *new_node = new field_list_t();
				strcpy(new_node->name, para_name.c_str());
				new_node->type = type_table[para_type_name];
				new_node->next = 0;
				if (!head) head = tail = new_node;
				else tail->next = new_node, tail = new_node;

				var_table.insert({{para_name, scope}, para_type_name});
			}
		});
		
		func->args_num = var_list.size();
		func->args_list = head;
		func_table.insert({func_name, func});
#ifdef DEBUG
		printf("Find user-defined function %s:\n", func_name.c_str());
		field_list_t *cur = func->args_list;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif
		$$ = make_tree_node("FunDec", $1->line_no, 0);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}	
	| ID LP RP {
		func_t *func = new func_t();
		string func_name = $1->name+4;
		if (func_table.count(func_name)) {
			printf("Error Type 4 at Line %d: function \"%s\" is redefined.\n", $2->line_no, func_name.c_str());
		}
		func->args_num = 0;
		func_table.insert({func_name, func});

#ifdef DEBUG
		printf("Find user-defined function %s:\n", func_name.c_str());
		field_list_t *cur = func->args_list;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif

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
		// std::remove_if(var_table.begin(), var_table.end(), [&](const auto &entry) -> bool {
		// 	int var_scope = entry.first.second;
		// 	if (scope == var_scope) return true;
		// 	return false;
		// });

		$$ = make_tree_node("CompSt", $1->line_no, 0);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
/*
		dec_list vars_table = parse_DefList($2);
		std::for_each(vars_table.rbegin(), vars_table.rend(), [&](const dec_entry vars) { 
			string type_name = vars.first;
			var_info_list var_list = vars.second;
			if (!type_table.count(type_name)) {
				printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $1->line_no, type_name.c_str());
			} else {
				std::for_each(var_list.rbegin(), var_list.rend(), [&](const var_info_entry entry) {
					string var_name = std::get<0>(entry);
					bool is_array = std::get<1>(entry);
					int length = std::get<2>(entry);

					if (var_table.count(var_name)) {
						printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", $1->line_no, var_name.c_str());
					} else {
						if (is_array) {
							if (length < 0) {
								printf("Error type 21 at Line %d: the length of array is less than 0\n", $1->line_no);
							} else {
								var_table.insert({var_name, insert_array_type(type_name.c_str(), length)});
							}
						} else {
							var_table.insert({var_name, type_name});
						}	
					}
				});
				
			}
		});
*/
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
		for (auto it = var_table.begin(); it != var_table.end(); ) {
			auto const& [var_name, var_scope] = (*it).first;
			if (scope == var_scope) it = var_table.erase(it);
			else ++it;
		}
		scope_flag = false;
		scope--;
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
		printf("Error type B at Line %d: Missing semicolon 3';'\n",$1->line_no);
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
		if (!scope_flag) ++scope;
		scope_flag = false;
	}
	| Def DefList {
		$$ = make_tree_node("DefList", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	;
Def:
	Specifier DecList SEMI {
		if (!scope_flag) ++scope;
		scope_flag = true;
		$$ = make_tree_node("Def", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);

		bool is_valid = 1;
		// check type
		string type_name = parse_Specifier($1);
		if (!type_table.count(type_name)) {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $1->line_no, type_name.c_str());
			is_valid = 0;
		}
		// check names
		var_info_list var_name_list = parse_DecList($2);
		type_t *type = type_table[type_name];
		std::for_each(var_name_list.begin(), var_name_list.end(), [&](const var_info_entry entry) { 
			string var_name = std::get<0>(entry);
			bool is_array = std::get<1>(entry);
			int length = std::get<2>(entry);
			tree_node *exp_node = std::get<3>(entry);
			if (var_table.count({var_name, scope})) {
				printf("Error type 3 at Line %d: variable \"%s\" is redefined.\n", $1->line_no, var_name.c_str());
			} else if (is_valid) {
				if (is_array) {
					if (length < 0) {
						printf("Error type 21 at Line %d: the length of array is less than 0\n", $1->line_no);
					} else {
						var_table.insert({{var_name, scope}, insert_array_type(type_name.c_str(), length)});
					}
				} else {
					if (exp_node != nullptr && !type_is_equal(find_type_in_value_node(find_first_right_value_node(exp_node)), type)) {
						printf("Error type 5 at Line %d: unmatching types appear at both sides of the assignment operator\n", $2->line_no);
					}
					var_table.insert({{var_name, scope}, type_name});
				}
			}
		});
#ifdef DEBUG
		printf("Find local variables of type \"%s\": ", type_name.c_str());
		std::for_each(var_name_list.begin(), var_name_list.end(), [](const var_info_entry entry) { 
			printf("[%s, %d, %d]", std::get<0>(entry).c_str(), std::get<1>(entry), std::get<2>(entry));
		});
		puts("");
#endif
	}
	| Specifier DecList error {
		printf("Error type B at Line %d: Missing semicolon 4';'\n",$1->line_no);	
	}
	| error DecList SEMI {
		printf("Error type 2B at Line %d: Missing specifier\n",$2->line_no-1);
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

		// single varible on the left
		int left_value_cnt = find_all_left_value_node($1).size();
		int right_value_cnt = find_all_right_value_node($1).size();
		if (left_value_cnt == 1 && right_value_cnt == 1) {
			type_t *var_type = find_type_in_value_node(find_first_left_value_node($1));
			tree_node *leaf = find_first_right_value_node($3);
			type_t *leaf_type = find_type_in_value_node(leaf);
			
#ifdef DEBUG
			printf("Detect ASSIGN, left[%s], right[%s]\n", var_type->name, leaf_type->name);
#endif
			if (!type_is_equal(var_type, leaf_type)) {
				printf("Error type 5 at Line %d: unmatching types appear at both sides of the assignment operator\n", $2->line_no);
				$$ = make_tree_node("Exp", $1->line_no, 0);
			} else {
				$$ = make_tree_node("Exp", $1->line_no, 0);
			}
/*		} else if ($1->children_number == 3 && !memcmp($1->child_first_ptr->next_child->node->name, "DOT", 3)) {
			
			struct_var_list struct_list = parse_Struct_Exp($1);
			printf("==OK==\n");

			type_t *var_type = parse_instance_type_in_struct(struct_list, $1->line_no);
			
			tree_node *leaf = find_first_right_value_node($3);
			type_t *leaf_type = find_type_in_value_node(leaf);
#ifdef DEBUG
			printf("Detect ASSIGN: \n, left[%s], right[%s]\n", var_type->name, leaf_type->name);
#endif
			if (var_type != leaf_type) {
				printf("Error type 6 at Line %d: unmatching types appear at both sides of the assignment operator\n", $2->line_no);
				$$ = make_tree_node("Exp", $1->line_no, 0);
			} else {
				$$ = make_tree_node("Exp", $1->line_no, 0);
			}
*/
		} else {
			printf("Error type 6 at Line %d: rvalue appears on the left-hand side of the assignment operator\n", $2->line_no);
			$$ = make_tree_node("Exp", $1->line_no, 0);
		}
		// $$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp AND Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		} else if (type1 != type_table["int"]) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp OR Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		} else if (type1 != type_table["int"]) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp LT Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp LE Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp GT Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp GE Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp NE Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp EQ Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp PLUS Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		} else if (type1 != type_table["int"] && type1 != type_table["float"]) {
			printf("Error type 20 at Line %d: do arithmatic operation on invalid type\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp MINUS Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		} else if (type1 != type_table["int"] && type1 != type_table["float"]) {
			printf("Error type 20 at Line %d: do arithmatic operation on invalid type\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp MUL Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		} else if (type1 != type_table["int"] && type1 != type_table["float"]) {
			printf("Error type 20 at Line %d: do arithmatic operation on invalid type\n", $2->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp DIV Exp {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node($1));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node($3));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", $2->line_no);
		} else if (type1 != type_table["int"] && type1 != type_table["float"]) {
			printf("Error type 20 at Line %d: do arithmatic operation on invalid type\n", $2->line_no);
		}
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
		type_t *type = find_type_in_value_node(find_first_right_value_node($2));
		if (type != type_table["int"] && type != type_table["float"]) {
			printf("Error type 18 at Line %d: MINUS operation is done on an invalid expression\n", $1->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);
	}
	| NOT Exp {
		type_t *type = find_type_in_value_node(find_first_right_value_node($2));
		if (type != type_table["int"]) {
			printf("Error type 17 at Line %d: not operation is done on a non-integer expression\n", $1->line_no);	
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $2);
		add_child($$, $1);		
	}
	| ID LP Args RP {
		
		if (!func_table.count($1->name+4)) {
			if (type_table.count($1->name+4) || find_var_in_table($1->name+4) != var_table.end()) {
				printf("Error type 11 at Line %d: applying function invocation operator on non-function variables\n", $1->line_no);
			} else {
				printf("Error type 2 at Line %d: function \"%s\" is not defined.\n", $1->line_no, $1->name+4);
			}
			
		} else {
			string func_name = string($1->name+4);
			args_list args = parse_Args_list($3);
			field_list_t *func_args = func_table[func_name]->args_list;

			if (args.size() != func_table[func_name]->args_num) {
				printf("Error type 9 at Line %d: the arguments' number does not match, expect: %d, actual: %lu\n", $1->line_no, func_table[func_name]->args_num, args.size());
			} else {
				std::for_each(args.begin(), args.end(), [&](tree_node* node) {
					tree_node *leaf = find_first_right_value_node(node);
					type_t *type = find_type_in_value_node(leaf);
					
					if (type != func_args->type) {
						printf("Error type 9 at Line %d: the arguments' type does not match, expect: %s, actual: %s\n", $1->line_no, func_args->type->name, type->name);
					}
					func_args = func_args->next;
				});
			}
			
		}
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
		if (!func_table.count($1->name+4)) {
			if (type_table.count($1->name+4) || find_var_in_table($1->name+4) != var_table.end()) {
				printf("Error type 11 at Line %d: applying function invocation operator on non-function variables\n", $1->line_no);
			} else {
				printf("Error type 2 at Line %d: function \"%s\" is not defined.\n", $1->line_no, func_name);
			}
		}
		if (func_table[func_name]->args_num != 0) {
			printf("Error type 9 at Line %d: the arguments' number does not match, expect: %d, actual: %d\n", $1->line_no, func_table[func_name]->args_num, 0);
		}
	}
	| Exp DOT ID %prec DOT {
#ifdef DEBUG
		printf("Reduce DOT\n");
#endif
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| Exp LB Exp RB {
#ifdef DEBUG
		printf("Reduce []\n");
#endif
		if (find_all_left_value_node($1).size() != 1 || find_all_right_value_node($1).size() != 1) {
			printf("Error type 10 at Line %d: apply index operator on non-array type\n", $1->line_no);
		} else {
			type_t *type = find_type_in_value_node(find_first_left_value_node($1));
			if (type->category != type_t::ARRAY) {
				printf("Error type 10 at Line %d: apply index operator on non-array type\n", $1->line_no);
			}
		}
		type_t *type_in = find_type_in_value_node(find_first_right_value_node($3));
		if (type_in->category != type_t::PRIMITIVE || type_in->data.primitive != type_t::data_t::ENUM_INT) {
			printf("Error type 12 at Line %d: array indexing with a non-integer type expression\n", $3->line_no);
		}
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $4);
		add_child($$, $3);
		add_child($$, $2);
		add_child($$, $1);
	}
	| ID {
		$$ = make_tree_node("Exp", $1->line_no, 0);
		add_child($$, $1);

		const char *var_name = $1->name+4;
		if (find_var_in_table(var_name) == var_table.end()) {
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

	func_t *func_ptr = new func_t();
	func_ptr->ret_type = nullptr;
	func_ptr->args_num = 1;
	func_ptr->args_list = new field_list_t();
	memset(func_ptr->args_list->name, 0, 32);
	func_ptr->args_list->type = type_table["int"];
	func_ptr->args_list->next = nullptr;
	func_table.insert({string("write"), func_ptr});

	func_ptr = new func_t();
	func_ptr->ret_type = type_table["int"];
	func_ptr->args_num = 0;
	func_ptr->args_list = nullptr;
	func_table.insert({string("read"), func_ptr});
}

type_t* parse_instance_type_in_struct(struct_var_list list, int line_no) {
	if (list.size() == 1) {
		return type_table[(*find_var_in_table(*(list.begin()))).second];
	}
	type_t *cur_type = type_table[(*find_var_in_table(*(list.begin()))).second];
	list.pop_front();
	bool has_error = false;
	std::for_each(list.begin(), list.end(), [&](const string var_name) {
		if (var_name == "&INDEX") {
			if (cur_type->category != type_t::ARRAY) {
				printf("Error type 10 at Line %d: apply index operator on non-array type\n", line_no);
				has_error = true;
			} else {
				cur_type = cur_type->data.array->base;
			}
		} else {
			if (cur_type->category != type_t::STRUCTURE) {
				printf("Error type 13 at Line %d: accessing members of a non-structure variable.\n", line_no);
				has_error = true;
			}
			cur_type = find_instance_type_in_struct(cur_type, var_name);
			if (cur_type == 0) {
				printf("Error type 14 at Line %d: accessing an undefined structure member \"%s\".\n", line_no, var_name.c_str());
				has_error = true;
			}
		}
	});
	if (has_error) return 0;
	else return cur_type;
}

type_t *find_type_in_value_node(tree_node *leaf, bool &is_left) {
	type_t *leaf_type = 0;
	if (!leaf) return 0;
	if (!memcmp(leaf->name, "INT", 3)) {
		leaf_type = type_table["int"];
		is_left = false;
	} else if (!memcmp(leaf->name, "CHAR", 4)) {
		leaf_type = type_table["char"];
		is_left = false;
	} else if (!memcmp(leaf->name, "FLOAT", 5)) {
		leaf_type = type_table["float"];
		is_left = false;
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "DOT")) {
		leaf_type = parse_instance_type_in_struct(parse_Struct_Exp(leaf), leaf->line_no);
		is_left = true;
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "LP")) {
		leaf_type = func_table[leaf->child_first_ptr->node->name+4]->ret_type;
		is_left = false;
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "LB")) {
		struct_var_list list = parse_Struct_Exp(leaf->child_first_ptr->node);
		type_t *array_type = parse_instance_type_in_struct(list, leaf->line_no);
		if (array_type->category == type_t::ARRAY) {
			leaf_type = parse_instance_type_in_struct(list, leaf->line_no)->data.array->base;
		}
		is_left = true;
	} else {
		auto it = find_var_in_table(leaf->name+4);
		if (it != var_table.end()) {
			leaf_type = type_table[(*find_var_in_table(leaf->name+4)).second];
			is_left = true;
		}
	}
	return leaf_type;
}

type_t *find_type_in_value_node(tree_node *leaf) {
	type_t *leaf_type = 0;
	if (!leaf) return 0;
	if (!memcmp(leaf->name, "INT", 3)) {
		leaf_type = type_table["int"];
	} else if (!memcmp(leaf->name, "CHAR", 4)) {
		leaf_type = type_table["char"];
	} else if (!memcmp(leaf->name, "FLOAT", 5)) {
		leaf_type = type_table["float"];
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "DOT")) {
		leaf_type = parse_instance_type_in_struct(parse_Struct_Exp(leaf), leaf->line_no);
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "LP")) { 
		func_t *func_entry = func_table[leaf->child_first_ptr->node->name+4];
		if (!func_entry) {
			leaf_type = 0;
		} else leaf_type = func_entry->ret_type;
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "LB")) {
		struct_var_list list = parse_Struct_Exp(leaf->child_first_ptr->node);
		type_t *array_type = parse_instance_type_in_struct(list, leaf->line_no);
		if (array_type->category == type_t::ARRAY) {
			leaf_type = parse_instance_type_in_struct(list, leaf->line_no)->data.array->base;
		}
	} else {
		auto it = find_var_in_table(leaf->name+4);
		if (it != var_table.end()) {
			leaf_type = type_table[(*find_var_in_table(leaf->name+4)).second];
		}
	}
	return leaf_type;
}

string insert_array_type(const char *type_name, int length) {
	char type_name_array[32];
	sprintf(type_name_array, "%s_%d", type_name, length);
	if (type_table.count(type_name_array)) return string(type_name_array);
	type_t *ptr = new type_t();
	strcpy(ptr->name, type_name_array);
	ptr->category = type_t::ARRAY;
	ptr->data.array = new array_t();
	ptr->data.array->base = type_table[type_name];
	ptr->data.array->size = length;
	type_table.insert({type_name_array, ptr});
	return string(type_name_array);
}

map<pair<string, int>, string>::iterator find_var_in_table(string var_name) {
	map<pair<string, int>, string>::iterator ret;
	int max_scope = -1;
	for (map<pair<string, int>, string>::iterator it = var_table.begin(); it != var_table.end(); ++it) {
		auto entry = *it;
		if (entry.first.first == var_name && entry.first.second > max_scope) {
			ret = it;
			max_scope = entry.first.second;
		}
	}
	if (max_scope == -1) return var_table.end();
	return ret;
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

		if (!has_error){
#ifdef DEBUG
			show_tree(root, 0);
#endif
		show_tree(root, 0);
			//generate_ir(root);
		}
		return 0;
	} else {
		fputs("Too many arguments! Expected: 2\n", stderr);
		return 1;
	}

}