#include<stdio.h>
#define PI 3.14159
void main( void )
{
int f ;
short p, k, newint ;
double c , r , s ;
printf("Input  Fahrenheit:" ) ;
scanf("%d", &f ) ;
c = 5.0/9*(f-32) ;
printf( " \n %d (F) = %.2f (C)\n\n ", f, c ) ;

printf("input the radius r:");
scanf("%lf", &r);
s = PI * r * r;
printf("\nThe acreage is %.2f\n\n",s);
printf("input hex int k, p :");
scanf("%hx %hx", &k, &p );
newint = (p&0xff00)|(((k&0xff00)>>8)&0x00ff);
printf("newint = %x\n\n",newint);
}
