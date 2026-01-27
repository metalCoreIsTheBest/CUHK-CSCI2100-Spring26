// it is actually a naive hash table

#include "../include/symtab.h"
#include <stdlib.h>
#include <string.h>

#warning This implementation is from the lecture slides and may cause memory leakage problems

int Hash(char *s, int nBuckets) {
    unsigned long hashcode;
    hashcode = 0;
    for (int i = 0; s[i] != '\0'; i++)
        hashcode = (hashcode << 5) + s[i];
    return (int)(hashcode % nBuckets);
}

// for seperate chaining
typedef struct cellT {
    char *key;
    void *value;
    struct cellT *next;
} cellT;

struct symtabCDT {
    cellT *buckets[101];
};

static cellT *FindCell(cellT *cp, char *key) {
    while ((cp != NULL ? strcmp(cp->key, key) != 0 : 0))
        cp = cp->next;
    return cp;
}

symtabADT EmptySymbolTable(void) {
    symtabADT table;
    int i;
    table = malloc(sizeof(*table));
    for (i = 0; i < 101; i++)
        table->buckets[i] = NULL;
    return table;
}

void Enter(symtabADT table, char *key, void *value) {
    int hashCode;
    cellT *cp;
    hashCode = Hash(key, 101);
    cp = FindCell(table->buckets[hashCode], key);
    if (cp == NULL) { /* New Entry */
        cp = malloc(sizeof(*cp));
        cp->key = malloc(sizeof(char) * (strlen(key) + 1));
        strcpy(cp->key, key);
        cp->next = table->buckets[hashCode];
        table->buckets[hashCode] = cp;
    };
    cp->value = value;
}

void *Lookup(symtabADT table, char *key) {
    int hashCode;
    cellT *cp;
    hashCode = Hash(key, 101);
    cp = FindCell(table->buckets[hashCode], key);
    if (cp == NULL)
        return NULL;
    return cp->value;
}

void forEachEntryDo(symtabFnT f, symtabADT table) {
    cellT *cp;
    for (int i = 0; i < 101; i++)
        for (cp = table->buckets[i]; cp != NULL; cp = cp->next)
            f(cp->key, cp->value);
}
