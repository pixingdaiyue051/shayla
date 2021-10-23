#include <stdio.h>
#define N 10
#define FNT(n) n * 21
#define ADD(a, b) (a + b)
#define SUB(a, b) (a - b)
#define MUT(a, b) (a * b)
#define DIV(a, b) (a / b)

typedef int ok;

int main(int argv, char *argc[])
{
	printf("hello world! %d\n", argv);
	for (int i = 0; i < argv; i++)
	{
		printf("%s\n", argc[i]);
	}

	ok i = N;
	ok v = FNT(i);
	float a1 = ADD(3.1, 4.6);
	float a2 = SUB(6.2, 9.4);
	float a3 = MUT(3.0, 4.9);
	float a4 = DIV(6.1, 1.6);
	printf("%f,%f,%f,%f\n", a1, a2, a3, a4);
	return 0;
}