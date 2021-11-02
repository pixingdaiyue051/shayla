#include <stdio.h>
#include <stdlib.h>
#define N 10
#define FNT(n) n * 21
#define ADD(a, b) (a + b)
#define SUB(a, b) (a - b)
#define MUT(a, b) (a * b)
#define DIV(a, b) (a / b)

// typedef enum OPERATOR
// {
// 	ADD = 1,
// 	PLUS = 1,
// 	MUL = 2,
// 	DIV = 2
// } ope_t;

// double operate(ope_t o, double a, double b)
// {
// 	double r;
// 	switch (o)
// 	{
// 	case ADD:
// 		r = a + b;
// 		break;

// 	case PLUS:
// 		r = a - b;
// 		break;

// 	case MUL:
// 		r = a * b;
// 		break;

// 	case DIV:
// 		r = a / b;
// 		break;

// 	default:
// 		r = 0.0;
// 		break;
// 	}
// 	return r;
// }

int main(int argv, char *argc[])
{
	// printf("hello world! %d\n", argv);
	// for (size_t i = 0; i < argv; i++)
	// {
	// 	printf("%s\n", argc[i]);
	// }

	// size_t i = N;
	// size_t v = FNT(i);
	// float a1 = ADD(3.1, 4.6);
	// float a2 = SUB(6.2, 9.4);
	// float a3 = MUT(3.0, 4.9);
	// float a4 = DIV(6.1, 1.6);
	// printf("%f,%f,%f,%f\n", a1, a2, a3, a4);

	double d = atof("1");
	printf("%.3f\n", d);

	return 0;
}