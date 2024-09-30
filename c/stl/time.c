#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 时间函数
 */
void time_test()
{
    // 1、获得当前时间距离1970-01-01 00:00:00的秒数
    time_t t = time(NULL);
    printf("%lu,%u\n", t, t / 60 / 60 / 24 / 365);
    printf("%s\n", ctime(&t)); // 根据时间秒显示时间字符串

    // 2、使用结构体数据承接时间
    time_t *sec = malloc(sizeof(time_t));
    time(sec);
    struct tm *st = localtime(sec);
    printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
           st->tm_sec,           /* 秒，范围从 0 到 59                */
           st->tm_min,           /* 分，范围从 0 到 59                */
           st->tm_hour,          /* 小时，范围从 0 到 23                */
           st->tm_mday,          /* 一月中的第几天，范围从 1 到 31                    */
           st->tm_mon,           /* 月份，范围从 0 到 11                */
           st->tm_year,          /* 自 1900 起的年数                */
           st->tm_wday,          /* 一周中的第几天，范围从 0 到 6                */
           st->tm_yday,          /* 一年中的第几天，范围从 0 到 365                    */
           st->tm_isdst);        /* 夏令时                        */
    printf("%s\n", asctime(st)); // 根据结构体显示时间字符串

    // 3、计时时钟 用于测算程序运行时间
    clock_t ct1 = clock();
    clock_t ct2 = clock();
    printf("cpu timing...(%ds)\n", (ct2 - ct1) / CLOCKS_PER_SEC);

    // 4、格式化输出时间
    // %a	缩写的星期几名称	Sun
    // %A	完整的星期几名称	Sunday
    // %b	缩写的月份名称	Mar
    // %B	完整的月份名称	March
    // %c	日期和时间表示法	Sun Aug 19 02:56:02 2012
    // %d	一月中的第几天（01-31）	19
    // %H	24 小时格式的小时（00-23）	14
    // %I	12 小时格式的小时（01-12）	05
    // %j	一年中的第几天（001-366）	231
    // %m	十进制数表示的月份（01-12）	08
    // %M	分（00-59）	55
    // %p	AM 或 PM 名称	PM
    // %S	秒（00-61）	02
    // %U	一年中的第几周，以第一个星期日作为第一周的第一天（00-53）	33
    // %w	十进制数表示的星期几，星期日表示为 0（0-6）	4
    // %W	一年中的第几周，以第一个星期一作为第一周的第一天（00-53）	34
    // %x	日期表示法	08/19/12
    // %X	时间表示法	02:50:06
    // %y	年份，最后两个数字（00-99）	01
    // %Y	年份	2012
    // %Z	时区的名称或缩写	CDT
    // %%	一个 % 符号	%
    char str[64];
    strftime(str, sizeof(str), "%x %X", st);
    printf("%s\n", str);
    strftime(str, sizeof(str), "%Y-%m-%d %H:%M:%S", st);
    printf("%s\n", str);
}

/**
 * 随机数函数
 */
void rand_test()
{
    // 1、随机获得0-RAND_MAX之间的数
    int r = rand();
    printf("%d\n", r);
    // 2、按照计算机启动分配的时间种子进行正态分布求解一个随机数 该种子数在启动后不会再改变 可以使用srand函数强行修改
    srand(time(NULL));
    int r1 = rand();
    int r2 = rand();
    int r3 = rand();
    int r4 = rand();
    int r5 = rand();
    printf("%d,%d,%d,%d,%d\n", r1, r2, r3, r4, r5);
}

int main()
{
    time_test();
    // rand_test();
}
