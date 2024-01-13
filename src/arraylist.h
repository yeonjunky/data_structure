#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef void *ArrayListValue;

typedef struct _ArrayList ArrayList;

struct _ArrayList {
    ArrayListValue *data;
    unsigned int length;
    unsigned int _alloced;
};

typedef int (*ArrauListEqualFunc)(ArrayListValue value1, ArrayListValue value2);

typedef int (*ArrayListCompareFunc)(ArrayListValue value1, ArrayListValue value2);


#endif