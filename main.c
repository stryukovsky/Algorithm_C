#include <stdio.h>
#include "data_type.h"
#include "sort/sort.h"
#include "search/search.h"
#include "linked_list/linked_list.h"

int main() {
    dtype arr[] = {1, 2,3, 4, 5, 6, 7, 8};
    if(hash_search(arr, 8, 3))
        printf("HEllo");

    return 0;
}
