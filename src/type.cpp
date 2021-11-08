#include "type.h"

std::string parse_Specifier(tree_node *specifier_node) {
	if (!strcmp(specifier_node->child_first_ptr->node->name, "StructSpecifier")) {
		// struct
		return std::string(specifier_node
					->child_first_ptr
					->node
					->child_first_ptr
					->next_child
					->node
					->name+4);
	} else {
		// basic
		return std::string(specifier_node
					->child_first_ptr
					->node
					->name+6);
	}
}

std::list<std::string> parse_ExtDecList(tree_node *ext_dec_list_node) {
	std::list<std::string> var_list;
	while (1) {
		var_list.push_back(ext_dec_list_node
				->child_first_ptr->node
				->child_first_ptr->node
				->child_first_ptr->node
				->name+4);
		if (ext_dec_list_node->child_first_ptr->next_child) {
			ext_dec_list_node = ext_dec_list_node->child_first_ptr
					->next_child
					->next_child
					->node;
		} else break;
	}
	return var_list;
}

std::list<std::string> parse_DecList(tree_node *dec_list_node) {
	std::list<std::string> var_list;
	while (1) {
		var_list.push_back(dec_list_node
				->child_first_ptr->node
				->child_first_ptr->node
				->child_first_ptr->node
				->name+4);
		if (dec_list_node->child_first_ptr->next_child) {
			dec_list_node = dec_list_node->child_first_ptr
					->next_child
					->next_child
					->node;
		} else break;
	}
	return var_list;
}

std::list<std::pair<std::string, std::list<std::string>>> parse_DefList(tree_node *def_list_node) {
	std::list<std::pair<std::string, std::list<std::string>>> vars_table;
	while (def_list_node) {
		std::string type_name = parse_Specifier(def_list_node
							->child_first_ptr->node
							->child_first_ptr->node);
		vars_table.push_back({
			parse_Specifier(def_list_node
					->child_first_ptr->node
					->child_first_ptr->node),
			parse_DecList(def_list_node
					->child_first_ptr->node
					->child_first_ptr
					->next_child->node)
		});
		def_list_node = def_list_node->child_first_ptr->next_child->node;
	}
	return vars_table;
}

std::list<std::pair<std::string, std::string>> parse_VarList(tree_node *var_list_node) {
	std::list<std::pair<std::string, std::string>> var_list;
	while (1) {
		var_list.push_back({
			var_list_node->child_first_ptr->node
				->child_first_ptr->node
				->child_first_ptr->node
				->name+6,
			var_list_node->child_first_ptr->node
				->child_first_ptr->next_child->node
				->child_first_ptr->node
				->name+4
		});
		if (var_list_node->child_first_ptr->next_child) {
			var_list_node = var_list_node->child_first_ptr
						->next_child
						->next_child
						->node;
		}
		else break;
	}
	return var_list;
}