//
// Created by dmitry on 09.02.2020.
//

typedef int dtype;

/*
 * Partition of Lomuto is used as default. (increasing/decreasing of indices where array is already sorted.
 * Low is increasing while value under this index is less than pivot, the same way high is increasing.
 */

int lomuto_partition(dtype* arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for (int j = low; j <= high; j++)
    {
        if(arr[j] <= pivot)
        {
            dtype tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    return 0;
}

int hoare_partition(dtype* arr, int low, int high)
{
    int middle = (low+high)/2;
    dtype pivot = arr[middle];
    int i = low-1;
    int j = high+1;
    while (1)
    {
        do  i++; while(arr[i]<pivot);
        do j--; while(arr[j]>pivot);

        if(i >=j)
            return j;

        dtype tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void quicksort(dtype* arr, int low, int high)
{
    if (low < high)
    {
        int p = hoare_partition(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);
    }


}

