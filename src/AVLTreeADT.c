#warning This implementation is from the lecture slides and may cause memory leakage problems

#include <stdlib.h>
#include <string.h>

#include "../include/AVLTreeADT.h"

static AVLTreeADT LeftRotate(AVLTreeADT t) {
    AVLTreeADT RSubtree;
    AVLTreeADT NewLSubtree;

    RSubtree = RightAVLSubTree(t);
    NewLSubtree = NonemptyAVLTree(
        AVLRoot(t),
        LeftAVLSubTree(t),
        LeftAVLSubTree(RSubtree)
    );

    return NonemptyAVLTree(
        AVLRoot(RSubtree),
        NewLSubtree,
        RightAVLSubTree(RSubtree)
    );
}

// this is not implemented in the slides, and was left as a homework
static AVLTreeADT RightRotate(AVLTreeADT t) {
    AVLTreeADT LSubTree;
    AVLTreeADT NewRSubTree;

    LSubTree = LeftAVLSubTree(t);
    NewRSubTree = NonemptyAVLTree(
        AVLRoot(t),
        RightAVLSubTree(LSubTree),
        RightAVLSubTree(t)
    );

    return NonemptyAVLTree(
        AVLRoot(LSubTree),
        LeftAVLSubTree(LSubTree),
        NewRSubTree
    );
}

static AVLTreeADT RightLeftrotate(AVLTreeADT t) {
    AVLTreeADT t1;

    t1 = NonemptyAVLTree(
        AVLRoot(t),
        LeftAVLSubTree(t),
        RightRotate(RightAVLSubTree(t))
    );

    return LeftRotate(t1);
}

// this is not implemented in the slides, and was left as a homework
static AVLTreeADT LeftRightRotate(AVLTreeADT t) {
    AVLTreeADT t1;

    t1 = NonemptyAVLTree(
        AVLRoot(t),
        LeftRotate(LeftAVLSubTree(t)),
        RightAVLSubTree(t)
    );

    return RightRotate(t1);
}

AVLTreeADT NonemptyAVLTree(TreeNodeADT N, AVLTreeADT L, AVLTreeADT R) {
    AVLTreeADT t = malloc(sizeof *t);
    t->rt = N;
    t->lst = L;
    t->rst = R;

    return t;
}

AVLTreeADT EmptyAVLTree() {
    return NULL;
}

AVLTreeADT LeftAVLSubtree(AVLTreeADT t) {
    if (AVLTreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->lst;
}

AVLTreeADT RightAVLSubTree(AVLTreeADT t) {
    if (AVLTreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rst;
}

int AVLTreeIsEmpty(AVLTreeADT t) {
    return t == NULL;
}

TreeNodeADT AVLRoot(AVLTreeADT t) {
    if (AVLTreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rt;
}

TreeNodeADT NewTreeNode(char *k, int d) {
    TreeNodeADT N = malloc(sizeof(*N));
    N->key = malloc(sizeof(char) * (strlen(k) + 1));
    strcpy(N->key, k);
    N->nodeData = d;
    return N;
}

char *GetNodeKey(TreeNodeADT N) {
    if (N == NULL)
        exit(EXIT_FAILURE);
    char *k = malloc(sizeof(char) * (strlen(N->key) + 1));
    strcpy(k, N->key);
    return k;
}

int GetNodeData(TreeNodeADT N) {
    return N->nodeData;
}

AVLTreeADT AVLInsertNode(TreeNodeADT X, AVLTreeADT T) {
    if (AVLTreeIsEmpty(T)) return NonemptyAVLTree(
        X, EmptyAVLTree(), EmptyAVLTree()
    );

    int sign = strcmp(GetNodeKey(X), GetNodeKey(AVLRoot(T)));
    if (sign == 0) return NonemptyAVLTree(
        X, LeftAVLSubtree(T), RightAVLSubTree(T)
    );

    if (sign < 0) {
        AVLTreeADT NewTree = NonemptyAVLTree(
            AVLRoot(T),
            AVLInsertNode(X, LeftAVLSubtree(T)),
            RightAVLSubTree(T)
        );

        if (AVLTreeHeight(LeftAVLSubtree(NewTree)) - AVLTreeHeight(RightAVLSubTree(T)) == 2) {
            return (strcmp(GetNodeKey(X), GetNodeKey(AVLRoot(LeftAVLSubtree(NewTree)))) < 0 ?
                RightRotate(NewTree) :
                LeftRightRotate(NewTree)
            );
        }

        return NewTree;
    } else if (sign > 0) {
        AVLTreeADT NewTree = NonemptyAVLTree(AVLRoot(T),
            LeftAVLSubtree(T),
            AVLInsertNode(X, RightAVLSubTree(T))
        );

        if (AVLTreeHeight(RightAVLSubTree(NewTree)) - AVLTreeHeight(LeftAVLSubTree(NewTree)) == 2 )
            return (strcmp(GetNodeKey(X), GetNodeKey(AVLRoot(RightAVLSubTree(NewTree)))) > 0 ?
            LeftRotate(NewTree) :
            RightLeftrotate(NewTree));
        return NewTree;
    }
}
