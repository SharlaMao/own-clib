#ifndef LIST_H
#define LIST_H

#ifndef NULL
#define NULL ((void*)0)
#endif

#include <stdlib.h>

typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
    int size;

    int (*match)(const void* key1, const void* key2);
    void (*destory)(void* data);

    ListElmt *head;
    ListElmt *tail;
} List;

// public interface

void list_init(List *list, void (*destory)(void* data));

void list_destory(List *list);

int list_ins_next(List *list, ListElmt *element, const void* data);

int list_rem_next(List *list, ListElmt *element, void** data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

//#define list_is_tail(list, element) ((element) == (list)->tail ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)




#endif
