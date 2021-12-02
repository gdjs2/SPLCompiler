#include "inter_code.h"

#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int tmp_cnt = 0;
int label_cnt = 0;
string new_place() {
    tmp_cnt++;
    return "t" + std::to_string(tmp_cnt);
}
// translate the tree in post-order
void generate_ir(tree_node* root) {
    tree_node* ExtDefList = root->child_first_ptr->node;
    // Program -> ExtDefList
    translate_ExtDefList(ExtDefList);
    root->ir = ExtDefList->ir;
    for (auto i : root->ir) {
        cout << i << endl;
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

// ExtDefList -> Specifier ExtDecList SEMI +| Specifier SEMI +|Specifier FunDec
// CompSt
void translate_ExtDef(tree_node* node) {
    if (node->children_number == 3 &&
        !strcmp(node->child_first_ptr->next_child->node->name, "FunDec")) {
        tree_node* Specifier = node->child_first_ptr->node;
        tree_node* FunDec = node->child_first_ptr->next_child->node;
        tree_node* CompSt = node->child_first_ptr->next_child->next_child->node;
        translate_FunDec(FunDec);
        translate_CompSt(CompSt);
        concatenate_ir(node, FunDec, CompSt);
    } else {
        printf("Error in translate_ExtDef!");
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
        node->ir.push_back("PARAM: ");

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

// Def -> Specifier DecList SEMI
void translate_Def(tree_node* node) {
    tree_node* Specifier = node->child_first_ptr->node;
    tree_node* DecList = node->child_first_ptr->next_child->node;

    translate_DecList(DecList);
    node->ir = DecList->ir;
}

// DecList -> Dec | Dec COMMA DecList
void translate_DecList(tree_node* node) {
    if (node->children_number == 1) {
        tree_node* Dec = node->child_first_ptr->node;
        translate_Dec(Dec);
        node->ir = Dec->ir;
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
        node->ir = VarDec->ir;
    } else if (node->children_number == 3) {
        tree_node* VarDec = node->child_first_ptr->node;
        tree_node* Exp = node->child_first_ptr->next_child->next_child->node;
        translate_VarDec(VarDec);
        node->ir_place = VarDec->ir_place;
        translate_Exp(Exp);

        concatenate_ir(node, VarDec, Exp);

    } else {
        printf("Error in translate_Dec");
    }
}

// VarDec -> ID | VarDec LB INT RB
void translate_VarDec(tree_node* node) {
    if (node->children_number == 1) {
        string id = string(node->child_first_ptr->node->name).substr(4);
        node->ir_place = id;

    } else if (node->children_number == 4) {
        printf("Not implemented1");
    } else {
        printf("Error in translate_VarDec");
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
        node->ir_place = place;
        translate_Exp(Exp);
        node->ir = Exp->ir;
        node->ir.push_back("RETURN " + place);
    } else if (node->children_number == 1 &&
               !strcmp(node->child_first_ptr->node->name, "CompSt")) {
        // Stmt -> CompSt
        tree_node* CompSt = node->child_first_ptr->node;
        translate_CompSt(CompSt);
        node->ir = CompSt->ir;
    } else if (node->children_number == 2 &&
               !strcmp(node->child_first_ptr->node->name, "Exp")) {
        // Stmt -> Exp SEMI
        tree_node* Exp = node->child_first_ptr->node;
        translate_Exp(Exp);
        node->ir = Exp->ir;
    }
}

void translate_Exp(tree_node* node) {
    string place = node->parent->ir_place;
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
            string variable =
                string(node->child_first_ptr->node->child_first_ptr->node->name)
                    .substr(4);
            node->ir_place = variable;
            translate_Exp(Exp2);
            node->ir = Exp2->ir;
            if (place != "")
                node->ir.push_back(place + "!!! :=" + variable);

        } else if (!strcmp(node->child_first_ptr->next_child->node->name,
                           "PLUS")) {
            string t1 = new_place();
            string t2 = new_place();
            node->ir_place = t1;
            translate_Exp(Exp1);
            node->ir_place = t2;
            translate_Exp(Exp2);
            concatenate_ir(node, Exp1, Exp2);
            node->ir.push_back(place + " := " + t1 + " + " + t2);
        } else if (!strcmp(node->child_first_ptr->next_child->node->name,
                           "MINUS")) {
            string t1 = new_place();
            string t2 = new_place();
            node->ir_place = t1;
            translate_Exp(Exp1);
            node->ir_place = t2;
            translate_Exp(Exp2);
            concatenate_ir(node, Exp1, Exp2);
            node->ir.push_back(place + " := " + t1 + " - " + t2);
        } else if (!strcmp(node->child_first_ptr->next_child->node->name,
                           "MUL")) {
            string t1 = new_place();
            string t2 = new_place();
            node->ir_place = t1;
            translate_Exp(Exp1);
            node->ir_place = t2;
            translate_Exp(Exp2);
            concatenate_ir(node, Exp1, Exp2);
            node->ir.push_back(place + " := " + t1 + " * " + t2);

        } else if (!strcmp(node->child_first_ptr->next_child->node->name,
                           "DIV")) {
            string t1 = new_place();
            string t2 = new_place();
            node->ir_place = t1;
            translate_Exp(Exp1);
            node->ir_place = t2;
            translate_Exp(Exp2);
            concatenate_ir(node, Exp1, Exp2);
            node->ir.push_back(place + " := " + t1 + " / " + t2);
        }
    } else if (node->children_number == 2 &&
               !strcmp(node->child_first_ptr->node->name, "MINUS")) {
        string tp = new_place();
        tree_node* Exp = node->child_first_ptr->next_child->node;
        node->ir_place = tp;
        translate_Exp(Exp);
        node->ir = Exp->ir;
        node->ir.push_back(place + ":=#0" + " - " + tp);

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
               (node->child_first_ptr->next_child->next_child->node->name,
                "Args")) {
        // Exp: ID LP Args RP
        string id = string(node->child_first_ptr->node->name).substr(4);
        tree_node* Args = node->child_first_ptr->next_child->next_child->node;
        translate_Args(Args);
        if (id == "write") {
            tree_node* Exp = Args->child_first_ptr->node;
            string tp = new_place();
            Args->ir_place = tp;
            translate_Exp(Exp);
            node->ir = Exp->ir;
            node->ir.push_back("WRITE " + tp);
        }
    } else if (node->children_number == 3 &&
               !strcmp(node->child_first_ptr->node->name, "LP")) {
        tree_node* Exp = node->child_first_ptr->next_child->node;
        node->ir_place = place;
        translate_Exp(Exp);
        node->ir = Exp->ir;
    }

    else {
        printf("Not implemented2");
    }
}

void translate_Args(tree_node* node) {}
