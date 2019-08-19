#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int zhishu (int m)
    {
        int i;
        if (m==2) return 1;
        if(m%2==0) return 0;
        for(i=3;i<=sqrt(m);i+=2)
     {
     if(m%i==0)
        return 0;
     }
    return 1;
    }

int main()
{
	int a,b,c;
	scanf("%d",&c);
	a=2;
	b=c-a;
	for(a=2;a<=b;a++)
    {
    if (zhishu(a)==0) continue;
    else
    {
        b=c-a;
        if (zhishu(b)==1) break;
        }
    }
    printf("%d=%d+%d\n",c,a,b);
}
