#include <stdio.h>
#include "linkedlist_def.h"
#include "linkedlist_fnt.h"

int main()
{
    for (int i = 0; i < 10; i++)
    {
        ll_append(i);
    }
    
    ll_print(ll_head);
    return 0;
}