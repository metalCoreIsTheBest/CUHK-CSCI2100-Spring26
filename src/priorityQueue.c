#include <stdlib.h>

#include "../include/priorityQueue.h"

#warning This implementation is from the lecture slides and may cause memory leakage problems

// I add this
#define HEAP_MAX 1000

struct priorityQueueCDT {
    pQueueElementT heap[HEAP_MAX];
    int numOfElem;
};

// I add these macros
#define parent_idx(N) (((N) - 1) / 2)
#define lchild_idx(N) (2 * (N) + 1)
#define rchild_idx(N) (2 * (N) + 2)

priorityQueueADT EmptyPriorityQueue() {
    priorityQueueADT pQ = malloc(sizeof(*pQ));
    pQ->numOfElem = 0;
    return pQ;
}

void PriorityEnqueue(priorityQueueADT pQ, pQueueElementT X) {
    int hole;

    for (hole = (pQ->numOfElem)++;
        hole != 0 && pQ->heap[parent_idx(hole)] > X;
        hole = parent_idx(hole))
    {
        pQ->heap[hole] = pQ->heap[parent_idx(hole)];
    }

    pQ->heap[hole] = X;
}

pQueueElementT PriorityDequeue(priorityQueueADT pQ) {
    pQueueElementT result, v;
    int hole, child;
    if (PriorityQueueIsEmpty(pQ)) exit(EXIT_FAILURE);

    result = pQ->heap[0];
    v = pQ->heap[--(pQ->numOfElem)];

    for (hole = 0; lchild_idx(hole) < pQ->numOfElem; hole = child) {
        child = lchild_idx(hole);
        if (child + 1 < pQ->numOfElem &&
            pQ->heap[child + 1] < pQ->heap[child])
            child++;
        if (v > pQ->heap[child])
            pQ->heap[hole] = pQ->heap[child];
        else
            break;
    }

    pQ->heap[hole] = v;
    return result;
}

bool PriorityQueueIsEmpty(priorityQueueADT pQ) {
    return pQ->numOfElem == 0;
}
