#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_stack.h"
#include "../ext/dbg.h"

/**
 * 判断是否是运算符
 **/
int isoperator(int c)
{
	return c == 43 || c == 45 || c == 42 || c == 47;
}

/**
 * 获得操作符优先级
 **/
int getpriority(int c)
{
	switch (c)
	{
	case 43:
		return 1;
	case 45:
		return 2;
	case 42:
		return 3;
	case 47:
		return 4;
	default:
		return 0;
	}
}

/**
 * 不同操作符 不同计算
 **/
double caculate0(int c, double a, double b)
{
	switch (c)
	{
	case 43:
		return a + b;
	case 45:
		return a - b;
	case 42:
		return a * b;
	case 47:
		return a / b;
	default:
		return 0.0f;
	}
}

/**
 * 递归入栈出栈计算
 * stack_ope 操作符栈
 * stack_num 操作数栈
 * tmp_c 待入栈的操作符
 * 待入栈的操作符大于栈顶则直接入栈 否则先出栈计算再入栈
 **/
void caculate(ls_t *stack_ope, ls_t *stack_num, char tmp_c)
{
	if (stack_ope->size == 0)
	{
		ls_push(stack_ope, tmp_c);
	}
	else
	{
		ls_dt pm;
		ls_peek(stack_ope, &pm);
		int p0 = getpriority(tmp_c);
		int p1 = getpriority(pm);
		if (p0 > p1)
		{
			ls_push(stack_ope, tmp_c);
		}
		else
		{
			ls_dt pm0, pm1;
			ls_pop(stack_num, &pm0);
			ls_pop(stack_num, &pm1);
			ls_pop(stack_ope, &pm);
			ls_push(stack_num, caculate0(pm, pm1, pm0));
			caculate(stack_ope, stack_num, tmp_c); // 进入递归
		}
	}
}

/**
 * 按字符串索引截取字符串并转换为数字 前闭后开
 **/
double slice_2num(char *src, int idx0, int idx1)
{
	int i = 0;
	int dst_len = idx1 - idx0 - 1;
	char dst[dst_len];
	for (i = 0; i < dst_len; i++)
	{
		dst[i] = src[i + idx0 + 1];
	}
	return atof(dst);
}

/**
 * 运算主逻辑
 **/
double mmcompute(char *src)
{
	ls_t *stack_num = ls_init();
	ls_t *stack_ope = ls_init();

	int i = 0;
	_ht_check(!isoperator(src[i]), "必须以操作数开始");
	int len = strlen(src);
	_ht_check(!isoperator(src[len]), "必须以操作数结尾");
	int idx0 = -1; // 记录操作符起始位置
	int idx1 = 0;  // 记录操作符结束位置
	char tmp_c;
	double arg0;
	for (i = 1; i < len; i++)
	{
		tmp_c = src[i];
		if (!isoperator(tmp_c)) // 不是操作符跳过循环
		{
			continue;
		}
		idx1 = i;																		// 记录当前操作符位置
		_ht_check(idx1 - idx0 != 1, "第%d %d格连续输入两个操作符", idx0 + 1, idx1 + 1); // 检查是否连续两个操作符
		arg0 = slice_2num(src, idx0, idx1);
		ls_push(stack_num, arg0);
		caculate(stack_ope, stack_num, tmp_c);
		idx0 = idx1; // 将上次记录的操作符位置设置给tmp1
	}
	arg0 = slice_2num(src, idx0, len + 1); // 手动添加最后一位数字
	ls_push(stack_num, arg0);
	caculate(stack_ope, stack_num, 0); // 最后再触发一次计算

	ls_dt pm;
	ls_pop(stack_num, &pm); // 出栈获得最终结果

	ls_free(stack_num);
	ls_free(stack_ope);
	return pm;
_ht_error:
	ls_free(stack_num);
	ls_free(stack_ope);
	return 0.0f;
}

int main(int argc, const char *argv[])
{
	double res = mmcompute("101*23.1-3.41*40+4*54.3/56*34/3*2-4*4-7+2+45-41-3-1-11-3*41+6/2*4-4-2");
	printf("%.3lf\n", res);
}