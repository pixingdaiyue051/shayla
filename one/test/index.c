#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// 输出所有的命令行输入参数
	printf("%d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	// scanf返回值代表匹配的数值个数0则表示没有匹配输入
	// int n;
	// int v = scanf("%d", &n);
	// printf("%d,%d\n", n, v);
	// 清空缓冲区 scanf默认不会清除回车符
	// while(getchar() != '\n');

	// 输出八进制 十六进制
	// int d = 123;
	// printf("%o\n%x\n", d);
	return 0;
}