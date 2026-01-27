#pragma once

// this implementation of list may result in memory leakage problems

typedef struct listCDT *listADT;

typedef int listElementT;



listADT EmptyList(void);

listADT Cons(listElementT, listADT);

listElementT Head(listADT);

listADT Tail(listADT);

int ListIsEmpty(listADT);

listElementT SumList(listADT L1);

listElementT LastElement(listADT L1);

listADT Append(listADT L1, listElementT x);

