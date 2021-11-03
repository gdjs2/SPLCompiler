#include "tree_node.h"
#include "splc.tab.hh"
#include <cstdlib>

extern int yylineno;

tree_node* make_tree_node(const char *name, int line_no, int is_terminate) {
	tree_node* node = (tree_node*)malloc(sizeof(tree_node));
	node->name = name;
	node->line_no = line_no ? line_no : yylineno;
	node->child_first_ptr = (child_list_node*)NULL;
	node->is_terminate = is_terminate;
	return node;
}

child_list_node* make_child_list_node(tree_node *tree_node) {
	child_list_node *list_node = (child_list_node*)malloc(sizeof(child_list_node));
	list_node->tree_node = tree_node;
	list_node->next_child = (child_list_node*)NULL;
	return list_node;
}

void add_child(tree_node *father, tree_node *child) {
	child_list_node *new_child = make_child_list_node(child);
	new_child->next_child = father->child_first_ptr;
	father->child_first_ptr = new_child;
}