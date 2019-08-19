#include<stdio.h>
int main()
{
	int year,month,day,m,i;
	m=0;
	scanf("%d %d %d",&year,&month,&day);
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	if((year%4==0&&year%100!=0||year%400==0))
	{
		for(i=1;i<month;i++)
		m+=b[i];
		m+=day;
	}
	else
	{
		for(i=1;i<year;i++)
		m+=a[i];
		m+=day;
	}
	printf("the day is the year of %d day",m);
	return 0;
}
