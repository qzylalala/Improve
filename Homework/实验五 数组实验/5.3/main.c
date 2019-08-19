#include<stdio.h>
#include<string.h>
void strnins(char s[], char t[], int n);
int main()
{
	char s[100], t[100];
	int n;
		printf("Input s:\n");
		fgets(s, 100, stdin);
		s[strlen(s) - 1] = s[strlen(s)];
		printf("Input t:\n");
		fgets(t, 100, stdin);
		s[strlen(t) - 1] = s[strlen(t)];
		printf("Input n:\n");
		scanf("%d", &n);
		strnins(s, t, n);
		printf("%s", s);
	return 0;
}
void strnins(char s[], char t[], int n)
{
	int len1 = strlen(t);
	int len2 = strlen(s);
	int i = 0, j = 0;
	//移位空出位置
	for (i = len2; i > n; i--)
		s[i + len1] = s[i];
	//插入字符串
	for (i = n + 1, j = 0; i < n + len1 + 1; i++, j++)
		s[i] = t[j];
}
