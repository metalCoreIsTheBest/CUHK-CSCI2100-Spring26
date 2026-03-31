#pragma once

// this implementation may result in memory leakage problems

#include <stdbool.h>

typedef struct ExprTreeCDT* ExprTreeADT;
typedef struct ExprTreeNodeCDT* ExprTreeNodeADT;

// `operator` is a bad identifier because it is a keyword in c++
enum nodetype {operator, integer};

typedef enum nodetype NodeTypeT;

ExprTreeNodeADT NewOpNode(char);

ExprTreeNodeADT NewIntNode(int);

NodeTypeT NodeType(ExprTreeNodeADT);

char NodeOp(ExprTreeNodeADT);

int NodeValue(ExprTreeNodeADT);

ExprTreeNodeADT ExprTreeRoot(ExprTreeADT);

ExprTreeADT EmptyExprTree(void);

ExprTreeADT NonemptyExprTree(ExprTreeNodeADT, ExprTreeADT, ExprTreeADT);

bool ExprTreeIsEmpty(ExprTreeADT);

ExprTreeADT LeftExprSubtree(ExprTreeADT);

ExprTreeADT RightExprSubtree(ExprTreeADT);
