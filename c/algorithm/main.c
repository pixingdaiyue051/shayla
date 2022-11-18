#include <stdio.h>
#include "seq_stack.h"
#include "linked_stack.h"

void ss_test()
{
    // ss_t *stack = ss_init(10);
    // for (int i = 0; i < 12; i++)
    // {
    //     ss_push(stack, i);
    // }
    // ss_dt pm;
    // ss_peek(stack, &pm);
    // printf("%d\n", pm);
    // ss_print(stack);
    // ss_free(stack);
}

void ls_test()
{
    ls_t *stack = ls_init();
    for (int i = 0; i < 10; i++)
    {
        ls_push(stack, i);
    }
    ls_dt pm;
    ls_peek(stack, &pm);
    printf("%d\n", pm);
    ls_print(stack);
    ls_free(stack);
}

int main(int argv, char *argc[])
{
    ss_test();
    ls_test();
    return 0;
}