#include <iostream>
#include "Astar.h"
using namespace std;

int main()
{
	//��ʼ����ͼ���ö�ά��������ͼ��1��ʾ�ϰ��0��ʾ��ͨ
	vector<vector<int>> maze = {
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,1,0,1,0,0,0,0,1},
		{1,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,1,1,1},
		{1,1,1,0,0,0,0,0,1,1,0,1},
		{1,1,0,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	};
	Astar astar;
	astar.InitAstar(maze);

	//������ʼ�ͽ�����
	Point start(1, 1);
	Point end(6, 10);
	//A*�㷨��Ѱ·��
	list<Point *> path = astar.GetPath(start, end, false);
	//��ӡ
	for (auto &p : path)
		cout << '(' << p->x << ',' << p->y << ')' << endl;

	system("pause");
	return 0;
}