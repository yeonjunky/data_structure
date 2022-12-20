#include "hash_table.h"

int main() {
    ht_hash_table* table = ht_new();

    ht_delete_table(table);
    return 0;
}
