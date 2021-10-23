#include <stdio.h>
#include "num.h"

int main()
{
    flower_num();
    num9();
    triangle();
    prime_number();
    
	int arr[] = {42, 63, 124, 765, 246, 754, 26456, 2563};
	print_arr(arr, 8);
	bubble_sort_asc(arr, 8);
	print_arr(arr, 8);
	bubble_sort_desc(arr, 8);
	print_arr(arr, 8);

    return 0;
}