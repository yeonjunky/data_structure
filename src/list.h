#ifndef LIST_H
#define LIST_H


typedef struct _ListEntry ListEntry;

typedef struct _ListIterator ListIterator;

typedef void *ListValue;

struct _ListIterator {
    ListEntry **prev_next;
    ListEntry *current;
};

#define LIST_NULL ((void *) 0)

typedef int (*ListCompareFunc)(ListValue value1, ListValue value2);

typedef int (*ListEqualFunc)(ListValue value1, ListValue value2);

void list_free(ListEntry *list);

ListEntry *list_prepend(ListEntry **list, ListValue data);

ListEntry *list_append(ListEntry **list, ListValue data);

ListEntry *list_prev(ListEntry *list_entry);

ListEntry *list_next(ListEntry *list_entry);

ListValue list_data(ListEntry *list_entry);

void list_set_data(ListEntry *list_entry, ListValue value);

ListEntry *list_nth_entry(ListEntry *list, unsigned int n);

ListValue list_nth_data(ListEntry *list, unsigned int n);

unsigned int list_length(ListEntry *list);

ListValue *list_to_array(ListEntry *list);

int list_remove_entry(ListEntry **list, ListEntry *entry);

unsigned int list_remove_data(ListEntry **list, ListEqualFunc callback, ListValue data);

void list_sort(ListEntry **list, ListCompareFunc compare_func);

ListEntry *list_find_data(ListEntry *list, ListEqualFunc callback, ListValue data);

void list_iterate(ListEntry **list, ListIterator *iter);

int list_iter_has_more(ListIterator *iterator);

ListValue list_iter_next(ListIterator *iterator);

void list_iter_remove(ListIterator *iterator);

#endif