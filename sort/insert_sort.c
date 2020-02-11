//
// Created by dmitry on 09.02.2020.
//
typedef int dtype;

void insert(dtype* arr, int pos, dtype value)
{
    int i = pos - 1;
    while(i >= 0 && arr[i] > value)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = value;
}

void insert_sort(dtype* array, int length)
{
    for(int i = 1; i < length; i++)
    {
        insert(array, i, array[i]);
    }
}