#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ext0()
{
	short h = 3;
	int i = 100;
	long l = 1L * 1024L * 1024L * 1024L;
	float f = 3.14156f;
	double d = 1911.11;
	char c = 65;
	printf("size of short:%lu,h=%hd\n", sizeof(short), h);
	printf("size of int:%lu,i=%d\n", sizeof(int), i);
	printf("size of long:%lu,l=%ld\n", sizeof(long), l);
	printf("size of float:%lu,f=%f\n", sizeof(float), f);
	printf("size of double:%lu,d=%lf\n", sizeof(double), d);
	printf("size of char:%lu,c=%c\n", sizeof(char), c);

	int ui = -100;
	long ul = -100;
	short us = -100;
	printf("%hu,%u,%lu\n", us, ui, ul);
	printf("%hd,%d,%ld\n", us, ui, ul);

	char nul = '\b';
	double r = d * nul;
	printf("r=%.3lf%%\n", r);

	char s[] = "i am the king of the world";
	char *p = "of course i still love you";
	printf("size of s:%lu,s=%s\n", sizeof(s), s);
	printf("size of p:%lu,p=%p\n", sizeof(p), p);

	int area[] = {10, 20, 30, 40, 50};
	char name[] = "jack";
	char name1[] = {'j', 'a', 'c', 'k', '\0'};
	area[1] = name[4];
	name[4] = 'r';
	printf("size of area:%ld\n", sizeof(area));
	printf("numbers of area:%ld\n", sizeof(area) / sizeof(int));
	printf("elements in area:%d,%d,%d\n", area[0], area[1], area[10]);
	printf("size of name:%ld,%ld\n", sizeof(name), sizeof(name1));
	printf("elements in name:%c,%c,%c\n", name[0], name[1], name[10]);
	printf("name:%s,name1:%s\n", name, name1);
}

enum BOOL
{
	FALSE,
	TRUE
};

/**
 * 
 */
void ext1()
{
	// const 作用于以后的变量类型不可变
	// 此时a和b都是不可变的
	const int a = 1;
	int const b = 2;
	// 通过使用指针的形式可以间接的修改const变量 但是编译器依然会有警告 而且在c++中无法通过编译 c++类型检查更严格
	int *pc = &a;
	printf("%d\n", a);
	*pc = 100;
	printf("%d\n", a);

	// 此时*pm不可变 pm是指针本质上是内存上的地址仍然可变
	const int *pm = malloc(10);
	printf("%p,%d\n", pm, *pm);
	pm = &a;
	printf("%p,%d\n", pm, *pm);

	// c没有设计bool类型 可以使用stdbool.h扩展使用bool 本质上是宏
	bool b1 = false;
	printf("%d\n", b1);
	b1 = 21; // 此时会自动转变为false(0)或true(非0)
	printf("%d\n", b1);
	// int g1 = b1 * 4;
	// printf("%d\n", g1);

	// c枚举本质上还是整数 可以赋值除已定义数值外的整数
	enum BOOL b2 = FALSE;
	printf("%d\n", b2);
	b2 = 21;
	printf("%d\n", b2);
	// int g2= b2 * 4;
	// printf("%d\n", g2);

	// 表达式可以赋值但是不能被赋值
	int v1, v2;
	v1 = v2 = 100; // 等同于 v1 = (v2 = 100); 先对v2赋值 再将v2=100表达式结果赋值给v1
	// (v1 = v2) = 50; // (v1 = v2)是一个表达式 无法对表达式赋值
	printf("%d,%d\n", v1, v2);
}

void test0()
{
	puts("hello world");
	putchar(65);
	putchar('a');
	putchar('\n');

	int c = 0;
	if (c) // 0以外都是true
	{
		puts("true");
	}

	short h1 = 10 & 2;
	short h2 = 10 | 2;
	short h3 = 10 ^ 2;
	short h4 = ~2;
	printf("与:%d\n", h1);
	printf("或:%d\n", h2);
	printf("异或:%d\n", h3);
	printf("非:%d,%hu\n", h4, h4);
}

int main()
{
	// ext0();
	ext1();

	return 0;
}