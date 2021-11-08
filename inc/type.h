#ifndef __TYPE_H
#define __TYPE_H

#include "tree_node.h"
#include <string>
#include <list>
#include <cstring>

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
std::list<std::string> parse_ExtDecList(tree_node*);
std::list<std::string> parse_DecList(tree_node*);
std::list<std::pair<std::string, std::list<std::string>>> parse_DefList(tree_node*);
std::list<std::pair<std::string, std::string>> parse_VarList(tree_node*);


#endif