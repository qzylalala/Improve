#include<stdio.h>
#define CHANGE 1
int main()
{
	int Word;
	while ((Word = getchar()) != '\n')
	{
#if CHANGE
	printf("%c", Word ^ 32);
#else
	printf("%c", Word);
#endif
	}
	printf("\n");
	return 0;
}
