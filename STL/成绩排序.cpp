#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define max_num 1001
struct info{
	string name;
	int age;
	int score;
};
info student[max_num];

bool cmp(info a, info b)
{
	if(a.score < b.score)
	{
		return true;
	}
	else if(a.score > b.score)
	{
		return false;
	}
	else
	{
		if(a.name <= b.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}



int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> student[i].name >> student[i].age >> student[i].score;	
		}
		sort(student, student + n-1, cmp);
		for(int i = 0; i < n; i++)
		{
			cout << student[i].name << " " << student[i].age << " " << student[i].score << endl;	
		}
	}
	
	return 0;
}
