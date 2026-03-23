#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "hashtable.h"

typedef struct symboltable {
    char** symbols;
    hashtable* hashtable;
    int length;
    int size;
} symboltable;

// Create a new symbol table
symboltable* symboltable_create(int size);
// Returns index of the entry for string s, or -1 if s is not found
int symboltable_lookup(symboltable* symboltable, char* s);
// Inserts s into a new entry of the symbol table and returns index of the entry
int symboltable_insert(symboltable* symboltable, char* s);
// Dumps all entries of the symbol table. returns length of the table
int symboltable_dump(symboltable* symboltable);

#endif /* SYMBOLTABLE_H */