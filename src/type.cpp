#include "type.h"
#include <algorithm>
#include <cstring>
#include "tree_node.h"

std::string parse_Specifier(tree_node* specifier_node) {
    if (!strcmp(specifier_node->child_first_ptr->node->name,
                "StructSpecifier")) {
        // struct
        return std::string(specifier_node->child_first_ptr->node
                               ->child_first_ptr->next_child->node->name +
                           4);
    } else {
        // basic
        return std::string(specifier_node->child_first_ptr->node->name + 6);
    }
}

var_info_list parse_ExtDecList(tree_node* ext_dec_list_node) {
    var_info_list var_list;
    while (1) {
        bool is_array = false;
        int length = 0;
        std::string var_name;
        tree_node* exp_node = nullptr;
        // if single variable
        if (ext_dec_list_node->child_first_ptr->node->child_first_ptr->node
                ->children_number == 1) {
            is_array = false;
            var_name = std::string(
                ext_dec_list_node->child_first_ptr->node->child_first_ptr->node
                    ->child_first_ptr->node->name +
                4);
            if (ext_dec_list_node->child_first_ptr->node->child_first_ptr
                    ->next_child) {
                exp_node = ext_dec_list_node->child_first_ptr->node
                               ->child_first_ptr->next_child->next_child->node;
            }
        } else {
            is_array = true;
            var_name = std::string(
                ext_dec_list_node->child_first_ptr->node->child_first_ptr->node
                    ->child_first_ptr->node->child_first_ptr->node->name +
                4);
            length = std::stoi(
                ext_dec_list_node->child_first_ptr->node->child_first_ptr->node
                    ->child_first_ptr->next_child->next_child->node->name +
                5);
        }
        var_list.push_back({var_name, is_array, length, exp_node});
        if (ext_dec_list_node->child_first_ptr->next_child) {
            ext_dec_list_node = ext_dec_list_node->child_first_ptr->next_child
                                    ->next_child->node;
        } else
            break;
    }
    return var_list;
}

var_info_list parse_DecList(tree_node* dec_list_node) {
    var_info_list var_list;
    while (1) {
        std::string var_name;
        bool is_array = false;
        int length = 0;
        tree_node* exp_node = nullptr;

        if (dec_list_node->child_first_ptr->node->child_first_ptr->node
                ->children_number == 4) {
            is_array = true;
            var_name = std::string(
                dec_list_node->child_first_ptr->node->child_first_ptr->node
                    ->child_first_ptr->node->child_first_ptr->node->name +
                4);
            length = std::stoi(
                dec_list_node->child_first_ptr->node->child_first_ptr->node
                    ->child_first_ptr->next_child->next_child->node->name +
                5);
        } else {
            var_name = std::string(
                dec_list_node->child_first_ptr->node->child_first_ptr->node
                    ->child_first_ptr->node->name +
                4);
            if (dec_list_node->child_first_ptr->node->child_first_ptr
                    ->next_child) {
                exp_node = dec_list_node->child_first_ptr->node->child_first_ptr
                               ->next_child->next_child->node;
            }
        }
        var_list.push_back({var_name, is_array, length, exp_node});

        if (dec_list_node->child_first_ptr->next_child) {
            dec_list_node =
                dec_list_node->child_first_ptr->next_child->next_child->node;
        } else
            break;
    }
    return var_list;
}

dec_list parse_DefList(tree_node* def_list_node) {
    dec_list vars_table;
    while (def_list_node) {
        std::string type_name = parse_Specifier(
            def_list_node->child_first_ptr->node->child_first_ptr->node);
        vars_table.push_back(
            {parse_Specifier(
                 def_list_node->child_first_ptr->node->child_first_ptr->node),
             parse_DecList(def_list_node->child_first_ptr->node->child_first_ptr
                               ->next_child->node)});
        def_list_node = def_list_node->child_first_ptr->next_child->node;
    }
    return vars_table;
}

std::list<std::pair<std::string, std::string>> parse_VarList(
    tree_node* var_list_node) {
    std::list<std::pair<std::string, std::string>> var_list;
    while (1) {
        var_list.push_back(
            {var_list_node->child_first_ptr->node->child_first_ptr->node
                     ->child_first_ptr->node->name +
                 6,
             var_list_node->child_first_ptr->node->child_first_ptr->next_child
                     ->node->child_first_ptr->node->name +
                 4});
        if (var_list_node->child_first_ptr->next_child) {
            var_list_node =
                var_list_node->child_first_ptr->next_child->next_child->node;
        } else
            break;
    }
    return var_list;
}

static inline bool field_is_equal(const field_list_t* lhs,
                                  const field_list_t* rhs) {
    std::list<type_t*> type_list;
    while (lhs) {
        type_list.push_back(lhs->type);
        lhs = lhs->next;
    }
    while (rhs) {
        if (type_list.empty()) {
            return false;
        }
        auto it = std::find_if(
            type_list.begin(), type_list.end(),
            [&rhs](type_t* t) { return type_is_equal(t, rhs->type); });
        if (it == type_list.end()) {
            return false;
        }
        type_list.erase(it);
        rhs = rhs->next;
    }
    return type_list.empty() && rhs == nullptr;
}

bool type_is_equal(const type_t* lhs, const type_t* rhs) {
    if (lhs == nullptr && rhs == nullptr)
        return true;
    if (lhs == nullptr || rhs == nullptr)
        return false;
    if (lhs->category != rhs->category) {
        return false;
    }
    if (lhs->category == type_t::PRIMITIVE) {
        return lhs->data.primitive == rhs->data.primitive;
    }
    if (lhs->category == type_t::ARRAY) {
        return type_is_equal(lhs->data.array->base, rhs->data.array->base) &&
               lhs->data.array->size == rhs->data.array->size;
    }
    if (lhs->category == type_t::STRUCTURE) {
        return field_is_equal(lhs->data.structure, rhs->data.structure);
    }
    __builtin_unreachable();
}

void _parse_Struct_Exp(tree_node* exp, struct_var_list& list) {
    if (!memcmp(exp->child_first_ptr->node->name, "ID", 2)) {
        list.push_back(exp->child_first_ptr->node->name + 4);
        return;
    }
    _parse_Struct_Exp(exp->child_first_ptr->node, list);
    if (exp->children_number == 3)
        list.push_back(
            exp->child_first_ptr->next_child->next_child->node->name + 4);
    else
        list.push_back("&INDEX");
    return;
}

struct_var_list parse_Struct_Exp(tree_node* exp) {
    struct_var_list ret;
    _parse_Struct_Exp(exp, ret);
    return ret;
}

type_t* find_instance_type_in_struct(type_t* struct_type,
                                     std::string instance_name) {
    field_list_t* cur = struct_type->data.structure;
    while (cur) {
        if (!strcmp(cur->name, instance_name.c_str())) {
            return cur->type;
        }
        cur = cur->next;
    }
    return 0;
}

void _find_return_list(tree_node* node, return_list& list) {
    if (!node || !node->child_first_ptr) {
        return;
    } else if (!strcmp(node->child_first_ptr->node->name, "RETURN")) {
        tree_node* leaf = (node->child_first_ptr->next_child->node);
        list.push_back({leaf, node->child_first_ptr->node->line_no});
    } else {
        child_list_node* child = node->child_first_ptr;
        while (child) {
            _find_return_list(child->node, list);
            child = child->next_child;
        }
    }
}

return_list find_return_list(tree_node* node) {
    return_list ret;
    _find_return_list(node, ret);
    return ret;
}

tree_node* find_first_left_value_node(tree_node* node) {
    if (!node)
        return 0;
    else if (node->children_number == 3 &&
             !strcmp(node->child_first_ptr->next_child->node->name, "DOT")) {
        return node;
    } else if (!memcmp(node->name, "ID", 2)) {
        return node;
    } else if ((node->children_number == 4) &&
               !strcmp(node->child_first_ptr->next_child->node->name, "LB")) {
        return node;
    } else {
        child_list_node* child = node->child_first_ptr;
        while (child) {
            tree_node* ret = find_first_left_value_node(child->node);
            if (ret)
                return ret;
            child = child->next_child;
        }
    }
    return 0;
}

args_list parse_Args_list(tree_node* args) {
    args_list list;
    while (1) {
        list.push_back(args->child_first_ptr->node);
        if (args->children_number != 1)
            args = args->child_first_ptr->next_child->next_child->node;
        else
            break;
    }
    return list;
}

void _find_all_left_value_node(tree_node* node, value_node_list& list) {
    if (!node)
        return;
    else if (node->children_number == 3 &&
             !strcmp(node->child_first_ptr->next_child->node->name, "DOT")) {
        list.push_back(node);
        return;
    } else if (!memcmp(node->name, "ID", 2)) {
        list.push_back(node);
        return;
    } else if ((node->children_number == 4) &&
               !strcmp(node->child_first_ptr->next_child->node->name, "LB")) {
        list.push_back(node);
    } else {
        child_list_node* child = node->child_first_ptr;
        while (child) {
            _find_all_left_value_node(child->node, list);
            child = child->next_child;
        }
    }
    return;
}

value_node_list find_all_left_value_node(tree_node* node) {
    value_node_list list;
    _find_all_left_value_node(node, list);
    return list;
}

tree_node* find_first_right_value_node(tree_node* node) {
    if (!node)
        return 0;
    else if (node->children_number == 3 &&
             !strcmp(node->child_first_ptr->next_child->node->name, "DOT")) {
        return node;
    } else if (!memcmp(node->name, "ID", 2) || !memcmp(node->name, "INT", 3) ||
               !memcmp(node->name, "FLOAT", 5) ||
               !memcmp(node->name, "CHAR", 4)) {
        return node;
    } else if ((node->children_number == 3 || node->children_number == 4) &&
               !strcmp(node->child_first_ptr->next_child->node->name, "LP")) {
        return node;
    } else if ((node->children_number == 4) &&
               !strcmp(node->child_first_ptr->next_child->node->name, "LB")) {
        return node;
    } else {
        child_list_node* child = node->child_first_ptr;
        while (child) {
            tree_node* ret = find_first_right_value_node(child->node);
            if (ret)
                return ret;
            child = child->next_child;
        }
    }
    return 0;
}

void _find_all_right_value_node(tree_node* node, value_node_list& list) {
    if (!node)
        return;
    else if (node->children_number == 3 &&
             !strcmp(node->child_first_ptr->next_child->node->name, "DOT")) {
        list.push_back(node);
        return;
    } else if (!memcmp(node->name, "ID", 2) || !memcmp(node->name, "INT", 3) ||
               !memcmp(node->name, "FLOAT", 5) ||
               !memcmp(node->name, "CHAR", 4)) {
        list.push_back(node);
        return;
    } else if ((node->children_number == 3 || node->children_number == 4) &&
               !strcmp(node->child_first_ptr->next_child->node->name, "LP")) {
        list.push_back(node);
        return;
    } else if ((node->children_number == 4) &&
               !strcmp(node->child_first_ptr->next_child->node->name, "LB")) {
        list.push_back(node);
    } else {
        child_list_node* child = node->child_first_ptr;
        while (child) {
            _find_all_right_value_node(child->node, list);
            child = child->next_child;
        }
    }
    return;
}

value_node_list find_all_right_value_node(tree_node* node) {
    value_node_list list;
    _find_all_right_value_node(node, list);
    return list;
}