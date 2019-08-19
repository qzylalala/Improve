#include<stdio.h>
double sum_fac(int n);
int main(void)
{
	double k;
	for (k = 1; k<6; k++)
		printf("k=%lf\tthe sum is %lf\n", k, sum_fac(k));
	return 0;
}
double sum_fac(int n)
{
	double s = 0;
	int i;
	double fac = 1;
	for (i = 1; i <= n; i++)
	{
		fac *= i;
		s += 1 / fac;
	}
	return s;
}
