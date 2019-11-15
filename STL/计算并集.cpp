#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	
	while(scanf("%d %d", &n, &m) != EOF)
	{
		int temp;
		set<int> st;
		for(int i = 1; i <= m+n; i++)
		{
			scanf("%d", &temp);
			st.insert(temp);	
		}
		set<int>::iterator iter;
		for(iter = st.begin(); iter != st.end(); iter++)
		{
			if(++iter == st.end())
			{
				cout << *(--iter )<< endl;
			}
			else
			{
				iter--;
				cout << *iter << " ";
			}
		}
	}
	
	return 0;
}
