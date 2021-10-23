#include <stdio.h>

void std1()
{
    printf("输入a:");
    // fprintf(stdout, "输入a:");

    int a,b;
    scanf("%d", &a);

    printf("输入b:");
    // fprintf(stdout, "输入b:");

    scanf("%d", &b);

    printf("a+b=%d\n", a+b);
}

int main()
{
    std1();
    return 0;
}
