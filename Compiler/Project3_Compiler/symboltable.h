#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <stdbool.h>

// 原有 Entry 結構與函數
typedef struct Entry {
    char *name;
    char *type;
    int is_const;
    int is_global;
    int local_index;
    int init_value;
    struct Entry *next;
} Entry;

void add_variable(const char *name, const char *type, int is_global, int is_const, int init_value);
Entry *lookup(const char *name);

int get_local_index(const char *name);
int is_global_variable(const char *name);
int get_initial_value(const char *name);
const char *get_type(const char *name);
int check_assignment_type(const char *lhs, const char *rhs_type);

// 擴充：支援 bucket-based symbol table 與 scope stack

typedef struct entry_node {
    char* name;
    int type; // 0=int, 1=bool
    int local_index;
    int is_global;
    int is_const;
    int const_value;
    struct entry_node* next;
} entry_node;

typedef struct symboltable {
    entry_node** buckets;
    int size;
    int next_local_index;
    struct symboltable* prev; // scope stack
    int local_count;
} symboltable;

void symboltable_insert_global(const char* name, int type);
symboltable* symboltable_create(int size);
void symboltable_insert(symboltable* table, const char* name, int type);
int  symboltable_lookup(symboltable* table, const char* name);
void symboltable_dump(symboltable* table);
void symboltable_free(symboltable* table);
int  symboltable_allocate_local(symboltable* table, const char* name, int type);
bool  symboltable_is_global(symboltable* table, const char* name);
int  symboltable_get_local_index(symboltable* table, const char* name);

// for const + scope
void symboltable_insert_const(symboltable* table, const char* name, int type, int value);
int symboltable_lookup_const(symboltable* table, const char* name, int* value_out);

// scope stack
void symboltable_push();
void symboltable_pop();
symboltable* symboltable_top();

int symboltable_get_type(symboltable* table, const char* name);

#endif