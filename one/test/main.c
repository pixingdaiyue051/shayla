#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
	// scanf返回值代表匹配的数值个数0则表示没有匹配输入
	// int n;
	// int v = scanf("%d", &n);
	// printf("%d,%d\n", n, v);
	// 清空缓冲区 scanf默认不会清除回车符
	// while(getchar() != '\n');

	// 输出八进制 十六进制
	int d = 123;
	printf("%o\n%x\n", d);
	return 0;
}