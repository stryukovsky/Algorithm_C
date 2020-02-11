#include <stdio.h>
#include "sort/sort.h"
#include "search/search.h"

int main() {
    printf("Hello, World!\n");
    int array[] = {1, 2, 10, 4};
    quicksort(array, 0, 3);
    for (int i = 0; i < 4; ++i) {
        printf("%d\n", array[i]);
    }
    return 0;
}
