//
// Created by dmitry on 12.02.2020.
//

#include <stdbool.h>
#include "../data_type.h"
#include "../linked_list/linked_list.h"
#include "math.h"

int hash(dtype x, int n)
{
    return abs(1434232913 * x % n);
}

void create_table(const dtype* arr, int n, linked_list** table)
{
    for (int i = 0; i < n; ++i) {
        dtype value = arr[i];
        int h = hash(value, n);
        if(table[h] == NULL)
        {
            linked_list* p;
            p = malloc(sizeof(linked_list));
            p->data = value;
            table[h] = p;
        } else
            linked_list_insert(&table[h], value);
    }
}

void show_table(linked_list** table, int n)
{
    for (int i = 0; i < n; ++i) {
        linked_list* p = table[i];
        printf("%d: ", i);
        if(p == NULL)
        {
            printf("Empty slot\n");
            continue;
        }
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

bool hash_search(dtype* arr, int n, dtype val)
{
    linked_list* table[n];
    for (int i = 0; i < n; ++i) {
        table[i] = NULL;
    }
    create_table(arr, n, table);
    show_table(table, n);
    int h = hash(val, n);
    if(table[h] != NULL)
    {
        linked_list* p = table[h];
        while (p != NULL)
        {
            if(p->data == val)
                return true;
            p = p->next;
        }
    }
    return false;
}