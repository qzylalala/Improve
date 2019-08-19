#include<stdio.h>
int main()
{
	int x,a,b,c;
	for(x=100;x<1000;x++)
	{
		a = x%10;
	    b = (x/10)%10;
	    c = x/100;
	    if(a*a*a+b*b*b+c*c*c==x)
	    printf("%5d",x);
	}
	return 0;
}
