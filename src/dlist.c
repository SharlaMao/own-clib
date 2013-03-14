#include <stdlib.h>
#include <string.h>
#include "dlist.h"

void dlist_init(DList *list, void(*destory)(void* data)){
    list->destory = destory;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return;
}

void dlist_destory(DList *list){
    void* data;
    while(dlist_size(list) > 0){
        if(dlist_remove(list, dlist_tail(list), (void**)&data) == 0
        && list->destory != NULL){
            list->destory(data);
        }
    }
    memset(list, 0, sizeof(DList));
    return;
}

int dlist_ins_next(DList *list, DListElmt *element, void* data){
    DListElmt * new_element;
    // Do not allow a NULL element unless list is empty
    if(element == NULL && dlist_size(list) != 0)
        return -1;
    // Allocate storage for new element
    if((new_element = (DListElmt*)malloc(sizeof(DListElmt))) == NULL)
        return -1;
    new_element->data = data;
    // Insert new element to list
    if(dlist_size(list) == 0){
        list->head = new_element;
        list->tail = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
    } else {
        if(dlist_is_tail(element) == 1){
            list->tail = new_element;
            new_element->prev = element;
            new_element->next = NULL;
            element->next = new_element;
        } else {
            new_element->prev = element;
            new_element->next = element->next;
            new_element->next->prev = new_element;
            new_element->prev->next = new_element;
        }
    }
    list->size++;
    return 0;
}

int dlist_ins_prev(DList *list, DListElmt *element, void* data){
    DListElmt * new_element;
    // Do not allow NULL element unless list is empty
    if(element == NULL && dlist_size(list) != 0)
        return -1;
    // Allocate storage for new element
    if((new_element = (DListElmt*)malloc(sizeof(DListElmt))) == NULL)
        return -1;
    new_element->data = data;
    // Insert the new element into the list
    if(dlist_size(list) == 0){
        list->head = new_element;
        list->tail = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
    } else {
        if(dlist_is_head(element) == 1){
            list->head = new_element;
            new_element->next = element;
            new_element->prev = NULL;
            element->prev = new_element;
        } else {
            new_element->prev = element->prev;
            new_element->next = element;
            new_element->next->prev = new_element;
            new_element->prev->next = new_element;
        }
    }
    list->size++;
    return 0;
}

int dlist_remove(DList *list, DListElmt *element, void** data){
    if(dlist_size(list) <= 0 || element == NULL)
        return -1;
    *data = element->data;
    // If just one element in double list
    if(dlist_is_head(element) == 1 && dlist_is_tail(element) == 1){
        list->head = NULL;
        list->tail = NULL;
    } else
    if(dlist_is_head(element) == 1){
        list->head = element->next;
        element->next->prev = NULL;
    } else
    if(dlist_is_tail(element) == 1){
        list->tail = element->prev;
        element->prev->next = NULL;
    } else {
        element->prev->next = element->next;
        element->next->prev = element->prev;
    }

    list->size--;
    free(element);
    return 0;
}
