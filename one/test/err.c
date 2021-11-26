#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void fi()
{
	printf("fi\n");
	FILE *pf;
	pf = fopen("../myfile/test.txt", "rb");
	if (pf == NULL)
	{
		perror("错误码");
		fprintf(stderr, "打开文件错误: %s\n", strerror(errno));
		exit(1);
	}
	fclose(pf);
	return;
}

void test()
{
	printf("test\n");
	return;
}

int main(int argv, char *argc[])
{
	test();
	printf("----------------\n");
	fi();
	printf("----------------\n");
	return 0;
}