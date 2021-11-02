#include <stdio.h>
#include <stdlib.h>
#include "stack_fnt.h"
#define FACTOR 0.051

int main()
{
    for (size_t i = 0; i < 10; i++)
    {
        ss_push(rand() * FACTOR);
    }
    ss_push(1);
    ss_push(2);
    ss_push(3);
    ss_push(4);
    ss_print(ss_top);
    ss_free(ss_top);
    return 0;
}