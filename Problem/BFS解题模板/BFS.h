#pragma once
/*
模板可以大体分成6部分
1.头文件段
2.坐标结构体段
3.障碍物预设段
4.已访问结点和移动坐标段
5.BFS算法函数段
6.主函数段

定义一个二维数组：

int maze[5][5] = {

	0, 1, 0, 0, 0,

	0, 1, 0, 1, 0,

	0, 0, 0, 0, 0,

	0, 1, 1, 1, 0,

	0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
Input
一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
Output
左上角到右下角的最短路径，格式如样例所示。
Sample Input
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
Sample Output
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
*/

1.头文件段
//这里使用c++的<queue>函数，这样可以快速进行队列的操作，没啥好解释的，背下
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<queue>

2.坐标结构体段
//记录结点坐标，特别注意，这里的坐标也可能是一维的，不要死板，具体情况具体分析。
struct mi {
	int x;
	int y;
}ca;

3.障碍物预设段（有可能没有，是无障碍题目）
//这里往往是初始化好的迷宫地图，或是什么其他条件的障碍物,在这里1就是障碍物,
这个地图要么是自己输入，要么是题目已知条件
int map[5][5];
= {
   {0,1,0,0,0},
   {0,1,0,1,0},
   {0,0,0,0,0},
   {0,1,1,1,0},
   {0,0,0,1,0},
}
struct mi zhen[5][5];  //这里记录着路径子节点与父节点的对应关系在5中详解

4.已访问结点和移动坐标段
//注意移动坐标要一一对应，可以使用二维数组，代表着在迷宫中怎样移动
int visited[5][5];     //用来记录已访问节点，但是也可以不要这个数组，每次走到后直接改变图，
把此节点的内容直接变成障碍物即可
int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0,0,-1,1 };


5.BFS算法函数段
//这里主要是对BFS算法的套用,具体可以看下列详细注释
注意：凡是写到背下的，说明其基本可以完全复用，而且处于此模板的核心部分

void BFS()
{
	memset(visited, 0, sizeof(visited));       //背下，初始化已访问数组
	queue<mi>q;                              //背下,初始化队列
	struct mi A;                             //背下，把第一个结点压入队列里
	A.x = 0;                                   //初始化第一个节点坐标 没啥好说的
	A.y = 0;
	visited[0][0] = 1;                         //初始化首已访问节点，说明自己已被访问
	zhen[0][0].x = 0;                          //初始化对应关系底层结点  下面将详细解释
	zhen[0][0].y = 0;

	//特别注意:千万不要死板，此题是走迷宫，所以首节点是左上角，其他题可不一定，千万不要一堆0就上去了

	q.push(A);                              //将首节点压入队列                 
	while (!q.empty())                       //背下，只要队列里还有东西就继续
	{
		struct mi te = q.front();             //这两句背下
		q.pop();

		if (te.x == 4 && te.y == 4)                //找到答案后退出 
			return;

		//特别注意:不一定都需要退出条件，如果题目要求我们对单节点进行移动（后面会提到）

		for (int i = 0; i < 4; i++)                //背下，把各个方向都试着走一遍
		{
			int zx = te.x + xx[i];              //zx,zy为移动后节点坐标
			int zy = te.y + yy[i];

			if (zx < 0 || zx>4 || zy < 0 || zy>4 || map[zx][zy] || visited[zx][zy])      //背下，判断是否为合法路径，比如墙和已走过节点都为非法路径，但让我前面提到过，可以把已走过节点直接在地图上变成墙也行，这样就不需要visited数组
				continue;

			visited[zx][zy] = 1;              //将已访问节点标志为1  下标对应当前节点

			struct mi kao;                  //背下，将合法子节点压入队列
			kao.x = zx;
			kao.y = zy;
			q.push(kao);

			//记录着谁走到了它
			zhen[zx][zy].x = te.x;           //现在来说明这个二维数组怎样记录最短路径，首先这个数组里存的是坐标结构体，数组下标代表着子节点坐标，而数组内容存着父节点坐标，这样皆可以通过循环，一级一级找上去，既可以知道最短路径长度，也可以打印所有经过的节点坐标
			zhen[zx][zy].y = te.y;
		}
	}
}

6.主函数部分
//略写 这没什么好说的 根据题目要求不同这个地方的灵活性也最大
int main(void)
{

	for (int m = 0; m < 5; m++)                  //初始化迷宫地图
	{
		for (int n = 0; n < 5; n++)
		{
			scanf("%d", &map[m][n]);
		}
	}

	BFS();
	int num[30][2];

	int x = 4, y = 4;
	int i = 0;
	while (1)
	{                                //把父子节点关系倒着取出放入数组中以便打印
		int k;
		k = x;
		x = zhen[x][y].x;
		y = zhen[k][y].y;

		num[i][0] = x;
		num[i][1] = y;
		i++;
		if (x == 0 && y == 0)
			break;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		printf("(%d, %d)\n", num[j][0], num[j][1]);          //打印路径节点部分
	}
	printf("(4, 4)");
	return 0;
}