#pragma once

#include <stdbool.h>

// this implementation may result in memory leakage problems

typedef struct priorityQueueCDT* priorityQueueADT;

typedef int pQueueElementT;

priorityQueueADT EmptyPriorityQueue(void);

void PriorityEnqueue(priorityQueueADT, pQueueElementT);

pQueueElementT PriorityDequeue(priorityQueueADT);

bool PriorityQueueIsEmpty(priorityQueueADT);
