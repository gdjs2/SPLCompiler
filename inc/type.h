#ifndef __TYPE_H
#define __TYPE_H

#include "tree_node.h"
#include <string>
#include <list>
#include <cstring>
#include <tuple>

typedef std::tuple<std::string, bool, int, tree_node*> var_info_entry;
typedef std::list<var_info_entry> var_info_list;
typedef std::list<std::pair<std::string, var_info_list>> dec_list;
typedef std::pair<std::string, var_info_list> dec_entry;
typedef std::pair<tree_node*, int> return_entry;
typedef std::list<return_entry> return_list;
typedef std::list<std::string> struct_var_list;
typedef std::list<tree_node*> args_list;
typedef std::list<tree_node*> value_node_list;

typedef struct type_t {
	char name[32];
	enum { PRIMITIVE, ARRAY, STRUCTURE } category;
	union data_t {
		enum { ENUM_INT, ENUM_FLOAT, ENUM_CHAR } primitive;
		struct array_t *array;
		struct field_list_t *structure;
	} data;
} type_t;

typedef struct array_t {
	type_t *base;
	int size;
} array_t;

typedef struct func_t {
	type_t *ret_type;
	int args_num;
	field_list_t *args_list;
} func_t;

typedef struct field_list_t {
	char name[32];
	type_t *type;
	field_list_t *next;
} field_list_t;

std::string parse_Specifier(tree_node*);
var_info_list parse_ExtDecList(tree_node *ext_dec_list_node);
var_info_list parse_DecList(tree_node *dec_list_node);
dec_list parse_DefList(tree_node *def_list_node);
std::list<std::pair<std::string, std::string>> parse_VarList(tree_node*);
bool type_is_equal(const type_t*, const type_t*);
struct_var_list parse_Struct_Exp(tree_node*);
type_t* find_instance_type_in_struct(type_t *struct_type, std::string instance_name);
return_list find_return_list(tree_node*);
tree_node* find_first_left_value_node(tree_node* node);
args_list parse_Args_list(tree_node*);
value_node_list find_all_left_value_node(tree_node*);
tree_node* find_first_right_value_node(tree_node* node);
value_node_list find_all_right_value_node(tree_node*);

#endif