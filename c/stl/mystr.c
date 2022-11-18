#include <stdio.h>

/**
 * 计算字符串长度 实现strlen
 **/
int ht_str_len(char *s)
{
	if (s == NULL)
	{
		return 0;
	}
	int r = 0;
	while (s[r++] != '\0')
		;
	// printf("%s len:%d\n", s, r - 1);
	return r - 1;
}

/**
 * 比较两个字符串是否相等 实现strcmp
 */
int ht_str_cmp(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
	{
		return 1;
	}
	if (s1 == NULL || s2 == NULL)
	{
		return 0;
	}
	int len1 = ht_str_len(s1);
	int len2 = ht_str_len(s2);
	if (len1 != len2)
	{
		return 0;
	}
	int tmp = 0, i = 0;
	for (i = 0; i < len1; i++)
	{
		tmp = s1[i] == s2[i];
		// printf("%c,%c,%d\n", *(s1 + i), *(s2 + i), r2);
		if (!tmp)
		{
			return 0;
		}
	}
	return 1;
}

/**
 * 将字符串转换成数字 实现atoi
 */
int ht_str_2int(char *s)
{
	int len = ht_str_len(s);
	if (len == 0)
	{
		return 0;
	}
	int i = 0, j = 0, tmp = 0, r = 0;
	for (i = 0; i < len; i++)
	{
		tmp = s[i] - 48; // 0的asc码是48
		if (tmp < 0 || tmp > 9)
		{
			return 0;
		}
		for (j = i + 1; j < len; j++) // 循环乘10 模拟幂运算 乘法即二进制的逐位或加运算
		{
			tmp *= 10;
		}
		r += tmp;
	}
	return r;
}