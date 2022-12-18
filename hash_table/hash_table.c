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


ht_hash_table* ht_new_table() {
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));

    ht -> size = 53;
    ht -> count = 0;
    ht -> items = calloc((size_t) ht -> size, sizeof(ht_item));
}

void ht_delete_table(ht_table* t) {
    for(int i=0;i<t -> size;i++) {
        ht_item* i = t -> items[i];
        if (i -> key != NULL) {
            ht_delete_item(i);
        }

    free(t -> items)
    free(t)
    }
}

