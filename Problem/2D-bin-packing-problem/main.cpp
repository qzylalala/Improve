#include "read_data.h"
#include "Placement.h"


vector<Point> init_obj(double width, double height)
{
	vector<Point> retangle;
	Point p1; p1.x = 0, p1.y = 0;
	Point p2; p2.x = 0, p2.y = height;
	Point p3; p3.x = width, p3.y = height;
	Point p4; p4.x = width, p4.y = 0;

	retangle.push_back(p1);
	retangle.push_back(p2);
	retangle.push_back(p3);
	retangle.push_back(p4);

	return retangle;
}

//把所有piece放在矩形右上角不远处。
vector<Point>* init_pieces(vector<Point>* p, double width, double height)
{
	for (int i = 1; i <= Size(p); i++)
		for (int j = 0; j < int(p[i].size()); j++)
		{
			p[i][j].x += width - left_bound(p[i]);
			p[i][j].y += height - low_bound(p[i]);
		}

	return p;
}


int main()
{
	double width = 100000, height = 1600;
	vector<Point> *piece = new vector<Point>[10000];//piece[i]存储第i个piece的所有边界坐标
	read_data(filename, piece);
	piece = sort(piece);//按piece的area递减排序
	piece = init_pieces(piece, width, height);
	Point retangle; retangle.x = width, retangle.y = height;
	//以上为初始化工作

	vector<Point> *temp = new vector<Point>[10000];//不清空
	vector<Point> *temp_col = new vector<Point>[1000];//每填一列清空一次
	int cnt = 0;
	for (int i = 1; i <= Size(piece); i++)
	{
		if (Size(temp_col) == 0)
		{
			if (cnt == 0)
				piece[i] = after_move(piece[i], retangle.x, retangle.y);
			else
			{
				piece[i] = after_move(piece[i], 0, retangle.y);
				piece[i] = after_move(piece[i], piece_Hmove_length(temp, piece[i]), 0);
			}
			temp[i] = piece[i];
			temp_col[i] = piece[i];
		}

		if (retangle.y - upper_y(temp_col) >= (upper_bound(piece[i]) - low_bound(piece[i])))
		{
			double delt_y;

			if (cnt == 0)
			{
				piece[i] = after_move(piece[i], retangle.x, 0);
				delt_y = piece_Vmove_length(temp_col, piece[i]);
				piece[i] = after_move(piece[i], 0, delt_y);
			}
			else
			{
				piece[i] = after_move(piece[i], piece_Hmove_length(temp, piece[i]), 0);
				delt_y = piece_Vmove_length(temp_col, piece[i]);
				piece[i] = after_move(piece[i], 0, delt_y);
				piece[i] = after_move(piece[i], piece_Hmove_length(temp, piece[i]), 0);
			}
			temp[i] = piece[i];
			temp_col[i] = piece[i];
		}
		else
		{
			cnt++;
			temp_col = NULL;
		}
	}
	//这个for循环将所有piece放置完毕。

	double rate, pieces_area = 0, needed_area = 0;
	for (int i = 1; i <= Size(piece); i++)
		pieces_area += area(piece[i]);

	needed_area = height * right_x(temp);
	rate = pieces_area / needed_area;
	std::cout << rate;

	system("pause");
	return 0;
}