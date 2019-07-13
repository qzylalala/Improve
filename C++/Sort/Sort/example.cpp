#include"Action.h"
#include<iostream>

using namespace std;
int main()
{
	int List[] = { 1, 3, 9, 5, 7 };
	Sort<int> s;
	s.BubbleSort(List);
	for (int i = 0; i < 5; i++)
	{
		cout << List[i] << endl;
	}

	return 0;
}