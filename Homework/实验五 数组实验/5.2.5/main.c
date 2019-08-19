#include<stdio.h>
int main()
{
	unsigned int mask = 1 << 31;
	int num;
	char rst[40] = { 0 };
	while (scanf("%d", &num) != EOF)
	{
		int i = 0;
		for (mask = (1 << 31), i = 0; mask > 0; mask >>= 1, i++)
		{
			if (mask&num) //若此位置为1，则将rst中赋值为字符1
				rst[i] = '1';
			else rst[i] = '0';
		}
		rst[i] = '\0';//最后赋值结束符\0
		printf("%s\n", rst);
	}
	return 0;
}
