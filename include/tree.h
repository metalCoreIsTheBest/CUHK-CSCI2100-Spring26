#pragma once

// this implementation may result in memory leakage problems

#include <stdbool.h>

typedef struct TreeNodeCDT * TreeNodeADT;
struct TreeNodeCDT {
    char * key;
    int nodeData;
};

typedef struct BinaryTreeCDT *BinaryTreeADT;
struct BinaryTreeCDT {
    TreeNodeADT rt;
    BinaryTreeADT lst;
    BinaryTreeADT rst;
};

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT, BinaryTreeADT, BinaryTreeADT);

BinaryTreeADT EmptyBinaryTree(void);

BinaryTreeADT LeftSubtree(BinaryTreeADT);

BinaryTreeADT RightSubtree(BinaryTreeADT);

bool TreeIsEmpty(BinaryTreeADT);

TreeNodeADT Root(BinaryTreeADT);

TreeNodeADT NewTreeNode(char*, int);

int GetNodeData(TreeNodeADT);

TreeNodeADT SpecialErrNode(void);

bool IsSpecialErrNode(TreeNodeADT);

char *GetNodeKey(TreeNodeADT);

TreeNodeADT FindNode(BinaryTreeADT t, char* key);

BinaryTreeADT InsertNode(BinaryTreeADT t, TreeNodeADT n);

BinaryTreeADT DeleteNode(BinaryTreeADT t, char* k);
