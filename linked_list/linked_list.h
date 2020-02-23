//
// Created by dmitry on 12.02.2020.
//

#ifndef ALGORITHMS_C_LINKED_LIST_H
#define ALGORITHMS_C_LINKED_LIST_H

#include "../data_type.h"
#include "stdlib.h"
typedef struct linked_list{
    dtype data;
    struct linked_list* next;
} linked_list;


void linked_list_insert(linked_list** l, dtype data)
{
    linked_list* new = malloc(sizeof(linked_list));
    new->data = data;
    new->next = *l;
    *l = new;
}


#endif //ALGORITHMS_C_LINKED_LIST_H
