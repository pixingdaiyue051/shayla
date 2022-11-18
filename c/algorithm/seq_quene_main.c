#include <stdio.h>
#include "seq_quene.c"

void in_out(sq_t *quene)
{
    sq_dt n;
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
            if (sq_add(quene, n))
            {
                printf("已入队\n");
                sq_print(quene);
            }
            else
            {
                printf("队列已满\n");
            }
        }
        else
        {
            sq_dt pm;
            if (sq_poll(quene, &pm))
            {
                printf("%d\n", pm);
                sq_print(quene);
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
    sq_t *quene = sq_init(10);

    // in_out(quene);

    for (int i = 0; i < 13; i++)
    {
        sq_add(quene, i);
    }

    sq_dt pm;
    sq_poll(quene, &pm);
    printf("%d\n", pm);
    sq_print(quene);

    sq_free(quene);

    return 0;
}