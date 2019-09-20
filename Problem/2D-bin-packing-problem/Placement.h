#include "Geometric.h"

//关键步骤，水平移动
double piece_Hmove_length(vector<Point> *p, vector<Point> piece)//在read_data中，p是从1开始存储的
{
	vector<Point> piece1 = build_left_piece(piece);
	vector<Point> *p1 = new vector<Point>[10000] ;
	int count_all = 0;
	for (int i = 1; i <= Size(p); i++)
	{
		if ((piece_in_piece(p[i], piece1) || Intersect(p[i], piece1)) && (!piece_in_piece(p[i], piece) && !Intersect(p[i], piece)))
		{
			p1[i] = p[i];
			count_all++;
		}
	}

	double m = left_bound(piece);
	if (count_all == 0)
		return m;

	for (int i = 0; i < int(piece.size()); i++)
		for (int j = 1; j <= Size(p); j++)
			for (int k = 0; k < int(p[j].size()); k++)
			{
				double d;
				if (point_Hdis_segment(piece[i], p[j][k], p[j][(k + 1) % (int(p[j].size()))]) > 0)
					d = point_Hdis_segment(piece[i], p[j][k], p[j][(k + 1) % (int(p[j].size()))]);

				if (d < m)
					m = d;
			}

	return m;
}


//竖直移动
double piece_Vmove_length(vector<Point> *p, vector<Point> piece)//p是从1开始存储的
{
	vector<Point> piece1 = build_low_piece(piece);
	vector<Point> *p1 = new vector<Point>[10000];
	int count_all = 0;
	for (int i = 1; i <= Size(p); i++)
	{
		if ((piece_in_piece(p[i], piece1) || Intersect(p[i], piece1)) && (!piece_in_piece(p[i], piece) && !Intersect(p[i], piece)))
		{
			p1[i] = p[i];
			count_all++;
		}
	}

	double m = left_bound(piece);
	if (count_all == 0)
		return m;

	for (int i = 0; i < int(piece.size()); i++)
		for (int j = 1; j <= Size(p); j++)
			for (int k = 0; k < int(p[j].size()); k++)
			{
				double d;
				if (point_Vdis_segment(piece[i], p[j][k], p[j][(k + 1) % (int(p[j].size()))]) > 0)
					d = point_Vdis_segment(piece[i], p[j][k], p[j][(k + 1) % (int(p[j].size()))]);

				if (d < m)
					m = d;
			}

	return m;
}


//返回移动之后的piece
vector<Point> after_move(vector<Point> piece, double H, double V)
{
	for (int i = 0; i < int(piece.size()); i++)
	{
		piece[i].x -= H;
		piece[i].y -= V;
	}

	return piece;
}