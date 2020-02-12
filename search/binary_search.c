//
// Created by dmitry on 11.02.2020.
//

#include "../data_type.h"

int binary_search(const dtype* arr, int val, int n)
{
    int low = 0;
    int high = n-1;
    while (low<=high)
    {
        int middle = (low+high)/2;
        dtype pivot = arr[middle];
        if(val < pivot)
            high = middle-1;
        else if(val > pivot)
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}

// Alternate version of algorithm - "search or insert)

int bs_contains(const dtype* arr, int val, int n)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int middle = (low+high)/2;
        dtype pivot = arr[middle];
        if(pivot > val)
        high = middle-1;
        else if(pivot < val)
            low = middle+1;
        else return middle;
    }

    return -(low+1);
}

int binary_search_insert(dtype* arr, int val, int n)
{
    int pos = bs_contains(arr, val, n);
    if(pos<0)
        arr[-pos+1] = val;
}