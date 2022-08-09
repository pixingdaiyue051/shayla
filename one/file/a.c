/**
 *  系统IO linux kernel IO
 * 对文件的操作基于 文件描述符
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

// #include <linux/input.h>

#define BUFFER_SIZE 1024

/**
 * 复制文件
 * */
int mycopy(char const *fa, char const *fb)
{
    int fdr = open(fa, O_RDONLY | O_BINARY);                            // 源文件 只读 二进制
    int fdw = open(fb, O_CREAT | O_WRONLY | O_APPEND | O_BINARY, 0644); // 目标文件 可写 追加 新建 二进制

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

    char buf[BUFFER_SIZE];

    int nread, nwrite;
    while (1)
    {
        nread = read(fdr, buf, BUFFER_SIZE); // nread代表从源文件中读取到的字节数
        if (nread == -1)                     // 读文件错误
        {
            printf("read failed %s", strerror(errno));
            exit(1);
        }
        if (nread == 0) // 文件已读取完毕
        {
            break;
        }

        // write(fdw, buf, nread);

        // 一般文件较小时 以下方法等同于 write(fdw, buf, nread);
        char *tmp = buf; // 初始定位需要开始写的文件位置
        while (nread > 0)
        {
            nwrite = write(fdw, tmp, nread); // nwrite代表已写入的字节数
            nread -= nwrite;                 // 计算剩余需要写入的字节数
            tmp += nwrite;                   // 加已写入的文件偏移量
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}

/**
 * 文件属性
 * */
int mystat(char const *fa)
{
    struct stat buf;
    stat(fa, &buf); // 根据文件名获取文件属性 文件路径必须正确且文件必须存在

    printf("索引号%d\n",buf.st_ino);
    printf("类型%d\n",buf.st_mode);
    printf("引用计数%d\n",buf.st_nlink);
    printf("文件所有者%d\n",buf.st_uid);
    printf("文件所有者群组%d\n",buf.st_gid);
    printf("文件大小%d\n",buf.st_size);
    printf("最新访问时间%d\n",buf.st_atime);
    printf("最近修改时间%d\n",buf.st_mtime);
    printf("创建时间%d\n",buf.st_ctime);
    printf("设备号%d\n",buf.st_dev);
    printf("特殊设备号%d\n",buf.st_rdev);
    // printf("主设备号%d,次设备号%d", majar(buf.st_dev), minor(buf.st_dev));
    // printf("主设备号%d,次设备号%d", majar(buf.st_rdev), minor(buf.st_rdev));

    if (S_ISREG(buf.st_mode))
    {
        printf("普通文件%d,%d\n", buf.st_rdev, buf.st_dev);
    }
    if (S_ISDIR(buf.st_mode))
    {
        printf("目录%d,%d\n", buf.st_rdev, buf.st_dev);
    }
    if (S_ISCHR(buf.st_mode))
    {
        printf("char文件%d,%d\n", buf.st_rdev, buf.st_dev);
    }
    if (S_ISBLK(buf.st_mode))
    {
        printf("block文件%d,%d\n", buf.st_rdev, buf.st_dev);
    }
    if (S_ISFIFO(buf.st_mode))
    {
        printf("pipe文件%d,%d\n", buf.st_rdev, buf.st_dev);
    }
    // if (S_ISLNK(buf.st_mode))
    // {
    //     printf("link文件%d,%d\n", buf.st_rdev, buf.st_dev);
    // }
    // if (S_ISSOCK(buf.st_mode))
    // {
    //     printf("socket文件%d,%d\n", buf.st_rdev, buf.st_dev);
    // }
}

/**
 * 读取文件夹
 * */
int mydir(const char *dd)
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

    // mystat(argv[1]);

    mydir(argv[1]);
    return 0;
}