#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

// New struct for entry node
typedef struct entry {
    char* name;
    int type;
    struct entry* next;
} entry;

// Hash bucket-based symbol table
typedef struct symboltable {
    entry** buckets;
    int size;
} symboltable;

symboltable* symboltable_create(int size);
void symboltable_insert(symboltable* table, const char* name, int type);
int symboltable_lookup(symboltable* table, const char* name);
void symboltable_dump(symboltable* table);
void symboltable_free(symboltable* table);

#endif /* SYMBOLTABLE_H */
