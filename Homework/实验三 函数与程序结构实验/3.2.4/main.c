#include<stdio.h>
int findCommonFactor(int x, int y);
int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	if (num1 != 0)
	{
		int cf = findCommonFactor(num1, num2);
		printf("%d\n", cf);
	}
	return 0;
}
int findCommonFactor(int x, int y)
{
	int temp;
	if(x<y)
	{
		int m=x;
		x=y;
		y=m;
	}
	if(x!=y)
	{
		temp=x-y;
		findCommonFactor(y, temp);
	}
	else return x;
}
