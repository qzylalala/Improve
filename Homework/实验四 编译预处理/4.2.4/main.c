#include<stdio.h>
#include<math.h>
#define sum(a,b,c) (a+b+c)/2.0
#define area(a,b,c) sqrt(s*(s-a)*(s-b)*(s-c))
int main()
{
	float a,b,c,s,area;
	printf("Please input three integer a,b,c:");
	scanf("%f,%f,%f",&a,&b,&c);
	s=sum(a,b,c);
	area=area(a,b,c);
	printf("%f",area);
	return 0;
}
