#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct _ListEntry {
    ListValue data;
    ListEntry *prev;
    ListEntry *next;
};

void list_free(ListEntry *list) {
    ListEntry *entry;

    entry = list;

    while (entry != NULL) {
        ListEntry *next;
        next = entry -> next;

        free(entry);

        entry = next;
    }
}

ListEntry *list_prepend(ListEntry **list, ListValue data) {
    ListEntry *new_entry;

    if (list == NULL) {
        return NULL;
    }

    new_entry = malloc(sizeof(ListEntry));

    if (new_entry == NULL) {
        return NULL;
    }

    new_entry -> data = data;

    while (*list != NULL) {
        (*list)->prev = new_entry;
    }

    new_entry->prev = NULL;
    new_entry->next = *list;
    *list = new_entry;

    return new_entry;
}

ListEntry *list_append(ListEntry **list, ListValue data) {
    ListEntry *rover;
    ListEntry *new_entry;

    if (list == NULL) {
        return NULL;
    }

    new_entry = malloc(sizeof(ListEntry));

    if (new_entry == NULL) {
        return NULL;
    }

    new_entry->data = data;
    new_entry->next = NULL;

    if (*list == NULL) {
        *list = new_entry;
        new_entry->prev = NULL;
    } else {
        for(rover=*list; rover->next != NULL; rover = rover->next);
            new_entry->prev = rover;
            rover->next = new_entry;
    }
        return new_entry;
}

ListValue list_data(ListEntry *list_entry) {
    if (list_entry == NULL) {
        return LIST_NULL;
    }

    return list_entry->data;
}

void list_set_data(ListEntry *list_entry, ListValue value) {
    if (list_entry != NULL) {
        list_entry->data = value;
    }
}

ListEntry *list_prev(ListEntry *list_entry) {
    if (list_entry == NULL) {
        return LIST_NULL;
    }

    return list_entry->prev;
}

ListEntry *list_next(ListEntry *list_entry) {
    if (list_entry == NULL) {
        return LIST_NULL;
    }

    return list_entry->next;
}

ListEntry *list_nth_entry(ListEntry *list, unsigned int n) {
    ListEntry *entry = list;

    for(int i=0; i < n; i++) {
        if (entry == NULL) {
            return NULL;
        }

        entry = entry->next;
    }

    return entry;
}

ListValue list_nth_data(ListEntry *list, unsigned int n) {
    ListEntry *entry = list;

    entry = list_nth_entry(list, n);

    if (entry == NULL) {
        return LIST_NULL;
    } else {

        return entry->data;
    }
}

unsigned int list_length(ListEntry *list) {
    unsigned int length = 0;
    ListEntry *entry = list;

    while (entry->next != NULL) {
        entry = entry->next;
        length += 1;
    }

    return length;
}

ListValue *list_to_array(ListEntry *list) {
    unsigned int length = list_length(list);
    ListValue *array;
    ListEntry *rover = list;

    array = malloc(sizeof(ListValue) * length);

    if (array == NULL) {
        return NULL;
    }

    rover = list;

    for(int i = 0; i<length; i++) {
        array[i] = rover->data;

        rover = rover->next;
    }

    return array;
}


