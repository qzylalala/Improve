#include<stdio.h>
enum _state { SPACE, COPY };
void change(char str[]);
int main()
{
	FILE *fp1;
	char str[100];
	fp1 = fopen("D:\\m.txt", "w+");
	fgets(str, 100, stdin);
	change(str);
	fprintf(fp1, "%s", str);
	fclose(fp1);
	return 0;
}
void change(char str[])
{
	int i = 0;
	enum _state state;
	if(str[0]==' ') state = SPACE;
	else {
		str[0] ^= 32;
		state = COPY;
	}
	for (i = 1; str[i] != '\0'; i++)
	{
		switch (state)
		{
		case SPACE:
			if (str[i] <= 'z'&&str[i] >= 'a')
				str[i] ^= 32;
			if (str[i] == ' ')
				state = SPACE;
			else state = COPY;
			break;
		case COPY:
			if (str[i] == ' ')
				state = SPACE;
			else  state = COPY;
			break;
		}
	}
}
