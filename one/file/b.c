/**
 *  标准IO c对系统IO的封装
 * */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ELE_N 5
#define ELE_BUF_SIZE 20

int mycopy(char const * fa, char const * fb)
{
    FILE *fdr = fopen(fa, "rb");
    FILE *fdw = fopen(fb, "ab");

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

    char *buf = calloc(ELE_N, ELE_BUF_SIZE);

    int nread, nwrite;
    long start, end;
    while (1)
    {
        start = ftell(fdr);
        nread = fread(buf, ELE_BUF_SIZE, ELE_N, fdr);
        if (nread == -1)
        {
            printf("read failed %s", strerror(errno));
            exit(1);
        }
        if (nread < ELE_N)
        {
            end = ftell(fdr);
            fwrite(buf, end - start, 1, fdw);
            // fputs("\n------------------------------\n", fdw);
            break;
        }

        fwrite(buf, ELE_BUF_SIZE, ELE_N, fdw);

        // char *tmp = buf;
        // while (nread > 0)
        // {
        //     nwrite = fwrite(tmp, ELE_BUF_SIZE, ELE_N, fdw);
        //     tmp += nwrite * ELE_BUF_SIZE;
        //     nread -= nwrite;
        // }
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