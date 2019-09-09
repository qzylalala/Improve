#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n = 0;
int* pArr = NULL;

void handle(const int index, stack<int> s, vector<int> v)
{
	//对于每一个待处理的数字，先处理栈里面的，再处理这个数字
	for (int i = s.size(); i >= 0; i--)
	{
		//栈里面的数字可以出来 [0个, 全部]，出来的就放到了vector里面待输出了
		stack<int> sTemp(s);
		vector<int> vTemp(v);

		//从栈里面出 i 个到队列里面去
		for (int j = 1; j <= i; j++)
		{
			int top = sTemp.top();
			sTemp.pop();
			vTemp.push_back(top);
		}

		//再处理这个，把它放到栈顶
		sTemp.push(pArr[index]);

		if (n - 1 == index)
		{
			//输出结果
			static bool isFirst = true;
			vector<int> vRes;
			if (!isFirst)
				cout << endl;

			for (int i = 0; i < vTemp.size(); i++)
				vRes.push_back(vTemp[i]);

			while (!sTemp.empty())
			{
				int top = sTemp.top();
				sTemp.pop();
				vRes.push_back(top);
			}

			int i = 0;
			for (i = 0; i < vRes.size() - 1; i++)
				cout << vRes[i] << " ";
			cout << vRes[i];
			isFirst = false;
		}
		else
		{
			//递归处理
			handle(index + 1, sTemp, vTemp);
		}
	}
}

int main()
{
	cin >> n;
	pArr = new int[n];

	for (int i = 0; i < n; i++)
		//cin >> pArr[i];
		pArr[i] = i + 1;//默认按1 2 3.....n进站

	stack<int> s;
	vector<int> v;
	handle(0, s, v);

	delete[] pArr;

	system("pause");
	return 0;
}