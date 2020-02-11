//
// Created by dmitry on 09.02.2020.
//

typedef int dtype;

void heapify(dtype* arr, int idx, int n)
{
    int largest = idx;
    int left = 2 * idx +1;
    int right = 2 * idx+2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != idx)
    {
        dtype tmp = arr[idx];
        arr[idx] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, largest, n);
    }
}

void buildHeap(dtype* arr, int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);
}

void pyramid_sort(dtype* arr, int n)
{
    buildHeap(arr, n);
    for(int i = n-1; i >= 1; i--)
    {
        dtype tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, 0, i);
    }
}
