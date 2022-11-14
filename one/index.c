#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define N 10
#define FNT(n) n * 21
#define ADD(a, b) (a + b)
#define SUB(a, b) (a - b)
#define MUT(a, b) (a * b)
#define DIV(a, b) (a / b)

#define MAX(a, b)                      \
	(                                  \
		{                              \
			typeof(a) _a = a;          \
			typeof(a) _b = b;          \
			(void)(&_a == &_b);        \
			(_a) > (_b) ? (_a) : (_b); \
		})

/**
 *  利用宏定义代替函数实现
 *  由于宏定义在代码编译阶段是简单代码片段替换 某些情况下会比使用函数更高效
 */
void def()
{
	float a1 = ADD(3.1, 4.6);
	float a2 = SUB(6.2, 9.4);
	float a3 = MUT(3.0, 4.9);
	float a4 = DIV(6.1, 1.6);
	printf("%f,%f,%f,%f\n", a1, a2, a3, a4);

	int a = 1;
	int b = 3;
	int c = MAX(a, b++);
	printf("%d,%d,%d\n", a, b, c);

	float num = 9.1F;
	long lo = *(long *)&num;

	printf("%ld\n", lo);
}

/**
 *  输出错误内容
 */
void err()
{
	FILE *pf;
	pf = fopen("../out/test.txt", "rb");
	if (pf == NULL)
	{
		perror("err num");
		fprintf(stderr, "fail to open file: %s\n", strerror(errno));
		exit(1);
	}
	fclose(pf);
}

/**
 * 当定义一个变量可以没有初始值
 * 此时变量的初始值取决于该内存是否有被其他程序占用并赋值
 */
void typeope()
{
	char c;
	printf("%c\n", c);
	int i;
	printf("%d\n", i);
	short s;
	printf("%d\n", s);
	long l;
	printf("%d\n", l);
	float f;
	printf("%f\n", f);
	double b;
	printf("%f\n", b);
	char *ch;
	printf("%s", ch);
	char *p;
	printf("%p", p);
}

/**
 * scanf返回值代表匹配的数值个数0则表示没有匹配输入
 */
void inope0()
{
	int n;
	int v = scanf("%d", &n);
	printf("%d,%d\n", n, v);
	// 清空缓冲区 scanf默认不会清除回车符
	while (getchar() != '\n')
		;
}

/**
 * 输出所有的命令行的输入参数
 */
void inope(int argc, char const *argv[])
{
	//
	printf("arguments count:%d\n", argc);
	for (int i = 0; i < argc;)
	{
		printf("%d.%s\n", ++i, argv[i]);
	}

	// if ('3' == *argv[1])
	// {
	// 	printf("test single char is ok\n");
	// }

	// char *msg = "hhs56@667*本不耐热";
	// if (*msg == *argv[2])
	// {
	// 	printf("test string is ok\n");
	// }
}

int main(int argc, char const *argv[])
{
	inope(argc, argv);
	typeope();
	return 0;
}