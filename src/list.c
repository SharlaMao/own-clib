#include <stdlib.h>
#include <string.h>
#include "list.h"

void list_init(List* list, void(*destory)(void* data)){
    list->destory = destory;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return;
}

void list_destory(List* list){
    void *data;

    while(list_size(list) > 0){
        if(list_rem_next(list, NULL, (void**)&data) == 0
            && list->destory != NULL){
            list->destory(data);
        }
    }
    memset(list, 0, sizeof(List));
    return;
}

int list_ins_next(List* list, ListElmt* element, const void* data){
    ListElmt *new_element;
    // Allocate storage for new element
    if((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL)
        return -1;
    new_element->data = data;
    // Insert to head
    if(element == NULL){
        // List is empty
        if(list_size(list) == 0){
            list->head = new_element;
            list->tail = new_element;
            new_element->next = NULL;
        }
        else{
            new_element->next = list->head;
            list->head = new_element;
        }
    }
    else{
        // Insert to tail
        if(element->next == NULL){
            list->tail = new_element;
        }
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;
    return 0;
}


int list_rem_next(List* list, ListElmt* element, void **data){
    if(list_size(list) <= 0)
        return -1;
    ListElmt *remove_element;
    // Remove head
    if(element == NULL){
        if(list_size(list) == 1){
            list->tail = NULL;
        }
        *data = list->head->data;
        remove_element = list->head;
        list->head = list->head->next;
    }
    else{
        if(list_is_tail(element) == 1)
            return -1;
        if(list_is_tail(element->next) == 1){
            list->tail = element;
        }
        *data = element->next->data;
        remove_element = element->next;
        element->next = element->next->next;
    }

    free(remove_element);
    list->size--;
    return 0;
}




