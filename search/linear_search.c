//
// Created by dmitry on 11.02.2020.
//

#include "../data_type.h"

int linear_search(const dtype* arr,  dtype value, int n)
{
    for (int i = 0; i < n; ++i) {
        if(arr[i]==value)
            return i;
    }
    return -1;
}

