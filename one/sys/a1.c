#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("模拟子进程运行...\n");
    printf("接收的参数数量%d\n", argc);
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    int len = atoi(argv[1]);
    for (i = 0; i < len; i++)
    {
        sleep(1);
        printf("子进程 pid:%d,ppid:%d\n", getpid(), getppid());
    }

    return 5;
}