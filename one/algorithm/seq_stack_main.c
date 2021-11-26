#include <stdio.h>
#include "seq_stack.c"

void dec_2_oct(ss_t *stack)
{
    ss_dt d;
    scanf("%d", &d);

    while (d > 0)
    {
        if (!ss_push(stack, d % 8))
        {
            exit(1);
        }
        d /= 8;
    }

    printf("0");
    ss_dt pm;
    while (1)
    {
        if (!ss_pop(stack, &pm))
        {
            break;
        }
        printf("%d", pm);
    }
    printf("\n");
}

int main(int argv, char *argc[])
{
    ss_t *stack = ss_init(10);

    // dec_2_oct(stack);

    for (int i = 0; i < 12; i++)
    {
        ss_push(stack, i);
    }
    ss_dt pm;
    ss_pop(stack, &pm);
    printf("%d\n", pm);
    ss_print(stack);

    ss_free(stack);
    
    return 0;
}