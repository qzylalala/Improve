#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct Point
{
	double x;
	double y;
};

string filename = "1.txt";
int read_data(string file_name, vector<Point> *piece)//piece[i]存储第i个piece的所有边界坐标
{
	ifstream infile;
	infile.open(file_name);
	if (!infile)
		cout << "error" << endl;

	string str;
	int count_all = 1;

	while (getline(infile, str))
	{
		int Size = str.size();
		int num = 0;
		Point p;
		for (int i = 2; i <= Size - 3; i++)
		{
			string x_str = "";
			if (str[i] == '[')
				continue;
			else if (isdigit(str[i]))
				x_str += str[i];
			else if (str[i] == '.')
				x_str += str[i];
			else if (str[i] == ',' || str[i] == ']')
			{
				if (str[i + 1] != '[')
				{
					num++;
					if (num % 2 == 1)
						p.x = stof(x_str);
					else
					{
						p.y = stof(x_str);
						piece[count_all].push_back(p);
					}
				}
			}
		}
		count_all++;
	}

	return count_all--;
}


int Size(vector<Point> *piece)
{
	return read_data(filename, piece);
}



double det(Point p1, Point p2)//叉乘
{
	return p1.x*p2.y - p1.y*p2.x;
}


double area(vector<Point> piece)//根据piece的坐标求该不规则图形的面积
{
	double s = 0;
	int i;
	for (i = 0; i < int(piece.size() - 1); i++)
	{
		s += det(piece[i], piece[i + 1]);
	}
	s += det(piece[i], piece[0]);

	return s / 2;
}


vector<Point>* sort(vector<Point> *p)//返回值包含的piece按area递减排列
{
	vector<Point> *temp = new vector<Point>[10000];
	vector<Point> piece;
	for (int i = 1; i < Size(p); i++)
		for (int j = 1; j <= Size(p) - i + 1; j++)
			if (area(p[j]) < area(p[j + 1]))
			{
				piece = p[j];
				p[j] = p[j + 1];
				p[j + 1] = piece;
			}

	for (int i = 1; i < Size(p); i++)
		temp[i] = p[i];

	return temp;
}