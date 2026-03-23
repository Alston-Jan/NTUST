#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"

symboltable* symboltable_create(int size) {
    if (size < 1) return NULL;

    symboltable* st = (symboltable*)malloc(sizeof(symboltable));
    if (st == NULL) return NULL;

    st->symbols = (char**)malloc(sizeof(char*) * size);
    if (st->symbols == NULL) {
        free(st);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        st->symbols[i] = NULL;
    }

    st->hashtable = hashtable_create(size);
    if (st->hashtable == NULL) {
        free(st->symbols);
        free(st);
        return NULL;
    }

    st->length = 0;
    st->size = size;

    return st;
}

int symboltable_lookup(symboltable* symboltable, char* s) {
    return hashtable_get(symboltable->hashtable, s);
}

int symboltable_insert(symboltable* symboltable, char* s) {
    if (hashtable_get(symboltable->hashtable, s) != -1) {
        return -1; // 已存在
    }
    if (symboltable->length >= symboltable->size) {
        return -100; // 符號表已滿
    }

    char* key = strdup(s);
    if (key == NULL) return -2; // 記憶體分配失敗

    int value = symboltable->length;
    symboltable->symbols[value] = key;
    hashtable_set(symboltable->hashtable, key, value);

    ++symboltable->length;
    return value; // 加入後回傳索引
}

int symboltable_dump(symboltable* symboltable) {
    for (int i = 0; i < symboltable->length; i++) {
        printf("%s\n", symboltable->symbols[i]);
    }
    return symboltable->length;
}
