#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"

const char* typeToStr(int type) {
    switch (type) {
        case 0: return "int";
        case 1: return "float";
        case 2: return "bool";
        case 3: return "string";
        case 4: return "void";
        default: return "unknown";
    }
}

symboltable* symboltable_create(int size) {
    symboltable* table = (symboltable*) malloc(sizeof(symboltable));
    table->buckets = (entry**) calloc(size, sizeof(entry*));
    table->size = size;
    return table;
}

unsigned int hash(const char* str, int size) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % size;
}

void symboltable_insert(symboltable* table, const char* name, int type) {
    unsigned int index = hash(name, table->size);
    entry* new_entry = (entry*) malloc(sizeof(entry));
    new_entry->name = strdup(name);
    new_entry->type = type;
    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
}

int symboltable_lookup(symboltable* table, const char* name) {
    unsigned int index = hash(name, table->size);
    entry* e = table->buckets[index];
    while (e) {
        if (strcmp(e->name, name) == 0) {
            return e->type;
        }
        e = e->next;
    }
    return -1; // Not found
}

void symboltable_dump(symboltable* table) {
    for (int i = 0; i < table->size; ++i) {
        entry* e = table->buckets[i];
        while (e) {
            printf("Symbol: %s, Type: %s\n", e->name, typeToStr(e->type));
            e = e->next;
        }
    }
}

void symboltable_free(symboltable* table) {
    for (int i = 0; i < table->size; ++i) {
        entry* e = table->buckets[i];
        while (e) {
            entry* temp = e;
            e = e->next;
            free(temp->name);
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}
