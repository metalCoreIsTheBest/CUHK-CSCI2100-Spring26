#pragma once

// this implementation of list may result in memory leakage problems

#include <stdio.h>

typedef struct TreeNodeCDT* TreeNodeADT;
struct TreeNodeCDT {
    char * key;
    int nodeData;
};

typedef struct AVLTreeCDT* AVLTreeADT;
struct AVLTreeCDT {
    TreeNodeADT rt;
    AVLTreeADT lst;
    AVLTreeADT rst;
};


AVLTreeADT NonemptyAVLTree(TreeNodeADT, AVLTreeADT, AVLTreeADT);

AVLTreeADT EmptyAVLTree(void);

AVLTreeADT LeftAVLSubTree(AVLTreeADT);

AVLTreeADT RightAVLSubTree(AVLTreeADT);

int AVLTreeIsEmpty(AVLTreeADT);

int AVLTreeHeight(AVLTreeADT);

TreeNodeADT AVLRoot(AVLTreeADT);

TreeNodeADT NewTreeNode(char*, int);

char* GetNodeKey(TreeNodeADT);

int GetNodeData(TreeNodeADT);

AVLTreeADT AVLInsertNode(TreeNodeADT X, AVLTreeADT T);
