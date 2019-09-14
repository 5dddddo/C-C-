#pragma warning (disable : 4996)
#include <stdio.h>
void input(double *,double *,double *);
void output(double, double, double);
int main()
{
	double a, b, c;
	input(&a, &b, &c);
	output(a,b,c);
	return 0;
}

void input(double *a, double *b, double *c)
{
	printf("a = ");
	scanf("%lf", a);
	printf("b = ");
	scanf("%lf", b);
	printf("c = ");
	scanf("%lf", c);
}

void output(double a, double b, double c)
{
	int x;
	for (x = 1; x <= 20; x++)
	{
		printf("x = %d	=>	y = %.2lf\n", x, a*x*x + b*x + c);
	}
}