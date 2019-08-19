#include<stdio.h>
int  main( void )
{
unsigned short x,m,n;
printf("输入x(16进制),m(0~15)和n(1~16-m) \n ");
scanf("%hx %hd %hd",&x,&m,&n);
if (m>=0&&m<=15&&n>=1&&n<=16-m)
 	printf("ans=%hx\n",(x>>m)<<(16-n));
return  0;
}
