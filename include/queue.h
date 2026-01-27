#pragma once

// this implementation of queue may result in memory leakage problems

#include <stdlib.h>

typedef struct queueCDT *queueADT;
typedef int queueElementT;


queueADT EmptyQueue(void);

void Enqueue(queueADT queue, queueElementT element);

queueElementT Dequeue(queueADT queue);

int QueueLength(queueADT queue);

int QueueIsEmpty(queueADT queue);

