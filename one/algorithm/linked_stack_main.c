#include <stdio.h>
#include "linked_stack.c"

void dec_2_oct(ls_t *stack)
{
    ls_dt d;
    scanf("%d", &d);

    while (d > 0)
    {
        if (!ls_push(stack, d % 8))
        {
            exit(1);
        }
        d /= 8;
    }

    printf("0");
    ls_dt pm;
    while (1)
    {
        if (!ls_pop(stack, &pm))
        {
            break;
        }
        printf("%d", pm);
    }
    printf("\n");
}

int main(int argv, char *argc[])
{
    ls_t *stack = ls_init();

    // dec_2_oct(stack);

    for (int i = 0; i < 10; i++)
    {
        ls_push(stack, i);
    }
    ls_dt pm;
    ls_peek(stack, &pm);
    printf("%d\n", pm);
    ls_print(stack);

    ls_free(stack);
    
    return 0;
}