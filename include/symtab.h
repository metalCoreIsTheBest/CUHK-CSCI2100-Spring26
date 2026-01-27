#pragma once

// this implementation of symbol table may result in memory leakage problems

typedef struct symtabCDT *symtabADT;


symtabADT EmptySymbolTable(void);
typedef void (*symtabFnT)(char*, void*);

void Enter(symtabADT table, char *key, void *value);

void *Lookup(symtabADT table, char *key);

void forEachEntryDo(symtabFnT, symtabADT);

