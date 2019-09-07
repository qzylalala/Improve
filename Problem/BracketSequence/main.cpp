#include<iostream>
#include<string>
using namespace std;

int d[100][100]; //d[i][j]��ʾ�����ַ������±�i���±�j������Ҫ�ӵ������� 
int c[100][100] = { -1 }; //c[i][j]��ʾ���±�i���±�j���Ӵ��ָ���±꣬-1��ʾ���ָ� 
int len; //�������Ŵ��ĳ��� 
string s; //��������Ŵ� 


void dp()
{
	int i, j, k, l;
	int min;

	for (i = 0; i < len; i++) d[i][i] = 1;

	for (l = 1; l < len; ++l)// lΪ�Ӷγ���,�Ӷ����Ա�֤d[i][j]�������Ҫ�õ�����δ����ʼ��������
		for (i = 0; i + l < len; ++i) //iΪ�Ӷε����
		{
			j = i + l;
			min = d[i][i] + d[i + 1][j];
			c[i][j] = i;
			for (k = i + 1; k < j; k++)
			{
				if (d[i][k] + d[k + 1][j] < min)
				{
					min = d[i][k] + d[k + 1][j];
					c[i][j] = k;
				}
			}
			d[i][j] = min;

			if (s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']')//��β��Ӧ�ſ���ʹc[i][j]ȡ-1
			{
				if (d[i + 1][j - 1] < min)//������ʵ���и�Сbug��,��j=i+1ʱd[1][0]��δ����ʼ���ģ���������print�ᵥ�����������������Ӱ�������
				{
					d[i][j] = d[i + 1][j - 1];
					c[i][j] = -1;
				}
			}
		}
}


void print(int i, int j) //��ӡ��� 
{
	if (i > j) return;
	if (i == j)
	{
		if (s[i] == '(' || s[i] == ')') cout << "()";
		else cout << "[]";
	}
	else
	{
		if (c[i][j] >= 0) //��i��j��c[i][j]���ָ� 
		{
			print(i, c[i][j]);
			print(c[i][j] + 1, j);
		}
		else//c[i][j]Ϊ-1ʱ����β�ض��Ƕ�Ӧ��
		{
			if (s[i] == '(')
			{
				cout << "(";
				print(i + 1, j - 1);
				cout << ")";
			}
			else
			{
				cout << "[";
				print(i + 1, j - 1);
				cout << "]";
			}
		}
	}
}

int main()
{
	getline(cin, s); //������������ 

	len = s.size();
	dp();
	print(0, len - 1);
	cout << endl;

	system("pause");
	return 0;
}