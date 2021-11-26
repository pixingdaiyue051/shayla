#include <stdio.h>
#include <stdlib.h>
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

int main(int argv, char *argc[])
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
	return 0;
}