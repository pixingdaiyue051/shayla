#include <stdio.h>

// 指针
void method_pointer()
{
    int i = 10;
    int *j = &i;

    char g = 'c';
    char *z = &g;

    printf("i %p,j %p,g %p,z %p\n", &i, &j, &g, &z);
    printf("i %d,j %d,g %c,z %c\n", i, *j, g, *z);

    char c[] = "123456789";
    char *c1 = "123456789";
    printf("c %p,c1 %p,c1 %p\n", c, c1, &c1);
    printf("c %s,c1 %s,c1 %c\n", c, c1, *c1);

    for (int i = 0; i < 10; i++)
    {
        printf("%c\n", c[i]);
    }
}

// 数组
void method_arr()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%p,%p,%p\n", arr, &arr, &arr[0]);
    printf("%d\n", arr[0]);

    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
        printf("*(arr+%d) = %d\n", i, *(arr + i));
    }

    int arr1[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    printf("%p,%p,%p,%p\n", arr1, &arr1, &arr1[0], &arr1[0][0]);
    printf("%d\n", arr1[0][0]);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int z = 3 * i + j;
            printf("arr1[%d][%d] = %d\n", i, j, arr1[i][j]);
            printf("*(arr1+%d) = %p\n", z, *(arr1 + z));
        }
    }
}

int add(int a, int b)
{
    int z = a + b;
    return z;
}

int sub(int a, int b)
{
    int z = a - b;
    return z;
}

int mut(int a, int b)
{
    int z = a * b;
    return z;
}

float div(int a, int b)
{
    float z = a * 1.0 / b;
    return z;
}