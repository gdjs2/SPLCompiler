#ifndef __TREE_NODE_H
#define __TREE_NODE_H

typedef struct tree_node tree_node;
typedef struct child_list_node child_list_node;

// struct value_node {
// 	enum { INT_VALUE, FLOAT_VALUE, CHAR_VALUE, BOOL_VALUE} value_type;
	
// 	union {
// 		int int_value;
// 		float float_value;
// 		char char_value;
// 		bool bool_value;
// 	};
// };

struct tree_node {
	const char *name;
	int line_no;
	int is_terminate;
	int children_number;
	child_list_node *child_first_ptr;
	// value_node *value;
};

struct child_list_node {
	tree_node *node;
	child_list_node *next_child;
};

tree_node* make_tree_node(const char*, int, int);
tree_node* make_tree_node(const char*, int, int, int);
tree_node* make_tree_node(const char*, int, int, float);
tree_node* make_tree_node(const char*, int, int, char);
tree_node* make_tree_node(const char*, int, int, bool);
// tree_node* make_tree_node(const char*, int, int, const value_node*);
child_list_node* make_child_list_node(tree_node*);
void add_child(tree_node*, tree_node*);
void show_tree(tree_node*, int);
tree_node* find_first_leaf_node(tree_node*);
#endif