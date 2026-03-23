#include "hashtable.h"

// Create a new hashtable.
hashtable* hashtable_create(int size) {
    hashtable* ht = (hashtable*)malloc(sizeof(hashtable));
    if (ht == NULL) return NULL; // 確保分配成功

    ht->table = (hashtable_entry**)malloc(sizeof(hashtable_entry*) * size);
    if (ht->table == NULL) {
        free(ht);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }

    ht->size = size;
    return ht;
}

// Hash a string for a particular hash table.
int hashtable_hash(hashtable* hashtable, char* key) {

    unsigned long int hashval;
    int i = 0;

    // Convert our string to an integer
    while (hashval < ULONG_MAX && i < strlen(key)) {
        hashval = hashval << 8;
        hashval += key[i];
        i++;
    }

    return hashval % hashtable->size;
}

// Create a key-value pair.
hashtable_entry* hashtable_newpair(char* key, int value) {
    hashtable_entry* newpair = (hashtable_entry*)malloc(sizeof(hashtable_entry));
    if (newpair == NULL) return NULL; // 檢查記憶體分配是否成功

    newpair->key = strdup(key);
    if (newpair->key == NULL) {
        free(newpair);
        return NULL;
    }

    newpair->value = value;
    newpair->next = NULL;
    return newpair;
}

// Insert a key-value pair into a hash table.
void hashtable_set(hashtable* hashtable, char* key, int value) {
    int bin = 0;
    hashtable_entry* newpair = NULL;
    hashtable_entry* next = NULL;
    hashtable_entry* last = NULL;

    bin = hashtable_hash(hashtable, key);

    next = hashtable->table[bin];

    while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0) {
        last = next;
        next = next->next;
    }

    // There's already a pair.  Let's replace that string.
    if (next != NULL && next->key != NULL && strcmp(key, next->key) == 0) {
        next->value = value;

        // Nope, could't find it.  Time to grow a pair.
    } else {
        newpair = hashtable_newpair(key, value);

        // We're at the start of the linked list in this bin.
        if (next == hashtable->table[bin]) {
            newpair->next = next;
            hashtable->table[bin] = newpair;

            // We're at the end of the linked list in this bin.
        } else if (next == NULL) {
            last->next = newpair;

            // We're in the middle of the list.
        } else {
            newpair->next = next;
            last->next = newpair;
        }
    }
}

// Retrieve a key-value pair from a hash table.
int hashtable_get(hashtable* hashtable, char* key) {
    int bin = 0;
    hashtable_entry* pair;

    bin = hashtable_hash(hashtable, key);

    // Step through the bin, looking for our value.
    pair = hashtable->table[bin];
    while (pair != NULL && pair->key != NULL && strcmp(key, pair->key) > 0) {
        pair = pair->next;
    }

    // Did we actually find anything?
    if (pair == NULL || pair->key == NULL || strcmp(key, pair->key) != 0) {
        return -1;

    } else {
        return pair->value;
    }
}