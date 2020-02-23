//
// Created by dmitry on 23.02.2020.
//

#include "data_type.h"

int hash1(dtype val)
{
    return (val % 31) * (val*val - 2) + 0xDADBEEF*val % 0xBEEF;
}

int hash2(dtype val)
{
    return (val * val * val ) % 11 + 13*val - (7*(val*129) % 19);
}


void filter_create(char* array, int n)
{

    for (int i = 0; i < n; ++i) {
        array[i] = 0;
    }

}

void filter_add(char* array, int n, dtype value)
{
    array[hash1(value)%n] = 1;
    array[hash2(value)%n] = 1;
}

bool filter_contains(char* array, dtype value)
{
    int first = hash1(value);
    int second = hash2(value);
    if(array[first] + array[second] == 2)
        return true;
    return false;
}