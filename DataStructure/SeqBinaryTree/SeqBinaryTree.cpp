#include "BinaryTree.h"

void InitTree(BiTree T)
{
	int i;
	for (i = 0; i < Max_Node_size; i++)
	{
		T[i] = '\0';
	}
}

void ClearBiTree(BiTree T)
{
	int i;
	for (i = 0; i < Max_Node_size; i++)
	{
		T[i] = '\0';
	}
}

bool BiTreeEmpty(BiTree T)
{
	return T[0] == '\0' ? true : false;
}

bool CreateBiTree_Pre(BiTree T, int i)
{
	char ch;
	scanf("%c", &ch);
	if (ch == ' ')
		T[i] = '\0';
	else
	{
		T[i] = ch;
		CreateBiTree_Pre(T, 2*i + 1);
		CreateBiTree_Pre(T, 2*i + 2);
	}

	return true;
}

int BiTreeLength(BiTree T)
{
	int len;
	for (len = Max_Node_size; len - 1 >= 0; len--)
	{
		if (T[len - 1] != '\0')
			break;
	}

	return len;
}

int BiTreeDepth(BiTree T)
{
	int depth = 0;
	while ((int)pow(2, depth) - 1 < BiTreeLength(T))
		depth++;
	
	return depth;
}

bool Root(BiTree T, Type *e)
{
	if (BiTreeEmpty(T))
		return false;

	*e = T[0];
	
	return true;
}

Type Value(BiTree T, Position s)
{
	int i = (int)pow(2, s.depth - 1) + s.order - 2;

	return T[i];
}

bool Assign(BiTree T, Position s, Type value)
{
	int i = (int)pow(2, s.depth - 1) + s.order - 2;
	if (value == '\0' && (T[2 * i + 1] != '\0' || T[2 * i + 2] != '\0'))
		return false;
	else if (value != '\0' && T[(i + 1) / 2 - 1] == '\0')
		return false;
	else
		T[i] = value;

	return true;
}

Type Parent(BiTree T, Type e)
{
	int i;
	if (T[0] != '\0')
	{
		for (i = 0; i < Max_Node_size; i++)
		{
			if (T[i] == e)
				return T[(i + 1) / 2 - 1];
		}
	}
}

Type LeftChild(BiTree T, Type e)
{
	int i;
	if (T[0] == '\0')
		return '\0';
	for (i = 0; i < Max_Node_size; i++)
	{
		if (T[i] == e)
			return T[2 * i + 1];
	}

	return '\0';
}

Type RightChild(BiTree T, Type e)
{
	int i;
	if (T[0] == '\0')
		return '\0';
	for (i = 0; i < Max_Node_size; i++)
	{
		if (T[i] == e)
			return T[2 * i + 2];
	}

	return '\0';
}

Type LeftSibling(BiTree T, Type e)
{
	int i;
	if (T[0] == '\0')
		return '\0';
	for (i = 0; i < Max_Node_size; i++)
	{
		if (i%2 == 0 && T[i] == e)
			return T[i - 1];
	}

	return '\0';
}

Type RightSibling(BiTree T, Type e)
{
	int i;
	if (T[0] == '\0')
		return '\0';
	for (i = 0; i < Max_Node_size; i++)
	{
		if (i % 2 == 1 && T[i] == e)
			return T[i + 1];
	}

	return '\0';
}

void LevelOrderTraverse(BiTree T)
{
	int len = BiTreeLength(T);
	for (int = 0; i < len; i++)
	{
		if (T[i] != '\0')
			Visit(T[i]);//此处为伪代码
	}
}

void PreOrderTraverse(BiTree T, int i)
{
	if (T[i] != '\0')
	{
		Visit(T[i]);
		PreOrderTraverse(T, 2 * i + 1);
		PreOrderTraverse(T, 2 * i + 2);
	}
}

void InOrderTraverse(BiTree T, int i)
{
	if (T[i] != '\0')
	{
		PreOrderTraverse(T, 2 * i + 1);
		Visit(T[i]);
		PreOrderTraverse(T, 2 * i + 2);
	}
}

void PostOrderTraverse(BiTree T, int i)
{
	if (T[i] != '\0')
	{
		PreOrderTraverse(T, 2 * i + 1);
		PreOrderTraverse(T, 2 * i + 2);
		Visit(T[i]);
	}
}

void Print(BiTree T)
{
	int i, j, level;
	char tmp[Max_Node_size][Max_Node_size] = {};

	level = BiTreeDepth(T);

	for (i = 1; i <= level; i++)
		for (j = 1; j < 2 * (int)pow(2, level - 1); j++)
			tmp[i - 1][(int)pow(2, i - 1) + (j - 1)*(int)pow(2, level - i + 1) - 1] = T[(int)pow(2, i - 1) - 1 + j - 1];//将二叉树存储在二阶数组tmp[][]中
	for (i = 0; i < level; i++)
	{
		for (j = 0; j < 2 * (int)pow(2, level - 1) - 1; j++)
		{
			if (tmp[i][j] != '\0')
				std::cout << tmp[i][j];
			else
				std::cout << " ";
		}
		std::cout << "\n";//输出操作
	}
}