#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		string a, b;
		cin >> a >> b;
		int count = 0; 
		int position = b.find(a, 0);//����a�������״�ƥ���λ�ã���ƥ��ʧ�ܣ�����npos
		while(position != string::npos)
		{
			count++;
			position = b.find(a, position + 1);
		}
		cout << count << endl;
	}
	
	return 0;
}
