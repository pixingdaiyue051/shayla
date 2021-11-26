#include <stdio.h>

#include "stack_data.c"
#include "stack_ope.c"
#include "caculator.c"

// #include "caculator_fnt.h"

int main(int argv, char *argc[])
{
	printf("输入四则运算表达式目前只支持+-*/整数运算\n");
	char s[32];
	scanf("%s", s);
	double r = caculate(s);

	printf("运算结果%.3f\n", r);
	return 0;
}