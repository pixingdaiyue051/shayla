/**
 *  标准IO c对系统IO的封装
 * 对文件的操作基于 文件指针
 * */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ELE_N 32
#define ELE_BUF_SIZE 1024

/**
* 复制文件
**/
int mycopy(char const *fa, char const *fb)
{
    FILE *fdr = fopen(fa, "rb"); // r只读 b二进制
    FILE *fdw = fopen(fb, "ab"); // a只写追加 b二进制

    if (fdr == NULL)
    {
        printf("open failed[%s],%s", fa, strerror(errno));
        exit(1);
    }
    if (fdw == NULL)
    {
        printf("open failed[%s],%s", fb, strerror(errno));
        exit(1);
    }

    char *buf = calloc(ELE_N, ELE_BUF_SIZE); // 申请字节块缓冲区

    int nread, nwrite;
    long start;
    while (1)
    {
        start = ftell(fdr);                           // 读之前先记录当前读取位置
        nread = fread(buf, ELE_BUF_SIZE, ELE_N, fdr); // nread代表读取的字节块数 nread<=ELE_N
        if (nread == -1)
        {
            printf("read failed %s", strerror(errno));
            exit(1);
        }
        if (nread < ELE_N) // 此时读取到了文件尾 需要处理最后一个字节块
        {
            long end = ftell(fdr); // 最后一个字节块 再标记此时文件位置 就可以得到最后一个数据块字节数
            fwrite(buf, end - start, 1, fdw);
            printf("最后读取的数据块大小%d", end - start);
            break;
        }

        // 完整的读取到了数据块
        // fwrite(buf, ELE_BUF_SIZE, ELE_N, fdw);

        char *tmp = buf;
        while (nread > 0)
        {
            nwrite = fwrite(tmp, ELE_BUF_SIZE, nread, fdw);
            nread -= nwrite;
            tmp += nwrite * ELE_BUF_SIZE;
        }
    }
    fclose(fdr);
    fclose(fdw);
    return 0;
}

int main(int argc, char const *argv[])
{
    mycopy(argv[1], argv[2]);

    return 0;
}