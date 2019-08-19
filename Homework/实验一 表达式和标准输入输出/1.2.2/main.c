#include<stdio.h>
#include<stdlib.h>
int main()
{
int a, b;
printf("input two integers:");
scanf("%d %d",&a, &b);
a^=b;b^=a;a^=b;
printf("\na = %d, b = %d",a,b);
return 0;
}
