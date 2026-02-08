// version 2.0
// use linked list to implement

#warning This implementation is from the lecture slides and may cause memory leakage problems

#include <stdlib.h>

#include "../include/list.h"

struct listCDT {
    listElementT h;
    listADT t;
};

listADT EmptyList(void) {
    return NULL;
}

// returns a new list
listADT Cons(listElementT h1, listADT t1) {
    listADT list = malloc(sizeof(*list));

    list->h = h1;
    list->t = t1;

    return list;
}

listElementT Head(listADT list) {
    if (ListIsEmpty(list)) {
        exit(EXIT_FAILURE);
    }

    return list->h;
}

// return a new list containing the "tails"
listADT Tail(listADT list) {
    if (ListIsEmpty(list)) {
        exit(EXIT_FAILURE);
    }

    return list->t;
}

int ListIsEmpty(listADT list) {
    return list == NULL;
}

// get List length recursively
int ListLength(listADT list) {
    if (ListIsEmpty(list))
        return 0;
    else
        return 1 + ListLength(Tail(list));
}

listElementT SumList(listADT list) {
    if (ListIsEmpty(list))
        return 0;
    else
        return Head(list) + SumList(Tail(list));
}

listElementT LastElement(listADT list) {
    if (ListIsEmpty(list))
        exit(EXIT_FAILURE);
    else if (ListIsEmpty(Tail(list)))
        return Head(list);
    else
        return LastElement(Tail(list));
}

listADT Append(listADT list, listElementT x) {
    if (ListIsEmpty(list))
        return Cons(x, EmptyList());
    else
        return Cons(Head(list), Append(Tail(list), x));
}

listADT Reverse(listADT list) {
    if (ListIsEmpty(list))
        return EmptyList();
    else
        return Append(Reverse(Tail(list)), Head(list));
}
