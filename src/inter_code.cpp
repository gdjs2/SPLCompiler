#include "inter_code.h"
int cnt = 0;
// traverse the tree in post-order
void generate_ir(tree_node* root) {
    tree_node* ExtDefList = root->child_first_ptr->node;
    // Program -> ExtDefList
    traverse_ExtDefList(ExtDefList);
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
void traverse_ExtDefList(tree_node* node) {
    if (!node || node->children_number == 0) {
        return;
    } else if (node->children_number == 2) {
        tree_node* ExtDef = node->child_first_ptr->node;
        tree_node* ExtDefList = node->child_first_ptr->next_child->node;

        traverse_ExtDef(ExtDef);
        traverse_ExtDefList(ExtDefList);

        concatenate_ir(node, ExtDef, ExtDefList);
    } else {
        printf("Error in traverse_ExtDefList!");
    }
}

// ExtDefList -> Specifier ExtDecList SEMI +| Specifier SEMI +|Specifier FunDec
// CompSt
void traverse_ExtDef(tree_node* node) {
    if (node->children_number == 3 &&
        !strcmp(node->child_first_ptr->next_child->node->name, "FunDec")) {
        tree_node* Specifier = node->child_first_ptr->node;
        tree_node* FunDec = node->child_first_ptr->next_child->node;
        tree_node* CompSt = node->child_first_ptr->next_child->next_child->node;
        traverse_FunDec(FunDec);
        traverse_CompSt(CompSt);
        concatenate_ir(node, FunDec, CompSt);
    } else {
        printf("Error in traverse_ExtDef!");
    }
}

// FunDec -> ID LP RP | ID LP VarList RP +
void traverse_FunDec(tree_node* node) {
    if (node->children_number == 3) {
        string ir = "FUNCTION " +
                    string(node->child_first_ptr->node->name).substr(4) + " :";
        node->ir.push_back(ir);
    } else if (node->children_number == 4) {
        printf("Not implement");
    } else {
        printf("Error in traverse_ExtDef!");
    }
}

// CompSt -> LC DefList StmtList RC
void traverse_CompSt(tree_node* node) {
    tree_node* DefList = node->child_first_ptr->next_child->node;
    tree_node* StmtList = node->child_first_ptr->next_child->next_child->node;
    traverse_DefList(DefList);
    traverse_StmtList(StmtList);
    concatenate_ir(node, DefList, StmtList);
}

// DefList -> Def DefList | $
void traverse_DefList(tree_node* node) {
    if (!node || node->children_number == 0) {
        return;
    } else if (node->children_number == 2) {
        tree_node* Def = node->child_first_ptr->node;
        tree_node* DefList = node->child_first_ptr->next_child->node;
        traverse_Def(Def);
        traverse_DefList(DefList);
        concatenate_ir(node, Def, DefList);
    } else {
        printf("Error in traverse_DefList");
    }
}

// Def -> Specifier DecList SEMI
void traverse_Def(tree_node* node) {
    tree_node* Specifier = node->child_first_ptr->node;
    tree_node* DecList = node->child_first_ptr->next_child->node;

    traverse_DecList(DecList);
    node->ir = DecList->ir;
}

// DecList -> Dec | Dec COMMA DecList
void traverse_DecList(tree_node* node) {
    if (node->children_number == 1) {
        tree_node* Dec = node->child_first_ptr->node;
        traverse_Dec(Dec);
        node->ir = Dec->ir;
    } else if (node->children_number == 3) {
        tree_node* Dec = node->child_first_ptr->node;
        tree_node* DecList =
            node->child_first_ptr->next_child->next_child->node;
        traverse_Dec(Dec);
        traverse_DecList(DecList);
        concatenate_ir(node, Dec, DecList);
    } else {
        printf("Error in traverse_DecList");
    }
}

// Dec -> VarDec | VarDec ASSIGN Exp
void traverse_Dec(tree_node* node) {
    if (node->children_number == 1) {
        tree_node* VarDec = node->child_first_ptr->node;
        traverse_VarDec(VarDec);
        node->ir = VarDec->ir;
    } else if (node->children_number == 3) {
        tree_node* VarDec = node->child_first_ptr->node;
        tree_node* Exp = node->child_first_ptr->next_child->next_child->node;
        traverse_VarDec(VarDec);
        node->ir_place = VarDec->ir_name;
        traverse_Exp(Exp);

        concatenate_ir(node, VarDec, Exp);

    } else {
        printf("Error in traverse_Dec");
    }
}

// VarDec -> ID | VarDec LB INT RB
void traverse_VarDec(tree_node* node) {
    if (node->children_number == 1) {
        string id = string(node->child_first_ptr->node->name).substr(4);
        node->ir_name = id;

    } else if (node->children_number == 4) {
        printf("Not implemented");
    } else {
        printf("Error in traverse_VarDec");
    }
}

// StmtList -> Stmt StmtList | $
void traverse_StmtList(tree_node* node) {
    if (!node || node->children_number == 0) {
        return;
    } else if (node->children_number == 2) {
        tree_node* Stmt = node->child_first_ptr->node;
        tree_node* StmtList = node->child_first_ptr->next_child->node;
        traverse_Stmt(Stmt);
        traverse_StmtList(StmtList);
        concatenate_ir(node, Stmt, StmtList);
    } else {
        printf("Error in traverse_StmtList");
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
void traverse_Stmt(tree_node* node) {
    if (node->children_number == 3 &&
        !strcmp(node->child_first_ptr->node->name, "RETURN")) {
        // Stmt -> RETURN Exp SEMI
        tree_node* Exp = node->child_first_ptr->next_child->node;
        string place = "t" + to_string(cnt);
        node->ir_place = place;
        traverse_Exp(Exp);
        node->ir = Exp->ir;
        node->ir.push_back("RETURN " + place);
    }
}

void traverse_Exp(tree_node* node) {
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
    } else {
        printf("Not implemented");
    }
}
