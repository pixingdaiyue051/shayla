#include <stdio.h>
#include "ptr.h"

int g = 10;

int main()
{
    method_pointer();
    // method_arr();

    int a, b;
    a = 21;
    b = 2;

    add(a, b);
    sub(a, b);
    mut(a, b);
    div(a, b);

    return 0;
}
