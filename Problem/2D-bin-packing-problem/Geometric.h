#include "read_data.h"
#include<algorithm>

double low_bound(vector<Point> p)
{
	double temp = 1000000;
	for (int i = 0; i < int(p.size()); i++)
	{
		temp = min(temp, p[i].y);
	}

	return temp;
}
double upper_bound(vector<Point> p)
{
	double temp = 0;
	for (int i = 0; i < int(p.size()); i++)
	{
		temp = max(temp, p[i].y);
	}

	return temp;
}

double left_bound(vector<Point> p)
{
	double temp = 1000000;
	for (int i = 0; i < int(p.size()); i++)
	{
		temp = min(temp, p[i].x);
	}

	return temp;
}

double right_bound(vector<Point> p)
{
	double temp = 0;
	for (int i = 0; i < int(p.size()); i++)
	{
		temp = max(temp, p[i].x);
	}

	return temp;
}

Point left_upper_point(vector<Point> p)
{
	Point temp;
	temp.x = 0, temp.y = 0;
	for (int i = 0; i < int(p.size()); i++)
	{
		if (p[i].y > temp.y)
			temp = p[i];
		if (p[i].y == temp.y && p[i].x < temp.x)
			temp = p[i];
	}

	return temp;
}


Point left_low_point(vector<Point> p)
{
	Point temp;
	temp.x = 0, temp.y = 100000;
	for (int i = 0; i < int(p.size()); i++)
	{
		if (p[i].y < temp.y)
			temp = p[i];
		if (p[i].y == temp.y && p[i].x < temp.x)
			temp = p[i];
	}

	return temp;
}


bool line_intersect(Point pa, Point pb, Point pc, Point pd)//�ж��߶��Ƿ��ཻ
{
	double fc = (pb.x - pa.x) * (pc.y - pa.y) - (pc.x - pa.x) * (pb.y - pa.y);//AC * AB
	double fd = (pb.x - pa.x) * (pd.y - pa.y) - (pd.x - pa.x) * (pb.y - pa.y);//AD * AB

	double fa = (pd.x - pc.x) * (pa.y - pc.y) - (pa.x - pc.x) * (pd.y - pc.y);//AC * CD
	double fb = (pd.x - pc.x) * (pb.y - pc.y) - (pb.x - pc.x) * (pd.y - pc.y);//BC * CD

	if (fc * fd <= 0 && fa * fb <= 0)//fc * fd <= 0 ��ʾC,D��ֱ��AB���
		return true;
	else
		return false;
}


bool Intersect(vector<Point> p1, vector<Point> p2)//�ж�����piece�Ƿ��ཻ
{
	if (low_bound(p1) > upper_bound(p2) || upper_bound(p1) < low_bound(p2))
		return false;
	if (left_bound(p1) > right_bound(p2) || right_bound(p1) < left_bound(p2))
		return false;
	for(int i = 0; i < int(p1.size() - 1); i++)
		for (int j = i + 1; j < int(p1.size() - 1); j++)
			for(int k = 0; k < int(p2.size() - 1); k++)
				for (int t = k + 1; t < int(p2.size()); t++)
				{
					if (line_intersect(p1[i], p1[j], p2[k], p2[t]))
						return true;
				}
	
	return false;
}

double D_Function(Point pa, Point pb, Point pc)//D-Function
{
	double result = 0;
	result = (pa.x - pb.x) * (pa.y - pc.y) - (pa.y - pb.y) * (pa.x - pc.x);//��result��ֵΪ���� ���C��AB�ұߣ�������AB��ߡ�

	return result;
}

bool point_in_piece(vector<Point> piece, Point p)//�жϸ����ĵ��Ƿ���piece�ڲ�
{
	if (p.y < low_bound(piece) || p.y > upper_bound(piece))
		return false;
	if (p.x < left_bound(piece) || p.x > right_bound(piece))
		return false;
	for (int i = 0; i < int(piece.size()); i++)
	{
		if (p.x = piece[i].x && p.y == piece[i].y)
			return false;
	}
	for (int i = 0; i < int(piece.size() - 1); i++)
	{
		if (piece[i].x == piece[i + 1].x)
			if (p.x == piece[i].x && p.y > min(piece[i].y, piece[i + 1].y) && p.y < max(piece[i].y, piece[i + 1].y))
				return false;

		if((piece[i + 1].y - piece[i].y) * (p.x - piece[i].x) == (p.y - piece[i].y) * (piece[i + 1].x - piece[i].x))
			if(p.y > min(piece[i].y, piece[i + 1].y) && p.y < max(piece[i].y, piece[i + 1].y))
				return false;
	}
	//����Ϊ�Ե�p��piece�ı߽��ϵļ��

	Point temp;
	temp.x = INFINITY, temp.y = p.y;
	int count_all = 0;
	for (int i = 0; i < int(piece.size() - 1); i++)
	{
		if (line_intersect(piece[i], piece[i + 1], p, temp))
			count_all++;
	}

	for (int i = 0; i < int(piece.size()); i++)
	{
		if (piece[i].y == p.y && piece[i].x > p.x)//
		{
			double D1 = D_Function(p, temp, piece[(i - 1 + int(piece.size())) % int(piece.size())]);
			double D2 = D_Function(p, temp, piece[(i + 1 + int(piece.size())) % int(piece.size())]);
			if ((D1 * D2) < 0)
				count_all++;
		}
	}

	if (count_all % 2 == 1)
		return true;
	else
		return false;
}



//piece������piece��
Point mid_point(Point p1, Point p2)
{
	Point temp;
	temp.x = (p1.x + p2.x) / 2;
	temp.y = (p1.y + p2.y) / 2;
	return temp;
}


Point near_point(Point p, Point p1)
{
	Point temp;
	temp.x = (p.x * 9 + p1.x) / 10;
	temp.y = (p.y * 9 + p1.y) / 10;
	return temp;
}

bool piece_in_piece(vector<Point> p1, vector<Point> p2)
{
	if (low_bound(p1) > upper_bound(p2) || upper_bound(p1) < low_bound(p2))
		return false;
	if (left_bound(p1) > right_bound(p2) || right_bound(p1) < left_bound(p2))
		return false;
	if (Intersect(p1, p2))
		return false;
	//�ȼ���������

	double y_max = max(upper_bound(p1), upper_bound(p2));
	double y_min = min(low_bound(p1), low_bound(p2));
	double x_max = max(right_bound(p1), right_bound(p2));
	double x_min = min(left_bound(p1), left_bound(p2));

	if ((y_max - y_min) * (x_max - x_min) < (area(p1) + area(p2)))
		return true;
	//���ڵ�����if�����Ѿ��ų�������piece�ཻ�����Σ� ����һ��������piece�������ڵľ��ε������С��������piece���֮�ͣ�����piece���а�����ϵ

	double y1 = (upper_bound(p1) + low_bound(p1)) / 2;
	double x1 = (left_bound(p1) + right_bound(p1)) / 2;
	double y2 = (upper_bound(p2) + low_bound(p2)) / 2;
	double x2 = (left_bound(p2) + right_bound(p2)) / 2;
	Point o, p;
	o.x = x1, o.y = y1;
	p.x = x2, o.y = y2;
	
	if ((point_in_piece(p1, o) && point_in_piece(p2, o)) || (point_in_piece(p1, p) && point_in_piece(p2, p)))
		return true;

	//���������Ͻ��ĺ��������������An effective heuristic for the two-dimentional irregular bin packing problem��
	int flag = 1;
	for (int i = 0; i < int(p1.size()); i++)
	{
		if (point_in_piece(p2, p1[i]) && point_in_piece(p2, mid_point(p1[i], p1[(i + 1) % int(p1.size())])) && point_in_piece(p2, near_point(p1[i], p1[(i + 1) % int(p1.size())])) && point_in_piece(p2, near_point(p1[i], p1[(i - 1 + int(p1.size())) % int(p1.size())])))
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return true;

	flag = 1;
	for (int i = 0; i < int(p2.size()); i++)
	{
		if (point_in_piece(p1, p2[i]) && point_in_piece(p1, mid_point(p2[i], p2[(i + 1) % int(p2.size())])) && point_in_piece(p1, near_point(p2[i], p2[(i + 1) % int(p2.size())])) && point_in_piece(p1, near_point(p2[i], p2[(i - 1 + int(p2.size())) % int(p2.size())])))
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return true;

	if (area(p1) == area(p2))
		return true;
	else
		return false;
}


//����һ��piece������������piece�����ʣ�ಿλ
vector<Point> build_left_piece(vector<Point> piece)
{
	vector<Point> result;

	Point p1 = left_upper_point(piece);
	Point p2 = left_low_point(piece);
	Point p3; p3.x = 0, p3.y = p1.y;
	Point p4; p4.x = 0, p4.y = p2.y;

	result.push_back(p3);
	result.push_back(p1);
	result.push_back(p2);
	result.push_back(p4);

	for (int i = 0; i < int(piece.size()); i++)
	{
		if (p1.x == p2.x)
		{
			if (piece[i].x < p1.x)
				result.push_back(piece[i]);
		}

		else if (p1.x < p2.x)
		{
			double k = (p1.y - p2.y) / (p1.x - p2.x);
			double y = k * (piece[i].x - p1.x) + p1.y;
			if (y > piece[i].y)
				result.push_back(piece[i]);
		}

		else
		{
			double k = (p1.y - p2.y) / (p1.x - p2.x);
			double y = k * (piece[i].x - p1.x) + p1.y;
			if (y < piece[i].y)
				result.push_back(piece[i]);
		}
	}

	return result;
}


//�����Ǹ�build�������õ���awsl
Point find_left(vector<Point> p)
{
	Point temp;
	temp.x = 100000, temp.y = 100000;
	for (int i = 0; i < int(p.size()); i++)
	{
		if (p[i].x < temp.x)
			temp = p[i];
		if (p[i].x == temp.x && p[i].y < temp.y)
			temp = p[i];
	}

	return temp;
}


Point find_right(vector<Point> p)
{
	Point temp;
	temp.x = 0, temp.y = 0;
	for (int i = 0; i < int(p.size()); i++)
	{
		if (p[i].x > temp.x)
			temp = p[i];
		if (p[i].x == temp.x && p[i].y < temp.y)
			temp = p[i];
	}

	return temp;
}


//����һ��piece������������piece���·�ʣ�ಿλ
vector<Point> build_low_piece(vector<Point> piece)
{
	vector<Point> result;

	Point p1 = find_left(piece);
	Point p2 = find_right(piece);
	Point p3; p3.x = p1.x, p3.y = 0;
	Point p4; p4.x = p2.x, p4.y = 0;

	result.push_back(p3);
	result.push_back(p1);
	result.push_back(p2);
	result.push_back(p4);

	for (int i = 0; i < int(piece.size()); i++)
	{
		if (p1.y == p2.y)
		{
			if (piece[i].y < p1.y)
				result.push_back(piece[i]);
		}

		else
		{
			double k = (p1.y - p2.y) / (p1.x - p2.x);
			double y = k * (piece[i].x - p1.x) + p1.y;
			if (y > piece[i].y)
				result.push_back(piece[i]);
		}
	}

	return result;
}

//��������ĵ㵽�����߶ε�ˮƽ����, �������߶������Ϊ���� �����߶��Ҳ���Ϊ��
double point_Hdis_segment(Point p, Point pa, Point pb)
{
	if ((p.y < pa.y && p.y < pb.y) || (p.y > pa.y && p.y > pb.y))
		throw("�õ�ˮƽ�޷���������߶�");
	else if (p.y == pa.y && p.y == pb.y && p.x > pa.x && p.x > pb.x)
		return min(p.x - pa.x, p.x - pb.x);
	else if (p.y == pa.y && p.y == pb.y && p.x < pa.x && p.x < pb.x)
		return -min(pa.x - p.x, pb.x - p.x);
	else if (p.y == pa.y && p.y == pb.y)
		return 0;
	else
		return p.x - pa.x + (pa.x - pb.x) * (pa.y - p.y) / (pa.y - pb.y);
}


//��������ĵ㵽�����߶ε���ֱ����,���߶��Ϸ�Ϊ�����·�Ϊ��
double point_Vdis_segment(Point p, Point pa, Point pb)
{
	if ((p.x < pa.x && p.x < pb.x) || (p.x > pa.x && p.x > pb.x))
		throw("�õ���ֱ�޷���������߶�");
	else if (p.x == pa.x && p.x == pb.x && p.y > pa.y && p.y> pb.y)
		return min(p.y - pa.y, p.y - pb.y);
	else if (p.x == pa.x && p.x == pb.x && p.y < pa.y && p.y < pb.y)
		return -min(pa.y - p.y, pb.y - p.y);
	else if (p.y == pa.y && p.y == pb.y)
		return 0;
	else
		return p.y - pa.y - (pa.y - pb.y) * (p.x - pa.x) / (pa.x - pb.x);
}

//����p������pieced�Ķ����е����ֵ
double upper_y(vector<Point> *p)
{
	double y = 0;
	for(int i = 1; i <= Size(p); i++)
		for (int j = 0; j < int(p[i].size()); j++)
		{
			if (p[i][j].y > y)
				y = p[i][j].y;
		}

	return y;
}


double right_x(vector<Point> *p)
{
	double x = 0;
	for (int i = 1; i <= Size(p); i++)
		for (int j = 0; j < int(p[i].size()); j++)
		{
			if (p[i][j].x > x)
				x = p[i][j].x;
		}

	return x;
}