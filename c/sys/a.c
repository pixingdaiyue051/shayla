/**
 *进程的创建与退出 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int a = 1;
/**
 * fork函数从当前进程中复制一份子进程
 * 父进程和子进程的数据资源都独立
 * 并执行fork后的程序
 */
void a_fork()
{
    int b = 2;
    int *c = malloc(sizeof(int));
    *c = 3;
    printf("[%d]\n", __LINE__);

    int pid = fork();

    if (pid > 0) // 父进程
    {
        sleep(2);
        printf("父进程%d,%d,%d\n", a, b, *c);
    }
    if (pid == 0) // 子进程
    {
        a = 100;
        b = 200;
        *c = 300;
        printf("子进程%d,%d,%d\n", a, b, *c);
    }
    printf("[%d]\n", __LINE__);
}

void f1()
{
    printf("[%s] is calling...\n", __FUNCTION__);
}

void f2()
{
    printf("[%s] is calling...\n", __FUNCTION__);
}

/**
 * exit()退出时还会调用注册函数并清空缓冲区
 * _exit()直接退出
 */
void a_exit()
{
    atexit(f1); // 注册需要后续处理的函数 栈结构后加入的先执行
    atexit(f2);

    printf("abcd"); // 此时abcd会输出缓冲区 如果检测到\n或者调用了exit()就会帮缓冲区的数据全部刷新到输出设备或输出文件中
    sleep(1);
    printf("rdddda");
    sleep(1);
    _exit(1); // exit之后的程序都不会执行
    printf("\n");
}

/**
 * exec是一组函数 用于替换程序执行代码
 */
void a_exec()
{
    int r = fork(); // 复制一个子进程(和父进程并行运行)
    if (r > 0)      // 父进程
    {
        sleep(1); // 让父进程休眠一会儿 保证子进程先运行结束
        printf("父进程 pid:%d,ppid:%d\n", getpid(), getppid());

        int *cstatus = malloc(sizeof(int));
        wait(cstatus); // 等待该进程开启所有子进程中任意一个结束 cstatus是子进程结束的状态 其中最低一位存放这 结束码(0-255)
        printf("子进程结束 结束码[%d]\n", WEXITSTATUS(*cstatus));
    }
    if (r == 0) // 子进程
    {
        printf("子进程 pid:%d,ppid:%d\n", getpid(), getppid()); // 如果父进程先于子进程结束 此时子进程的ppid将是系统内一个专门接收孤儿进程的进程

        // execl("./a1.out", NULL);                    // 替换掉子进程需要执行的代码 在这之后的代码都无效 正常运行一个脚本都会传递的两个参数 其中NULL是用于收尾的一定要传

        char *arg[] = {"5", "5k7", "abg", NULL};      // 这里实际传递的参数数量为3
        execv("./a1.out", arg);

        // execlp("ls", "ls", "-al", NULL); // 可以运行系统命令 execlp会已系统路径为前缀自动查找程序位置
        // execl("/usr/bin/ls", "ls", "-al", NULL);
        printf("aaaaa\n");
    }
}

int main(int argc, char const *argv[])
{
    // a_fork();
    // a_exit();
    a_exec();
    return 0;
}