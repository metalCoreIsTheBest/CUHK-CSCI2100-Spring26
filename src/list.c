#warning This implementation is from the lecture slides and may cause memory leakage problems

#include <stdlib.h>

#include "../include/list.h"

// get List length recursively
int ListLength(listADT L1) {
    if (ListIsEmpty(L1))
        return 0;
    else
        return 1 + ListLength(Tail(L1));
}

listElementT SumList(listADT L1) {
    if (ListIsEmpty(L1))
        return 0;
    else
        return Head(L1) + SumList(Tail(L1));
}

listElementT LastElement(listADT L1) {
    if (ListIsEmpty(L1))
        exit(EXIT_FAILURE);
    else if (ListIsEmpty(Tail(L1)))
        return Head(L1);
    else
        return LastElement(Tail(L1));
}

listADT Append(listADT L1, listElementT x) {
    if (ListIsEmpty(L1))
        return Cons(x, EmptyList());
    else
        return Cons(Head(L1), Append(Tail(L1), x));
}
