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
	Triple data[MAX_SIZE];//存储非零元素(从左向右，从上到下，非零元素编号1，2，3......)
	int pos[MAX_ROW];//记录每行第一个非零元素的位置(在data数组中的序号)；若一行全为零，则将第一个元素加入
	int row, col, cnt;//矩阵的行数，列数， 以及非零元素的个数；
};

void SparseMatrixMul(SMatrix M, SMatrix N, SMatrix &result)
{
	int Rtemp[MAX_ROW + 1], temp, Rrow, Nrow, Rcol, i, j;

	//特殊情况
	if (M.col != N.row)//两矩阵不是m*n, n*r型， 无法相乘
	{
		cout << "无法相乘" << endl;
		return;
	}
	if (0 == M.cnt * N.cnt)
		return;
	
	//一般情况
	result.row = M.row;
	result.col = N.col;
	result.cnt = 0;

	for (Rrow = 1; Rrow <= result.row; Rrow++)//一行一行分析
	{
		for (int Rcol = 1; Rcol <= result.col; Rcol++)
		{
			Rtemp[Rcol] = 0;//Rtemp[i]存储的是当前行第i列元素的value值；
		}

		result.pos[Rrow] = result.cnt + 1;
		//确定边界
		if (Rrow < M.row)
			temp = M.pos[Rrow + 1];//下一行的起始位置
		else
			temp = M.cnt + 1;//最后一行拿出来单独处理， 以cnt总元素个数为边界为

		for (i = M.pos[Rrow]; i < temp; i++)
		{
			//对M当前行的每一个非零元
			//找到对应元素在N中的行号，即M中当前元的列号
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

		//将Rtemp中的信息存入到result中
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
data数组中存储的全都是非零元素，
而pos[row+1]是第row+1行中第一个非零元素在data中的位置，
所以它的前一个位置一定是第row行中最后一个非零元素在data中的位置
*/
