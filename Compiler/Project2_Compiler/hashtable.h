#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashtable_entry {
    char* key;
    int value;
    struct hashtable_entry* next;
} hashtable_entry;

typedef struct hashtable {
    int size;
    struct hashtable_entry** table;
} hashtable;

// Create a new hashtable.
hashtable* hashtable_create(int size);

// Hash a string for a particular hash table.
int hashtable_hash(hashtable* hashtable, char* key);

// Create a key-value pair.
hashtable_entry* hashtable_newpair(char* key, int value);

// Insert a key-value pair into a hash table.
void hashtable_set(hashtable* hashtable, char* key, int value);

// Retrieve a key-value pair from a hash table.
int hashtable_get(hashtable* hashtable, char* key);

#endif /* HASHTABLE_H */