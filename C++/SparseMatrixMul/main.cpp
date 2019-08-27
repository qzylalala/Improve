#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define Elemtype double
#define MAX_SIZE 1500
#define MAX_ROW 1500

using namespace std;


class Triple
{
public:
	int row, col;
	Elemtype value;
};

class SMatrix
{
public:
	Triple data[MAX_SIZE];//�洢����Ԫ��(�������ң����ϵ��£�����Ԫ�ر��1��2��3......)
	int pos[MAX_ROW];//��¼ÿ�е�һ������Ԫ�ص�λ��(��data�����е����)����һ��ȫΪ�㣬�򽫵�һ��Ԫ�ؼ���
	int row, col, cnt;//����������������� �Լ�����Ԫ�صĸ�����
};

void SparseMatrixMul(SMatrix M, SMatrix N, SMatrix &result)
{
	int Rtemp[MAX_ROW + 1], temp, Rrow, Nrow, Rcol, i, j;

	//�������
	if (M.col != N.row)//��������m*n, n*r�ͣ� �޷����
	{
		cout << "�޷����" << endl;
		return;
	}
	if (0 == M.cnt * N.cnt)
		return;
	
	//һ�����
	result.row = M.row;
	result.col = N.col;
	result.cnt = 0;

	for (Rrow = 1; Rrow <= result.row; Rrow++)//һ��һ�з���
	{
		for (int Rcol = 1; Rcol <= result.col; Rcol++)
		{
			Rtemp[Rcol] = 0;//Rtemp[i]�洢���ǵ�ǰ�е�i��Ԫ�ص�valueֵ��
		}

		result.pos[Rrow] = result.cnt + 1;
		//ȷ���߽�
		if (Rrow < M.row)
			temp = M.pos[Rrow + 1];//��һ�е���ʼλ��
		else
			temp = M.cnt + 1;//���һ���ó����������� ��cnt��Ԫ�ظ���Ϊ�߽�Ϊ

		for (i = M.pos[Rrow]; i < temp; i++)
		{
			//��M��ǰ�е�ÿһ������Ԫ
			//�ҵ���ӦԪ����N�е��кţ���M�е�ǰԪ���к�
			Nrow = M.data[i].col;
			if (Nrow < N.row)
				j = N.pos[Nrow + 1];
			else
				j = N.cnt + 1;

			for (int p = N.pos[Nrow]; p < j; p++)
			{
				Rcol = N.data[p].col;
				Rtemp[Rcol] += M.data[i].value * N.data[p].value;
			}
		}

		//��Rtemp�е���Ϣ���뵽result��
		for (Rcol = 1; Rcol <= result.col; Rcol++)
		{
			if (0 != Rtemp[Rcol])
				if (++result.cnt > MAX_SIZE)
					return;
			result.data[result.cnt].row = Rrow;
			result.data[result.cnt].col = Rcol;
			result.data[result.cnt].value = Rtemp[Rcol];
		}
	}
}

/*
data�����д洢��ȫ���Ƿ���Ԫ�أ�
��pos[row+1]�ǵ�row+1���е�һ������Ԫ����data�е�λ�ã�
��������ǰһ��λ��һ���ǵ�row�������һ������Ԫ����data�е�λ��
*/
