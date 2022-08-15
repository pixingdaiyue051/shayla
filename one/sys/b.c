/**
 * 守护进程
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>

#define LOG_TAG "sys_idx"

/**
 * 模拟进程不退出
 */
void b_running()
{
    while (1)
    {
        sleep(3);
        printf("当前运行进程pid:%d,ppid:%d\n", getpid(), getppid());
    }
}

void b_task()
{
    // pause();

    openlog(LOG_TAG, LOG_CONS | LOG_PID, LOG_DAEMON);
    while(1)
    {
        syslog(LOG_DEBUG, "测试syslog");
        sleep(1);
    }
    closelog();
}

void b_daemon()
{
    signal(SIGHUP, SIG_IGN); // 忽略系统挂断信号

    int a = fork(); // 创建新的进程p2
    if (a > 0)
        exit(0); // 父进程p1正常退出

    setsid();   // p2开启新的session
    a = fork(); // 开启新的进程p3降低权限
    if (a > 0)
        exit(0); // p2正常退出

    setpgrp();                          // p3开启新的进程组
    int max_fd = sysconf(_SC_OPEN_MAX); // 查找并关闭已打开的文件描述符 回收资源
    int i;
    for (i = 0; i < max_fd; i++)
        close(i);

    umask(0); // 关闭文件掩码权限 使p3获得当前工作路径下所有文件权限

    chdir("/"); // 修改p3的工作路径 应是一个不可被卸载被删除的固定目录

    // 下面的代码就可以完成自己需求了
    b_task();
}

int main(int argc, char const *argv[])
{
    // b_running();
    b_daemon();
    return 0;
}