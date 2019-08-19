#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag = 0;
typedef struct _Stu {
	char stuNum[20];
	char name[30];
	float engGrade;
	float mathGrade;
	float phyGrade;
	float CGrade;
	float ave;
	float sum;
	struct _Stu *next;
}Stu;
Stu *createList(int);
void printList(Stu *stu);
int main()
{
	int i, n, nChange;
	scanf("%d", &n);
	getchar();
	Stu *stu = createList(n);
	Stu *head = stu;
	char waste[4];
	//input the list
	for (i = 0; i < n; i++)
	{
		scanf("%s%s", stu->stuNum, stu->name);
		scanf("%f", &stu->engGrade);
		scanf("%f", &stu->mathGrade);
		scanf("%f", &stu->phyGrade);
		scanf("%f", &stu->CGrade);
		fgets(waste, 4, stdin);
		stu = stu->next;
	}
	//print out the list
	printList(head);
	//change the partiicular contents. Take change the C grade of Harry for example
	stu = head;//initiate the pointer stu
	scanf("%d", &nChange);
	char *lesson[4] = { "英语","数学","物理","C" };
	char changeLesson[15], changeNum[20];
	float changeScore;
	while (nChange-- > 0)
	{
		stu = head;
		scanf("%s %s %f", changeNum, changeLesson, &changeScore);
		while (stu)
		{
			if (strcmp(stu->stuNum, changeNum) == 0)
			{
				if (strcmp(changeLesson, "英语") == 0)
					stu->engGrade = changeScore;
				if (strcmp(changeLesson, "数学") == 0)
					stu->mathGrade = changeScore;
				if (strcmp(changeLesson, "物理") == 0)
					stu->phyGrade = changeScore;
				if (strcmp(changeLesson, "C") == 0)
					stu->CGrade = changeScore;
				break;
			}
			stu = stu->next;
		}
	}
	printf("Alter:\n");
	printList(head);
	//calciulate the average scores of each student
	float sum[4] = { 0 };
	for (stu = head; stu != NULL; stu = stu->next)
	{
		stu->sum = stu->engGrade + stu->CGrade + stu->mathGrade + stu->phyGrade;
		stu->ave = stu->sum / 4;
	}
	//print out the sum and average
	printf("总分和平均分:\n");
	printf("%-15s%-20s%-10s%-10s\n", "ID", "名字", "总分", "平均分");
	stu = head;
	while (stu)
	{
		printf("%-15s%-20s%-10.2f%-10.2f\n",
			stu->stuNum, stu->name, stu->sum, stu->ave);
		stu = stu->next;
	}
	//sort the number
	Stu *begin, *end;
	for (begin = head; begin != NULL; begin = begin->next)
		for (end = begin; end != NULL; end = end->next)
			if (end->ave < begin->ave)
			{
				char tmpNum[20], tmpName[20];
				strcpy(tmpNum, end->stuNum);
				strcpy(end->stuNum,begin->stuNum);
				strcpy(begin->stuNum, tmpNum);
				strcpy(tmpName,end->name);
				strcpy(end->name,begin->name);
				strcpy(begin->name,tmpName);
				float tmpScore = end->ave;
				end->ave = begin->ave;
				begin->ave=tmpScore;
			}
	printf("\nSort:\n");
	printf("%-15s%-20s%-10s\n", "ID", "名字", "平均分");
	stu = head;
	while (stu)
	{
		printf("%-15s%-20s%-10.2f\n",
			stu->stuNum, stu->name, stu->ave);
		stu = stu->next;
	}
	printf("\n");
	return 0;
}
void printList(Stu *stu)
{
	printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", "ID", "名字", "英语", "数学", "物理", "C");
	while (stu)
	{
		printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",
			stu->stuNum, stu->name, stu->engGrade, stu->mathGrade, stu->phyGrade, stu->CGrade);
		stu = stu->next;
	}
	printf("\n");
}
Stu *createList(int stuNum)
{
	static int num;
	static Stu *head;
	static Stu *tail;
	if (flag == 0)
	{
		num = stuNum;
		head = (Stu*)malloc(sizeof(Stu));
		tail = head;
		flag = 1;
	}
	if (num-- < 2)
	{
		tail->next = NULL;
		return head;
	}
else {
		tail->next = (Stu*)malloc(sizeof(Stu));
		tail = tail->next;
		return createList(num);
	}
}
