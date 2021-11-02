#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_data_fnt.h"
#include "stack_ope_fnt.h"

/**
 * 获得操作符优先级
 * */
int priority(char c)
{
	switch (c)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	default:
		return 0;
	}
}

/**
 * 操作符不同计算
 * */
double caculate1(char c, double a, double b)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return 0.0;
	}
}

/**
 *  c 当前输入的字符
 *  c_top 当前栈顶操作符
 * */
void recrusive(char c, char c_top)
{
	// 当前空栈 直接入栈
	if ('_' == c_top)
	{
		ope_push(c);
		return;
	}
	int p = priority(c);
	int p_c_top = priority(c_top);
	if (p > p_c_top)
	{
		ope_push(c);
		return;
	}
	// 输入的优先级小于或等于栈顶 出栈计算再入栈
	char c1 = ope_pop();
	double b = dd_pop();
	double a = dd_pop();
	dd_push(caculate1(c1, a, b));
	recrusive(c, ope_peek());
}

/**
 * 运算主逻辑
 * */
double caculate(char s[])
{
	int len = strlen(s);
	for (size_t i = 0; i < len; i++)
	{
		char c = s[i];
		// 输入字符的优先级
		int p = priority(c);
		// 0表示数字 直接入栈
		if (0 == p)
		{
			char s1[] = {c, '\0'};
			double d1 = atof(s1);
			dd_push(d1);
			continue;
		}
		// 当前栈顶操作符
		char c1 = ope_peek();
		// 递归计算
		recrusive(c, c1);
	}

	// 最后再计算一遍
	recrusive('~', ope_peek());
	ope_pop();
	double dddd = dd_pop();
	dd_free(dd_top);
	ope_free(ope_top);
	return dddd;
}