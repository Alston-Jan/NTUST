#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symboltable.h"

extern symboltable* symboltable_stack;

bool symboltable_is_global(symboltable* table, const char* name) {
    // 找到 global symboltable（最底層）
    while (table->prev != NULL) {
        table = table->prev;
    }
    // 若在 global table 中能查到此名稱，則為 global
    return symboltable_lookup(table, name) >= 0;
}

void symboltable_insert_global(const char* name, int type) {
    symboltable_insert(symboltable_stack, name, type);
}

symboltable* symboltable_stack = NULL;

static unsigned simple_hash(const char* str, int size) {
    unsigned hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % size;
}

symboltable* symboltable_create(int size) {
    symboltable* table = malloc(sizeof(symboltable));
    table->size = size;
    table->next_local_index = 0;
    table->buckets = calloc(size, sizeof(entry_node*));
    table->prev = NULL;
    return table;
}

void symboltable_insert(symboltable* table, const char* name, int type) {
    unsigned idx = simple_hash(name, table->size);
    entry_node* new_node = malloc(sizeof(entry_node));
    new_node->name = strdup(name);
    new_node->type = type;
    new_node->local_index = -1;
    new_node->is_global = 0;
    new_node->is_const = 0;
    new_node->next = table->buckets[idx];
    table->buckets[idx] = new_node;
}

int symboltable_allocate_local(symboltable* table, const char* name, int type) {
    symboltable_insert(table, name, type);
    unsigned idx = simple_hash(name, table->size);
    entry_node* current = table->buckets[idx];
    if (current) {
        current->local_index = table->next_local_index++;
        return current->local_index;
    }
    return -1;
}

void symboltable_reset_local_index(symboltable* table) {
    table->local_count = 0;
}

int symboltable_get_local_index(symboltable* table, const char* name) {
    while (table) {
        unsigned idx = simple_hash(name, table->size);
        entry_node* current = table->buckets[idx];
        while (current) {
            if (strcmp(current->name, name) == 0)
                return current->local_index;
            current = current->next;
        }
        table = table->prev;
    }
    return -1;
}

int symboltable_lookup(symboltable* table, const char* name) {
    while (table) {
        unsigned idx = simple_hash(name, table->size);
        entry_node* current = table->buckets[idx];
        while (current) {
            if (strcmp(current->name, name) == 0)
                return current->type;
            current = current->next;
        }
        table = table->prev;
    }
    return -1;
}

void symboltable_insert_const(symboltable* table, const char* name, int type, int value) {
    unsigned idx = simple_hash(name, table->size);
    entry_node* new_node = malloc(sizeof(entry_node));
    new_node->name = strdup(name);
    new_node->type = type;
    new_node->local_index = -1;
    new_node->is_const = 1;
    new_node->const_value = value;
    new_node->is_global = 0;
    new_node->next = table->buckets[idx];
    table->buckets[idx] = new_node;
}

int symboltable_lookup_const(symboltable* table, const char* name, int* value_out) {
    while (table) {
        unsigned idx = simple_hash(name, table->size);
        entry_node* current = table->buckets[idx];
        while (current) {
            if (strcmp(current->name, name) == 0 && current->is_const) {
                *value_out = current->const_value;
                return 1;
            }
            current = current->next;
        }
        table = table->prev;
    }
    return 0;
}

int symboltable_get_type(symboltable* table, const char* name) {
    while (table) {
        unsigned idx = simple_hash(name, table->size);
        entry_node* current = table->buckets[idx];
        while (current) {
            if (strcmp(current->name, name) == 0)
                return current->type;
            current = current->next;
        }
        table = table->prev;
    }
    return -1;
}

void symboltable_push() {
    symboltable* new_table = symboltable_create(64);
    new_table->prev = symboltable_stack;
    symboltable_stack = new_table;
}

void symboltable_pop() {
    if (symboltable_stack) {
        symboltable* temp = symboltable_stack;
        symboltable_stack = symboltable_stack->prev;
        symboltable_free(temp);
    }
}

symboltable* symboltable_top() {
    return symboltable_stack;
}

void symboltable_dump(symboltable* table) {
    printf("Symbol Table Dump:\n");
    for (int i = 0; i < table->size; ++i) {
        entry_node* current = table->buckets[i];
        while (current) {
            printf("  [%d] %s : type %d, local_index %d\n", i, current->name, current->type, current->local_index);
            current = current->next;
        }
    }
}

void symboltable_free(symboltable* table) {
    for (int i = 0; i < table->size; ++i) {
        entry_node* current = table->buckets[i];
        while (current) {
            entry_node* temp = current;
            current = current->next;
            free(temp->name);
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}