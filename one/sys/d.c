/**
 * IPC 进程见通信
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define FIFO_PATH "/data/test/fifo1"
#define LOG_PATH "/var/log/fake_fifo_log"
#define SIZE 128

/**
 * 匿名管道
 * 模拟子进程向父进程传输字符
 */
void d_pipe()
{
    int *fd = calloc(2, sizeof(int));
    pipe(fd); // 开启匿名管道 fd[0]读 fd[1]写

    pid_t pid = fork(); // 创建子进程
    if (pid > 0)        // 父进程
    {
        char buf[SIZE];
        bzero(buf, SIZE); // 清空数组 防止申请到的数组有其他数据
        read(fd[0], buf, SIZE);
        printf("父进程读取端:%s\n", buf);

        // char *msg = "不断发生同样肉体和粉色是个人身体45563464576人员划分但是都说了特";
        // size_t size = strlen(msg);
        // write(fd[1], msg, size);
        // printf("父进程写入端:%s\n", msg);
        // int *ex = malloc(sizeof(int));
        // wait(ex);
    }

    if (pid == 0) // 子进程
    {
        char *msg = "概念车繁华街头艺人突然34645645粉红色灯光56456是德国的3太有啥的3634他饿";
        size_t size = strlen(msg);
        write(fd[1], msg, size);
        printf("子进程写入端:%s\n", msg);

        // char buf[SIZE];
        // bzero(buf, SIZE); // 清空数组 防止申请到的数组有其他数据
        // read(fd[0], buf, SIZE);
        // printf("子进程读取端:%s\n", buf);
    }
}

/**
 * 具名管道
 */
void d_fifo(const char *_3mode)
{
    // access检查当前用户是否就有对某文件的权限
    // 此处用于检测文件是否存在
    if (access(FIFO_PATH, F_OK))
    {
        mkfifo(FIFO_PATH, 0644); // 创建具名管道
    }
    char *buf = malloc(SIZE);

    // 写
    if (*_3mode == 'w')
    {
        int fd = open(FIFO_PATH, O_WRONLY); // 打开管道
        while (1)
        {
            bzero(buf, SIZE); // 先清空缓冲区

            fgets(buf, SIZE, stdin);     // 从标准输入流获取输入的字符
            write(fd, buf, strlen(buf)); // 将缓冲区数据写入到fifo
        }

        close(fd);
    }

    // 读
    if (*_3mode == 'r')
    {
        int fd = open(FIFO_PATH, O_RDWR); // 打开管道
        while (1)
        {
            bzero(buf, SIZE); // 先清空缓冲区

            read(fd, buf, SIZE); // 从fifo读取数据到缓冲区
            printf("读取到:%s\n", buf);
        }

        close(fd);
    }
}

/**
 * 模拟syslog
 */
void d_log(const char *_3mode)
{
    if (access(FIFO_PATH, F_OK))
    {
        mkfifo(FIFO_PATH, 0644);
    }
    char *buf = malloc(SIZE);

    // 服务端 读
    if (*_3mode == 's')
    {
        int fifofd = open(FIFO_PATH, O_RDWR);                 // fifo 以读写形式打开 可以防止open方法阻塞 同时保证该管道至少有一个写文件描述符持有者 read方法会阻塞等待
        int logfd = open(LOG_PATH, O_CREAT | O_WRONLY, 0644); // 日志文件

        while (1)
        {
            bzero(buf, SIZE);

            read(fifofd, buf, SIZE);        // 从fifo读取 由于上面以读写方式打开fifo 此处read要么有数据 要么等待
            write(logfd, buf, strlen(buf)); // 写入到log
            printf("读取到:%s\n", buf);
        }
        close(fifofd);
        close(logfd);
    }

    // 客户端 写
    if (*_3mode == 'c')
    {
        int fifofd = open(FIFO_PATH, O_WRONLY); // fifo 以只写的形式打开
        time_t t;
        while (1)
        {
            sleep(1);
            bzero(buf, SIZE);

            time(&t);                                                               // 获取当时时间 ctime将时间格式化成字符串
            snprintf(buf, SIZE, "[%s] [%d] 测试模拟syslog\n", ctime(&t), getpid()); // 将可变参数内容以format形式写入到buf
            write(fifofd, buf, strlen(buf));                                        // 写入fifo
            printf("写入:%s\n", buf);
        }
        close(fifofd);
    }
}

int main(int argc, char const *argv[])
{
    // d_pipe();
    // d_fifo(argv[1]);
    d_log(argv[1]);
    return 0;
}