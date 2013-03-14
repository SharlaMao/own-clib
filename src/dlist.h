#ifndef DLIST_H
#define DLIST_H

#ifndef NULL
#define NULL ((void*)0)
#endif

#include <stdlib.h>

typedef struct DListElmt_ {
    void *data;
    struct DListElmt_ * prev;
    struct DListElmt_ * next;
} DListElmt;

typedef struct DList_ {
    int size;
    DListElmt * head;
    DListElmt * tail;

    void (*destory)(void* data);
    int (*match)(const void* key1, const void* key2);
} DList;

void dlist_init(DList *list, void(*destory)(void* data));

void dlist_destory(DList *list);

int dlist_ins_next(DList *list, DListElmt *element, void* data);

int dlist_ins_prev(DList *list, DListElmt *element, void* data);

int dlist_remove(DList *list, DListElmt *element, void** data);

#define dlist_size(list) ((list)->size)

#define dlist_head(list) ((list)->head)

#define dlist_tail(list) ((list)->tail)

#define dlist_size(list) ((list)->size)

#define dlist_is_head(element) ((element)->prev == NULL)

#define dlist_is_tail(element) ((element)->next == NULL)

#define dlist_data(element) ((element)->data)

#define dlist_prev(element) ((element)->prev)

#define dlist_next(element) ((element)->next)


#endif
