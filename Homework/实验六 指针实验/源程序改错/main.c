#include<stdio.h>
void main(void)
{
    float *p,n;
    p=&n;
    scanf("%f",&n);
    printf("%f\n",*p);
}
