#include <stdio.h>
#include "bst.c"

int main()
{
    printf("根节点:");
    int n;
    scanf("%d", &n);

    bst_t *root = bst_init(n);
    bst_t *tmp = root;

    printf("插入节点:");
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }

        bst_t *node = bst_init(n);
        bst_insert(tmp, node);
    }

    printf("删除节点:");
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        bst_remove(tmp, n);
    }
    return 0;
}