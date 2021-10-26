#include <stdio.h>
#include "num.h"

int main()
{
    int arr[10] = {170, 581, 552, 716, 626, 372, 172, 371, 110};
    print_arr(arr, 10);
    bubble_sort_asc(arr, 10);
    print_arr(arr, 10);
    bubble_sort_desc(arr, 10);
    print_arr(arr, 10);

    return 0;
}