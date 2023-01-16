#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

static ht_item* ht_new_item(const char* key, const char* value) {
    ht_item* new_item = malloc(sizeof(ht_item));
    new_item -> key = strdup(key);
    new_item -> value = strdup(value);

    return new_item;
}

static void ht_delete_item(ht_item* i) {
    free(i -> key);
    free(i -> value);
    free(i);
}


ht_hash_table* ht_new() {
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));

    ht -> size = 53;
    ht -> count = 0;
    ht -> items = calloc((size_t) ht->size, sizeof(ht_item*));
}

void ht_delete_table(ht_hash_table* t) {
    for(int i=0;i<t->size;i++) {
        ht_item* item = t->items[i];
        if (item != NULL) {
            ht_delete_item(item);
        }

    free(t->items);
    free(t);
    }
}

static int ht_hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);

    for(int i=0;i<len_s;i++) {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }

    return (int)hash
}

static int ht_get_hash(
    const char* s, const int num_buckets, const int attempt
) {
    const int hash_a = ht_hash(s, 97, num_buckets);
    const int hash_b = hy_hash(s, 89, num_buckets);

    return (hash_a + (attempt * (hash_b +1))) % num_buckets;
}

void ht_insert(ht_hash_table* ht, const char* key, const char* value){
    ht_item* item = ht_new_item(key, value);
    int index = ht_get_index(key, ht->size, 0);
    ht_item* curr_item = ht->items[index];
    int i = 1;
    while(item != NULL){
        index = ht_get_index(key, ht->size, i);
        curr_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while(item != NULL){
        if(strcmp(item->key, key) == 0){
            return item->value;
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    return NULL;
}
