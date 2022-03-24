/**
 *  系统IO linux kernel IO
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

/**
 * 复制文件
 * */
int mycopy(char const *fa, char const *fb)
{
    int fdr = open(fa, O_RDONLY | O_BINARY);
    int fdw = open(fb, O_CREAT | O_WRONLY | O_APPEND | O_BINARY, 0644);

    if (fdr == -1)
    {
        printf("open failed[%s],%s", fa, strerror(errno));
        exit(1);
    }
    if (fdw == -1)
    {
        printf("open failed[%s],%s", fb, strerror(errno));
        exit(1);
    }

    char buf[BUFSIZ];

    int nread, nwrite;
    while (1)
    {
        nread = read(fdr, buf, BUFSIZ);
        if (nread == -1)
        {
            printf("read failed %s", strerror(errno));
            exit(1);
        }
        if (nread == 0)
        {
            break;
        }

        write(fdw, buf, nread);

        // char *tmp = buf;
        // while (nread > 0)
        // {
        //     nwrite = write(fdw, tmp, nread);
        //     tmp += nwrite;
        //     nread -= nwrite;
        // }
    }
    close(fdr);
    close(fdw);
    return 0;
}

/**
 * 文件属性
 * */
int stat1(char const *fa)
{
    struct stat buf;
    stat(fa, &buf);

    if (S_ISREG(buf.st_mode))
    {
        printf("%d,%d\n", buf.st_dev, buf.st_dev);
    }
    if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
    {
        printf("%d,%d\n", buf.st_rdev, buf.st_rdev);
    }
}

/**
 * 读取文件夹
 * */
int dir1(const char *dd)
{
    DIR *d = opendir(dd);
    struct dirent *sd;

    while (1)
    {
        sd = readdir(d);
        if (sd == NULL)
        {
            break;
        }
        printf("%ld,%s\n", sd->d_ino, sd->d_name);
    }

    closedir(d);
    return 0;
}

int main(int argc, char const *argv[])
{
    // mycopy(argv[1], argv[2]);

    // stat1(argv[1]);

    dir1(argv[1]);
    return 0;
}