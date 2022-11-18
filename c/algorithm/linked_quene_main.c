#include <stdio.h>
#include "linked_quene.c"

void in_out(lq_t *quene)
{
    lq_dt n;
    int tmp;

    while (1)
    {
        tmp = scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        if (tmp == 1)
        {
            if (lq_add(quene, n))
            {
                printf("已入队\n");
                lq_print(quene);
            }
            else
            {
                printf("队列已满\n");
            }
        }
        else
        {
            lq_dt pm;
            if (lq_poll(quene, &pm))
            {
                printf("%d\n", pm);
                lq_print(quene);
            }
            else
            {
                printf("队列已空\n");
            }
            // 清空缓冲区 scanf默认不会清除回车符
            while (getchar() != '\n')
                ;
        }
    }
}

int main(int argv, char *argc[])
{
    lq_t *quene = lq_init();

    // in_out(quene);

    for (int i = 0; i < 13; i++)
    {
        lq_add(quene, i);
    }

    lq_dt pm;
    lq_peek(quene, &pm);
    printf("%d\n", pm);
    lq_print(quene);

    lq_free(quene);

    return 0;
}