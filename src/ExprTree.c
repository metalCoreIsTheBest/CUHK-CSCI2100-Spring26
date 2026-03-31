#include <stdlib.h>

#include "../include/ExprTree.h"

#warning This implementation is from the lecture slides and may cause memory leakage problems

struct ExprTreeCDT {
    ExprTreeNodeADT N;
    ExprTreeADT L, R;
};

struct ExprTreeNodeCDT {
    NodeTypeT T;
    union {
        char op;
        int value;
    } content;
};

ExprTreeNodeADT NewOpNode(char op) {
    ExprTreeNodeADT N = malloc(sizeof(*N));
    N->T = operator;
    N->content.op = op;

    return N;
}

ExprTreeNodeADT NewIntNode(int v) {
    ExprTreeNodeADT N = malloc(sizeof(*N));
    N->T = integer;
    N->content.value = v;

    return N;
}

NodeTypeT NodeType(ExprTreeNodeADT N) {
    return N->T;
}

char NodeOp(ExprTreeNodeADT N) {
    return N->content.op;
}

int NodeValue(ExprTreeNodeADT N) {
    return N->content.value;
}

ExprTreeADT EmptyExprTree(void) {
    return NULL;
}

ExprTreeADT NonemptyExprTree(ExprTreeNodeADT N, ExprTreeADT L, ExprTreeADT R) {
    ExprTreeADT t = malloc(sizeof(*t));
    t->N = N;
    t->L = L;
    t->R = R;

    return t;
}

ExprTreeNodeADT ExprTreeRoot(ExprTreeADT t) {
    return t->N;
}

ExprTreeADT LeftExprSubtree(ExprTreeADT t) {
    return t->L;
}

ExprTreeADT RightExprSubtree(ExprTreeADT t) {
    return t->R;
}
