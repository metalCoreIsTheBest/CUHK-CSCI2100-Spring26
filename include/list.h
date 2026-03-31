#pragma once

// this implementation of list may result in memory leakage problems

// Note: The lecture notes don't provide a complete implementation of list, so some of the codes are come from myself

typedef struct listCDT *listADT;

typedef int listElementT;



listADT EmptyList(void);

listADT Cons(listElementT x, listADT L1);

listElementT Head(listADT L1);

listADT Tail(listADT L1);

int ListIsEmpty(listADT L1);

int ListLength(listADT L1);

listElementT SumList(listADT L1);

listElementT LastElement(listADT L1);

listADT Append(listADT L1, listElementT x);

listADT Reverse(listADT L1);
