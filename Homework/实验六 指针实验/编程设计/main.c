#include<stdio.h>
#include<stdlib.h>
#define M 5		//number of classes
#define N 5     //number of students
int main()
{
	char *className = (char*)malloc(8*sizeof(char)*M);
	char **studentName = (char**)malloc(8*sizeof(char*)*N);
	float **studentGrade = (float**)malloc(8*sizeof(float*)*N);
	int i, j;
	for (i = 0; i < M; i++)
	{
		scanf("%c", className + i);
		getchar();
	}
	for (j = 0; j < N; j++)
	{
		*(studentName + j) = (char*)malloc(8 * sizeof(char) * 100);
		*(studentGrade + j) = (float*)malloc(8 * sizeof(float)*M);
		scanf("%s", *(studentName + j));
		for (i = 0; i < M; i++)
			scanf("%f", *(studentGrade + j) + i);
	}
	float sum;
	for (j = 0; j < N; j++)
	{
		sum = 0;
		for (i = 0; i < M; i++)
			sum += *(*(studentGrade + j) + i);
		printf("Average score of %s is %.2f\n", *(studentName + j), sum / M);
	}

	//计算每个课程的平均数并输出
	float *ave = (float*)malloc(8 * sizeof(float)*M);
	for (i = 0; i < N; i++)
	{
		sum = 0;
		for (j = 0; j < M; j++)
			sum += *(*(studentGrade + j) + i);
		*(ave + i) = sum / M;
		printf("Average score of %c is %.2f\n", *(className + i), sum / M);
	}

	//统计低于全班各课程成绩平均的人数
	for (i = 0; i < N; i++)
	{
		int num = 0;
		for (j = 0; j < M; j++)
			if (*(ave + i) > *(*(studentGrade + j) + i))
				num++;
		printf("Number of students lower than avg of %c is %d\n", *(className + i), num);
	}

	//统计全班不及格人数
	for (i = 0; i < N; i++)
	{
		int num = 0;
		for (j = 0; j < M; j++)
			if (*(*(studentGrade + j) + i) < 60.0)
				num++;
		printf("Number of students %c fail is %d\n", *(className + i), num);
	}

	//统计全班90分以上人数
	for (i = 0; i < N; i++)
	{
		int num = 0;
		for (j = 0; j < M; j++)
			if (*(*(studentGrade + j) + i) > 90.0)
				num++;
		printf("Number of students %c perfect is %d\n", *(className + i), num);
	}

	return 0;
}
