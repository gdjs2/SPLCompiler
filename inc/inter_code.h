#ifndef __INTER_CODE_H
#define __INTER_CODE_H

#include "tree_node.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
void generate_ir(tree_node*);
void concatenate_ir(tree_node*,tree_node*,tree_node*);
void traverse_ExtDefList(tree_node*);
void traverse_ExtDef(tree_node*);
void traverse_ExtDecList(tree_node*);
void traverse_Specifier(tree_node*) ;
void traverse_StructSpecifier(tree_node*);
void traverse_VarDec(tree_node*);
void traverse_FunDec(tree_node*);
void traverse_VarList(tree_node*);
void traverse_ParamDec(tree_node*);
void traverse_CompSt(tree_node*);
void traverse_StmtList(tree_node*);
void traverse_Stmt(tree_node*);
void traverse_DefList(tree_node*);
void traverse_Def(tree_node*);
void traverse_DecList(tree_node*);
void traverse_Dec(tree_node*);
void traverse_Exp(tree_node*);
void traverse_Args(tree_node*);


#endif