#pragma once

// this implementation of stack may result in memory leakage problems

typedef struct stackCDT* stackADT;

typedef int stackElementT;

stackADT EmptyStack(void);
void Push(stackADT stack, stackElementT element);
stackElementT Pop(stackADT stack);
int StackDepth(stackADT stack);
int StackIsEmpty(stackADT stack);

