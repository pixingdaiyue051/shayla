#include <stdio.h>
#include "linkedlist_def.h"
#include "linkedlist_fnt.h"

int main()
{
    for (size_t i = 0; i < 10; i++)
    {
        ll_append(i);
    }

    ll_print(ll_head);
    ll_free(ll_head);
    return 0;
}