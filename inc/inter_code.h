#ifndef __INTER_CODE_H
#define __INTER_CODE_H

#include "tree_node.h"

void generate_ir(tree_node*);
void concatenate_ir(tree_node*, tree_node*, tree_node*);
void translate_ExtDefList(tree_node*);
void translate_ExtDef(tree_node*);
void translate_ExtDecList(tree_node*);
void translate_Specifier(tree_node*);
void translate_StructSpecifier(tree_node*);
void translate_VarDec(tree_node*);
void translate_FunDec(tree_node*);
void translate_VarList(tree_node*);
void translate_ParamDec(tree_node*);
void translate_CompSt(tree_node*);
void translate_StmtList(tree_node*);
void translate_Stmt(tree_node*);
void translate_DefList(tree_node*);
void translate_Def(tree_node*);
void translate_DecList(tree_node*);
void translate_Dec(tree_node*);
void translate_Exp(tree_node*);
void translate_Args(tree_node*);

#endif