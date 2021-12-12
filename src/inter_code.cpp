#include "inter_code.h"
#include "type.h"

#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::make_pair;
using std::ofstream;
using std::stoi;
using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;

unordered_map<string, unordered_map<string, int>> struct_map;
unordered_map<string, string> type_map;

int tmp_cnt = 0;
int label_cnt = 0;
string new_place() {
    tmp_cnt++;
    return "t" + to_string(tmp_cnt);
}
string new_label() {
    label_cnt++;
    return "label" + to_string(label_cnt);
}
// translate the tree in post-order
void generate_ir(tree_node* root, string file_path) {
    if (root == nullptr) {
        printf("Empty parse tree\n");
        return;
    }
    tree_node* ExtDefList = root->child_first_ptr->node;
    // Program -> ExtDefList
    translate_ExtDefList(ExtDefList);
    root->ir = ExtDefList->ir;
    string out_path = file_path.substr(0, file_path.length() - 3) + "ir";
    ofstream fout(out_path);
    for (auto i : root->ir) {
        fout << i << endl;
    }
};

void concatenate_ir(tree_node* target, tree_node* s1, tree_node* s2) {
    if (s1) {
        target->ir.insert(target->ir.end(), s1->ir.begin(), s1->ir.end());
    }
    if (s2) {
        target->ir.insert(target->ir.end(), s2->ir.begin(), s2->ir.end());
    }
};

void concatenate_ir(tree_node* target, tree_node* s1) {
    if (s1) {
        target->ir.insert(target->ir.end(), s1->ir.begin(), s1->ir.end());
    }
};

// ExtDefList -> ExtDef ExtDefList | $
void translate_ExtDefList(tree_node* node) {
    if (!node || node->children_number == 0) {
        return;
    } else if (node->children_number == 2) {
        tree_node* ExtDef = node->child_first_ptr->node;
        tree_node* ExtDefList = node->child_first_ptr->next_child->node;

        translate_ExtDef(ExtDef);
        translate_ExtDefList(ExtDefList);

        concatenate_ir(node, ExtDef, ExtDefList);
    } else {
        printf("Error in translate_ExtDefList!");
    }
}

// ExtDefList -> Specifier ExtDecList SEMI +| Specifier SEMI |Specifier FunDec
// CompSt
void translate_ExtDef(tree_node* node) {
    if (node->children_number == 3 &&
        !strcmp(node->child_first_ptr->next_child->node->name, "FunDec")) {
        tree_node* FunDec = node->child_first_ptr->next_child->node;
        tree_node* CompSt = node->child_first_ptr->next_child->next_child->node;
        translate_FunDec(FunDec);
        translate_CompSt(CompSt);
        concatenate_ir(node, FunDec, CompSt);
    } else if (node->children_number == 2) {
        tree_node* Specifier = node->child_first_ptr->node;
        translate_Specifier(Specifier);
    } else {
        printf("Error in translate_ExtDef!");
    }
}

void translate_Specifier(tree_node* node) {
    if (!strcmp(node->child_first_ptr->node->name, "StructSpecifier")) {
        tree_node* StructSpecifier = node->child_first_ptr->node;
        translate_StructSpecifier(StructSpecifier);
    }
}

void _parse_Struct_DefList(unordered_map<string, int>& umap,
                           tree_node* node,
                           int i) {
    if (!node || node->children_number == 1) {
        return;
    } else {
        string id =
            string(node->child_first_ptr->node->child_first_ptr->next_child
                       ->node->child_first_ptr->node->child_first_ptr->node
                       ->child_first_ptr->node->name)
                .substr(4);
        umap.insert(make_pair(id, i));
        tree_node* DefList = node->child_first_ptr->next_child->node;
        _parse_Struct_DefList(umap, DefList, i + 1);
    }
}
void translate_StructSpecifier(tree_node* node) {
    if (node->children_number == 5) {
        //  STRUCT ID LC DefList RC
        string id =
            string(node->child_first_ptr->next_child->node->name).substr(4);
        unordered_map<string, int> umap;
        tree_node* DefList =
            node->child_first_ptr->next_child->next_child->next_child->node;
        _parse_Struct_DefList(umap, DefList, 0);
        struct_map.insert(make_pair(id, umap));
    } else if (node->children_number == 2) {
    }
}

// FunDec -> ID LP RP | ID LP VarList RP
void translate_FunDec(tree_node* node) {
    if (node->children_number == 3) {
        node->ir.push_back("FUNCTION " +
                           string(node->child_first_ptr->node->name).substr(4) +
                           " :");
    } else if (node->children_number == 4) {
        node->ir.push_back("FUNCTION " +
                           string(node->child_first_ptr->node->name).substr(4) +
                           " :");
        tree_node* VarList =
            node->child_first_ptr->next_child->next_child->node;
        args_list list = parse_Args_list(VarList);
        for (auto i : list) {
            node->ir.push_back("PARAM " +
                               string(i->child_first_ptr->next_child->node
                                          ->child_first_ptr->node->name)
                                   .substr(4));
        }
    } else {
        printf("Error in translate_ExtDef!");
    }
}

// CompSt -> LC DefList StmtList RC
void translate_CompSt(tree_node* node) {
    tree_node* DefList = node->child_first_ptr->next_child->node;
    tree_node* StmtList = node->child_first_ptr->next_child->next_child->node;
    translate_DefList(DefList);
    translate_StmtList(StmtList);
    concatenate_ir(node, DefList, StmtList);
}

// DefList -> Def DefList | $
void translate_DefList(tree_node* node) {
    if (!node || node->children_number == 0) {
        return;
    } else if (node->children_number == 2) {
        tree_node* Def = node->child_first_ptr->node;
        tree_node* DefList = node->child_first_ptr->next_child->node;
        translate_Def(Def);
        translate_DefList(DefList);
        concatenate_ir(node, Def, DefList);
    } else {
        printf("Error in translate_DefList");
    }
}

void _parse_Struct_DecList(tree_node* node, string id) {
    string variable = string(node->child_first_ptr->node->child_first_ptr->node
                                 ->child_first_ptr->node->name)
                          .substr(4);
    type_map.insert(make_pair(variable, id));
    auto size = struct_map[id].size();
    node->ir.push_back("DEC " + variable + " " + to_string(size * 4));
    if (node->children_number == 1) {
        return;
    }
    tree_node* DecList = node->child_first_ptr->next_child->next_child->node;
    _parse_Struct_DecList(DecList, id);
    concatenate_ir(node, DecList);
}
// Def -> Specifier DecList SEMI
void translate_Def(tree_node* node) {
    tree_node* Specifier = node->child_first_ptr->node;
    tree_node* DecList = node->child_first_ptr->next_child->node;
    if (!strcmp(Specifier->child_first_ptr->node->name, "StructSpecifier")) {
        string id = string(Specifier->child_first_ptr->node->child_first_ptr
                               ->next_child->node->name)
                        .substr(4);
        _parse_Struct_DecList(DecList, id);

    } else {
        translate_DecList(DecList);
    }

    concatenate_ir(node, DecList);
}

// DecList -> Dec | Dec COMMA DecList
void translate_DecList(tree_node* node) {
    if (node->children_number == 1) {
        tree_node* Dec = node->child_first_ptr->node;
        translate_Dec(Dec);
        concatenate_ir(node, Dec);
    } else if (node->children_number == 3) {
        tree_node* Dec = node->child_first_ptr->node;
        tree_node* DecList =
            node->child_first_ptr->next_child->next_child->node;
        translate_Dec(Dec);
        translate_DecList(DecList);
        concatenate_ir(node, Dec, DecList);
    } else {
        printf("Error in translate_DecList");
    }
}

// Dec -> VarDec | VarDec ASSIGN Exp
void translate_Dec(tree_node* node) {
    if (node->children_number == 1) {
        tree_node* VarDec = node->child_first_ptr->node;
        translate_VarDec(VarDec);
        concatenate_ir(node, VarDec);
    } else if (node->children_number == 3) {
        tree_node* VarDec = node->child_first_ptr->node;
        tree_node* Exp = node->child_first_ptr->next_child->next_child->node;
        translate_VarDec(VarDec);
        string place;
        if (VarDec->children_number == 1)
            place = string(VarDec->child_first_ptr->node->name).substr(4);
        translate_Exp(Exp, place);

        concatenate_ir(node, VarDec, Exp);

    } else {
        printf("Error in translate_Dec");
    }
}

// VarDec -> ID | VarDec LB INT RB
void translate_VarDec(tree_node* node) {
    if (node->children_number == 4) {
        string id =
            string(node->child_first_ptr->node->child_first_ptr->node->name)
                .substr(4);
        string size =
            string(node->child_first_ptr->next_child->next_child->node->name)
                .substr(5);
        node->ir.push_back("DEC " + id + " " + to_string(stoi(size) * 4));
    }
}

// StmtList -> Stmt StmtList | $
void translate_StmtList(tree_node* node) {
    if (!node || node->children_number == 0) {
        return;
    } else if (node->children_number == 2) {
        tree_node* Stmt = node->child_first_ptr->node;
        tree_node* StmtList = node->child_first_ptr->next_child->node;
        translate_Stmt(Stmt);
        translate_StmtList(StmtList);
        concatenate_ir(node, Stmt, StmtList);
    } else {
        printf("Error in translate_StmtList");
    }
}

/**
 * Stmt -> Exp SEMI
 * | CompSt
 * | RETURN Exp SEMI
 * | IF LP Exp RP Stmt
 * | IF LP Exp RP Stmt ELSE Stmt
 * | WHILE LP Exp RP Stmt
 */
void translate_Stmt(tree_node* node) {
    if (node->children_number == 3 &&
        !strcmp(node->child_first_ptr->node->name, "RETURN")) {
        // Stmt -> RETURN Exp SEMI
        tree_node* Exp = node->child_first_ptr->next_child->node;
        string place = new_place();
        translate_Exp(Exp, place);
        concatenate_ir(node, Exp);
        node->ir.push_back("RETURN " + place);
    } else if (node->children_number == 1 &&
               !strcmp(node->child_first_ptr->node->name, "CompSt")) {
        // Stmt -> CompSt
        tree_node* CompSt = node->child_first_ptr->node;
        translate_CompSt(CompSt);
        concatenate_ir(node, CompSt);
    } else if (node->children_number == 2 &&
               !strcmp(node->child_first_ptr->node->name, "Exp")) {
        // Stmt -> Exp SEMI
        tree_node* Exp = node->child_first_ptr->node;
        string place = new_place();
        translate_Exp(Exp, place);
        concatenate_ir(node, Exp);
    } else if (node->children_number == 5 &&
               !strcmp(node->child_first_ptr->node->name, "IF")) {
        // Stmt -> IF LP Exp RP Stmt
        string lb1 = new_label();
        string lb2 = new_label();
        tree_node* Exp = node->child_first_ptr->next_child->next_child->node;
        tree_node* Stmt = node->child_first_ptr->next_child->next_child
                              ->next_child->next_child->node;
        translate_cond_Exp(Exp, lb1, lb2);
        Exp->ir.push_back("LABEL " + lb1 + " :");
        translate_Stmt(Stmt);
        Stmt->ir.push_back("LABEL " + lb2 + " :");
        concatenate_ir(node, Exp, Stmt);

    } else if (node->children_number == 7) {
        // Stmt -> IF LP Exp RP Stmt ELSE Stmt
        string lb1 = new_label();
        string lb2 = new_label();
        string lb3 = new_label();
        tree_node* Exp = node->child_first_ptr->next_child->next_child->node;
        tree_node* Stmt1 = node->child_first_ptr->next_child->next_child
                               ->next_child->next_child->node;
        tree_node* Stmt2 =
            node->child_first_ptr->next_child->next_child->next_child
                ->next_child->next_child->next_child->node;
        translate_cond_Exp(Exp, lb1, lb2);
        Exp->ir.push_back("LABEL " + lb1 + " :");
        concatenate_ir(node, Exp);
        translate_Stmt(Stmt1);
        Stmt1->ir.push_back("GOTO " + lb3);
        Stmt1->ir.push_back("LABEL " + lb2 + " :");
        translate_Stmt(Stmt2);
        Stmt2->ir.push_back("LABEL " + lb3 + " :");
        concatenate_ir(node, Stmt1, Stmt2);

    } else if (!strcmp(node->child_first_ptr->node->name, "WHILE")) {
        string lb1 = new_label();
        string lb2 = new_label();
        string lb3 = new_label();
        tree_node* Exp = node->child_first_ptr->next_child->next_child->node;
        tree_node* Stmt = node->child_first_ptr->next_child->next_child
                              ->next_child->next_child->node;
        Exp->ir.push_back("LABEL " + lb1 + " :");
        translate_cond_Exp(Exp, lb2, lb3);
        Stmt->ir.push_back("LABEL " + lb2 + " :");
        translate_Stmt(Stmt);
        Stmt->ir.push_back("GOTO " + lb1);

        concatenate_ir(node, Exp, Stmt);
        node->ir.push_back("LABEL " + lb3 + " :");

    } else {
        printf("Error in translate_Stmt");
    }
}

void translate_Exp(tree_node* node, string place) {
    if (node->children_number == 1 &&
        !memcmp(node->child_first_ptr->node->name, "INT", 3)) {
        // Exp -> INT
        string ir = place + " := #" +
                    string(node->child_first_ptr->node->name).substr(5);
        node->ir.push_back(ir);

    } else if (node->children_number == 1 &&
               !memcmp(node->child_first_ptr->node->name, "ID", 2)) {
        // Exp -> ID
        string ir = place + " := " +
                    string(node->child_first_ptr->node->name).substr(4);
        node->ir.push_back(ir);

    } else if (node->children_number == 3 &&
               !strcmp(node->child_first_ptr->node->name, "Exp") &&
               !strcmp(
                   node->child_first_ptr->next_child->next_child->node->name,
                   "Exp")) {
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;

        // Exp -> Exp ASSIGN Exp
        if (!strcmp(node->child_first_ptr->next_child->node->name, "ASSIGN")) {
            if (Exp1->children_number == 4) {
                // array
                string id = string(Exp1->child_first_ptr->node->child_first_ptr
                                       ->node->name)
                                .substr(4);
                string offset_value;

                string offset = new_place();
                if (!memcmp(Exp1->child_first_ptr->next_child->next_child->node
                                ->child_first_ptr->node->name,
                            "INT", 3)) {
                    offset_value =
                        string(Exp1->child_first_ptr->next_child->next_child
                                   ->node->child_first_ptr->node->name)
                            .substr(5);
                    Exp1->ir.push_back(offset + " := #" + offset_value +
                                       " * #4");
                } else {
                    offset_value =
                        string(Exp1->child_first_ptr->next_child->next_child
                                   ->node->child_first_ptr->node->name)
                            .substr(4);
                    Exp1->ir.push_back(offset + " := " + offset_value +
                                       " * #4");
                }

                string address = new_place();
                Exp1->ir.push_back(address + " := " + id + " + " + offset);
                string place = new_place();
                translate_Exp(Exp2, place);
                Exp2->ir.push_back("*" + address + " := " + place);

            } else if (Exp1->children_number == 3) {
                // struct
                string id = string(Exp1->child_first_ptr->node->child_first_ptr
                                       ->node->name)
                                .substr(4);
                string variable = string(Exp1->child_first_ptr->next_child
                                             ->next_child->node->name)
                                      .substr(4);

                string address = new_place();
                int offset = struct_map[type_map[id]][variable];
                Exp1->ir.push_back(address + " := " + id + " + #" +
                                   to_string(offset * 4));
                string place = new_place();
                translate_Exp(Exp2, place);

                Exp2->ir.push_back("*" + address + " := " + place);
            } else {
                string variable = string(node->child_first_ptr->node
                                             ->child_first_ptr->node->name)
                                      .substr(4);
                translate_Exp(Exp2, variable);

                // if (place != "")
                //     node->ir.push_back(place + " := " + variable);
            }
            concatenate_ir(node, Exp1, Exp2);

        } else if (!strcmp(node->child_first_ptr->next_child->node->name,
                           "PLUS")) {
            string t1 = new_place();
            string t2 = new_place();

            translate_Exp(Exp1, t1);
            translate_Exp(Exp2, t2);
            concatenate_ir(node, Exp1, Exp2);
            node->ir.push_back(place + " := " + t1 + " + " + t2);
        } else if (!strcmp(node->child_first_ptr->next_child->node->name,
                           "MINUS")) {
            string t1 = new_place();
            string t2 = new_place();

            translate_Exp(Exp1, t1);
            translate_Exp(Exp2, t2);
            concatenate_ir(node, Exp1, Exp2);
            node->ir.push_back(place + " := " + t1 + " - " + t2);
        } else if (!strcmp(node->child_first_ptr->next_child->node->name,
                           "MUL")) {
            string t1 = new_place();
            string t2 = new_place();

            translate_Exp(Exp1, t1);
            translate_Exp(Exp2, t2);
            concatenate_ir(node, Exp1, Exp2);
            node->ir.push_back(place + " := " + t1 + " * " + t2);

        } else if (!strcmp(node->child_first_ptr->next_child->node->name,
                           "DIV")) {
            string t1 = new_place();
            string t2 = new_place();

            translate_Exp(Exp1, t1);
            translate_Exp(Exp2, t2);
            concatenate_ir(node, Exp1, Exp2);
            node->ir.push_back(place + " := " + t1 + " / " + t2);
        }
    } else if (node->children_number == 2 &&
               !strcmp(node->child_first_ptr->node->name, "MINUS")) {
        string tp = new_place();
        tree_node* Exp = node->child_first_ptr->next_child->node;
        translate_Exp(Exp, tp);
        concatenate_ir(node, Exp);
        node->ir.push_back(place + " := #0" + " - " + tp);

    } else if (node->children_number == 3 &&
               !strcmp(node->child_first_ptr->next_child->node->name, "LP") &&
               !strcmp(
                   node->child_first_ptr->next_child->next_child->node->name,
                   "RP")) {
        // Exp -> ID LP RP
        string id = string(node->child_first_ptr->node->name).substr(4);
        if (id == "read") {
            node->ir.push_back("READ " + place);
        } else {
            node->ir.push_back(place + " := CALL" + id);
        }
    } else if (node->children_number == 4 &&
               !strcmp(node->child_first_ptr->next_child->node->name, "LP") &&
               !strcmp(
                   node->child_first_ptr->next_child->next_child->node->name,
                   "Args")) {
        // Exp -> ID LP Args RP
        string id = string(node->child_first_ptr->node->name).substr(4);
        tree_node* Args = node->child_first_ptr->next_child->next_child->node;
        if (id == "write") {
            tree_node* Exp = Args->child_first_ptr->node;
            string tp = new_place();
            translate_Exp(Exp, tp);
            concatenate_ir(node, Exp);
            node->ir.push_back("WRITE " + tp);
        } else {
            vector<string> arg_list;
            translate_Args(Args, arg_list);
            for (auto i : arg_list) {
                Args->ir.push_back("ARG " + i);
            }
            concatenate_ir(node, Args);
            node->ir.push_back(place + " := CALL " + id);
        }
    } else if (node->children_number == 3 &&
               !strcmp(node->child_first_ptr->node->name, "LP")) {
        // Exp -> LP Exp RP
        tree_node* Exp = node->child_first_ptr->next_child->node;
        translate_Exp(Exp, place);
        concatenate_ir(node, Exp);
    }

    else if (node->children_number == 4 &&
             !strcmp(node->child_first_ptr->next_child->node->name, "LB")) {
        // Exp ->  Exp LB Exp RB
        // array
        string id =
            string(node->child_first_ptr->node->child_first_ptr->node->name)
                .substr(4);
        string offset_value;

        string offset = new_place();
        if (!memcmp(node->child_first_ptr->next_child->next_child->node
                        ->child_first_ptr->node->name,
                    "INT", 3)) {
            offset_value = string(node->child_first_ptr->next_child->next_child
                                      ->node->child_first_ptr->node->name)
                               .substr(5);
            node->ir.push_back(offset + " := #" + offset_value + " * #4");
        } else {
            offset_value = string(node->child_first_ptr->next_child->next_child
                                      ->node->child_first_ptr->node->name)
                               .substr(4);
            node->ir.push_back(offset + " := " + offset_value + " * #4");
        }

        string address = new_place();
        node->ir.push_back(address + " := " + id + " + " + offset);

        node->ir.push_back(place + " := *" + address);

    } else if (node->children_number == 3 &&
               !strcmp(node->child_first_ptr->next_child->node->name, "DOT")) {
        // struct
        string id =
            string(node->child_first_ptr->node->child_first_ptr->node->name)
                .substr(4);
        string variable =
            string(node->child_first_ptr->next_child->next_child->node->name)
                .substr(4);
        auto offset = struct_map[type_map[id]][variable];
        string tp = new_place();
        node->ir.push_back(tp + " := " + id + " + #" + to_string(offset * 4));
        node->ir.push_back(place + " := *" + tp);

    } else {
        printf("Not implemented");
    }
}

void translate_cond_Exp(tree_node* node, string lb_t, string lb_f) {
    if (node->children_number == 2) {
        translate_cond_Exp(node, lb_f, lb_t);
    } else if (!strcmp(node->child_first_ptr->next_child->node->name, "AND")) {
        string lb1 = new_label();
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;
        translate_cond_Exp(Exp1, lb1, lb_f);
        Exp1->ir.push_back("LABEL " + lb1 + " :");
        translate_cond_Exp(Exp2, lb_t, lb_f);
        concatenate_ir(node, Exp1, Exp2);
    } else if (!strcmp(node->child_first_ptr->next_child->node->name, "OR")) {
        string lb1 = new_label();
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;
        translate_cond_Exp(Exp1, lb_t, lb1);
        Exp1->ir.push_back("LABEL " + lb1 + " :");
        translate_cond_Exp(Exp2, lb_t, lb_f);
        concatenate_ir(node, Exp1, Exp2);
    } else if (!strcmp(node->child_first_ptr->next_child->node->name, "EQ")) {
        string t1 = new_place();
        string t2 = new_place();
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;
        translate_Exp(Exp1, t1);
        translate_Exp(Exp2, t2);
        concatenate_ir(node, Exp1, Exp2);
        node->ir.push_back("IF " + t1 + " == " + t2 + " GOTO " + lb_t);
        node->ir.push_back("GOTO " + lb_f);
    } else if (!strcmp(node->child_first_ptr->next_child->node->name, "NE")) {
        string t1 = new_place();
        string t2 = new_place();
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;
        translate_Exp(Exp1, t1);
        translate_Exp(Exp2, t2);
        concatenate_ir(node, Exp1, Exp2);
        node->ir.push_back("IF " + t1 + " != " + t2 + " GOTO " + lb_t);
        node->ir.push_back("GOTO " + lb_f);
    } else if (!strcmp(node->child_first_ptr->next_child->node->name, "GE")) {
        string t1 = new_place();
        string t2 = new_place();
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;
        translate_Exp(Exp1, t1);
        translate_Exp(Exp2, t2);
        concatenate_ir(node, Exp1, Exp2);
        node->ir.push_back("IF " + t1 + " >= " + t2 + " GOTO " + lb_t);
        node->ir.push_back("GOTO " + lb_f);
    } else if (!strcmp(node->child_first_ptr->next_child->node->name, "GT")) {
        string t1 = new_place();
        string t2 = new_place();
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;
        translate_Exp(Exp1, t1);
        translate_Exp(Exp2, t2);
        concatenate_ir(node, Exp1, Exp2);
        node->ir.push_back("IF " + t1 + " > " + t2 + " GOTO " + lb_t);
        node->ir.push_back("GOTO " + lb_f);
    } else if (!strcmp(node->child_first_ptr->next_child->node->name, "LE")) {
        string t1 = new_place();
        string t2 = new_place();
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;
        translate_Exp(Exp1, t1);
        translate_Exp(Exp2, t2);
        concatenate_ir(node, Exp1, Exp2);
        node->ir.push_back("IF " + t1 + " <= " + t2 + " GOTO " + lb_t);
        node->ir.push_back("GOTO " + lb_f);
    } else if (!strcmp(node->child_first_ptr->next_child->node->name, "LT")) {
        string t1 = new_place();
        string t2 = new_place();
        tree_node* Exp1 = node->child_first_ptr->node;
        tree_node* Exp2 = node->child_first_ptr->next_child->next_child->node;
        translate_Exp(Exp1, t1);
        translate_Exp(Exp2, t2);
        concatenate_ir(node, Exp1, Exp2);
        node->ir.push_back("IF " + t1 + " < " + t2 + " GOTO " + lb_t);
        node->ir.push_back("GOTO " + lb_f);
    }
}

// Args -> Exp COMMA Args | Exp
void translate_Args(tree_node* node, vector<string>& arg_list) {
    if (node->children_number == 1) {
        string tp = new_place();
        tree_node* Exp = node->child_first_ptr->node;
        translate_Exp(Exp, tp);
        arg_list.insert(arg_list.begin(), tp);
        concatenate_ir(node, Exp);
    } else {
        string tp = new_place();
        tree_node* Exp = node->child_first_ptr->node;
        tree_node* Args = node->child_first_ptr->next_child->next_child->node;
        translate_Exp(Exp, tp);
        arg_list.insert(arg_list.begin(), tp);
        translate_Args(Args, arg_list);
        concatenate_ir(node, Exp, Args);
    }
}
