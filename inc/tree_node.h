#ifndef __TREE_NODE_H
#define __TREE_NODE_H

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

#endif