#include <stdio.h>
#include "circle_list.c"

int main()
{
    cl_t *pos = cl_init(1001);
    
    cl_t *pos1 = pos;
    for (int i = 0; i < 10; i++)
    {
        pos1 = cl_append(pos1, i);
    }

    cl_next_print(pos);
    cl_pre_print(pos);
    
    cl_free(pos);

    return 0;
}