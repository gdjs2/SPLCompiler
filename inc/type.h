#ifndef __TYPE_H
#define __TYPE_H

#include "tree_node.h"

typedef struct type_t {
	char name[32];
	enum { PRIMITIVE, ARRAY, STRUCTURE } category;
	union _ {
		enum { ENUM_INT, ENUM_FLOAT, ENUM_CHAR } primitive;
		struct array_t *array;
		struct field_list_t *structure;
	};
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

void parse_specifier(tree_node* node);

#endif