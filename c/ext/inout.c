/**
 * 输入输出
 */
#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

/**
 * 输出所有的命令行的输入参数
 * argc 输入的参数个数 包括程序命令本身 所以argc>=1
 * argv 输入的参数以二维数组形式存储
 * 		argv 类型是char ** 一个指向指针的指针
 * 		argv 表示存放二维数组地址的地址
 * 		*argv 既是argv地址指向内存的存放内容也是二维数组第一个元素的地址
 * 		**argv 即二维数组第一个元素内容
 **/
void inope1(int argc, char *argv[])
{
    int i, j;
    printf("argument counts:%d\n", argc);
    for (i = 0; i < argc; i++)
    {
        printf("%d.%p%9s\n", i, argv[i], argv[i]);
        // printf("%d.%p%9s\n", i, argv + i, *(argv + i));
        for (j = 0; j < strlen(argv[i]); j++)
        {
            printf("%p,%c\n", &argv[i][j], argv[i][j]);
            // printf("%p,%c\n", argv[i] + j, *(argv[i] + j));
        }
    }
}

void outope()
{
    // 普通输出 向stdout输出 即显示器
    printf("%s %lu\n", "fss", 5324);

    FILE *f = fopen("/data/c_test/test.txt", "w");
    _ht_check(f, "failed to open file");

    // 指定输出到具体的文件设备(linux一切皆文件)
    fprintf(f, "%s %lu\n", "fss", 5324);

_ht_error:
    if (f)
        fclose(f);
}

/**
 * scanf返回值代表匹配的数值个数0则表示没有匹配输入
 **/
void inope()
{
    // 从stdin读取第一个字符
    char c;
    scanf("%c", &c);
    // 清空缓冲区 scanf默认不会清除回车符
    while (getchar() != '\n')
        ;
    printf("c=%c\n", c);

    char ch[5];
    scanf("%s", ch); // 如果输入的字符超出规定就会报错 不是安全方法
    // fgets(ch, 5, stdin); // 读取时设定好最多读取字符数 只要设置的和数组大小一致 该方法就是安全的
    printf("ch=%s\n", ch);


    // 指定从某个输入流中读取第一个字符
    // FILE *f = fopen("/data/c_test/test.txt", "r");
    // _ht_check(f, "failed to open file");
    // fscanf(f, "%c", &c);
// _ht_error:
//     if (f)
//         fclose(f);
}

int main(int argc, const char *argv[])
{
    // inope1(argc, argv);
    // outope();
    inope();


    system("pause");
    return 0;
}