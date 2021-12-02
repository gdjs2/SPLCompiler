#include "tree_node.h"
#include <memory.h>
#include <cstdlib>
#include "splc.tab.hh"

extern int yylineno;

tree_node* make_tree_node(const char* name, int line_no, int is_terminate) {
    tree_node* node = (tree_node*)malloc(sizeof(tree_node));
    node->name = name;
    node->line_no = line_no ? line_no : yylineno;
    node->child_first_ptr = (child_list_node*)NULL;
    node->is_terminate = is_terminate;
    node->children_number = 0;
    // node->value = 0;
    return node;
}

tree_node* make_tree_node(const char* name,
                          int line_no,
                          int is_terminate,
                          int int_value) {
    tree_node* node = make_tree_node(name, line_no, is_terminate);
    // node->value = new value_node();
    // node->value->value_type = node->value->INT_VALUE;
    // node->value->int_value = int_value;
    return node;
}

tree_node* make_tree_node(const char* name,
                          int line_no,
                          int is_terminate,
                          float float_value) {
    tree_node* node = make_tree_node(name, line_no, is_terminate);
    // node->value = new value_node();
    // node->value->value_type = node->value->FLOAT_VALUE;
    // node->value->float_value = float_value;
    return node;
}

tree_node* make_tree_node(const char* name,
                          int line_no,
                          int is_terminate,
                          char char_value) {
    tree_node* node = make_tree_node(name, line_no, is_terminate);
    // node->value = new value_node();
    // node->value->value_type = node->value->CHAR_VALUE;
    // node->value->char_value = char_value;
    return node;
}

tree_node* make_tree_node(const char* name,
                          int line_no,
                          int is_terminate,
                          bool bool_value) {
    tree_node* node = make_tree_node(name, line_no, is_terminate);
    // node->value = new value_node();
    // node->value->value_type = node->value->BOOL_VALUE;
    // node->value->bool_value = bool_value;
    return node;
}

// tree_node* make_tree_node(const char *name, int line_no, int is_terminate,
// const value_node *value) { 	tree_node *node = make_tree_node(name, line_no,
// is_terminate); 	node->value = new value_node();
// memcpy(node->value, value, sizeof(value_node)); 	return node;
// }

child_list_node* make_child_list_node(tree_node* tree_node) {
    child_list_node* list_node =
        (child_list_node*)malloc(sizeof(child_list_node));
    list_node->node = tree_node;
    list_node->next_child = (child_list_node*)NULL;
    return list_node;
}

void add_child(tree_node* father, tree_node* child) {
    child_list_node* new_child = make_child_list_node(child);
    new_child->next_child = father->child_first_ptr;
    father->child_first_ptr = new_child;
    father->children_number++;
}

tree_node* find_first_leaf_node(tree_node* root) {
    while (root->children_number) {
        root = root->child_first_ptr->node;
    }
    return root;
}