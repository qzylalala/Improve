#include<stdio.h>
int main()
{
	int a[3][4];
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		scanf("%d",&a[i][j]);
	}
	printf("原矩阵为：\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		printf("%d  ",a[i][j]);
		printf("\n");
	}
	printf("\n转置矩阵为：\n");
	for(j=0;j<4;j++)
	{
		for(i=0;i<3;i++)
		printf("%d  ",a[i][j]);
		printf("\n");
	}
	return 0;
 }
