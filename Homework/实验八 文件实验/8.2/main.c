#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{
	char ch;
	FILE *fp;
	if (argc != 3) {
		printf("Arguments error!\n");
		exit(-1);
	}
	if (strcmp(argv[1], "type") != 0)
	{
		printf("%s is not a right command", argv[1]);
		exit(-1);
	}
	if ((fp = fopen(argv[2], "r")) == NULL) {      /* fp ָ�� filename */
		printf("Can't open %s file!\n", argv[2]);
		exit(-1);
	}

	while ((ch = fgetc(fp)) != EOF)       /* ��filename�ж��ַ� */
		putchar(ch);                  /* ����ʾ����д�ַ� */
	fclose(fp);                      /* �ر�filename */
	return 0;
}
