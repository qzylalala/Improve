#include "Geometric.h"

//�ؼ����裬ˮƽ�ƶ�
double piece_Hmove_length(vector<Point> *p, vector<Point> piece)//��read_data�У�p�Ǵ�1��ʼ�洢��
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


//��ֱ�ƶ�
double piece_Vmove_length(vector<Point> *p, vector<Point> piece)//p�Ǵ�1��ʼ�洢��
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


//�����ƶ�֮���piece
vector<Point> after_move(vector<Point> piece, double H, double V)
{
	for (int i = 0; i < int(piece.size()); i++)
	{
		piece[i].x -= H;
		piece[i].y -= V;
	}

	return piece;
}