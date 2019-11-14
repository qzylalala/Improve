#include<bits/stdc++.h>


#define max_num 1001

using namespace std;


typedef struct{
	int num;
	int length;
	int width;
}rectangle;
rectangle rec[max_num];

bool cmp(rectangle a,rectangle b)
{
	if(a.num != b.num)
	{
		return a.num < b.num;
	}
	
	else if(a.length != b.length)
	{
		return a.length < b.length;
	}
	
	else if(a.width != b.width)
	{
		return a.width < b.width; 
	}
}

bool isEqual(rectangle x,rectangle y)
{
	if(x.num ==y.num && x.length == y.length && x.width == y.width)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

int main()
{
	int n;
	cin >> n;
	
	while(n--)
	{
		int m;
		cin >> m;
		
		for(int i = 1; i <= m; i++)
		{
			cin >> rec[i].num >> rec[i].length >> rec[i].width;
			if(rec[i].length < rec[i].width)
			{
				int temp = rec[i].length;
				rec[i].length = rec[i].width;
				rec[i].width = temp;
			}
		}
		
		sort(rec, rec + m, cmp);
		
		for(int i = 1; i <= m; i++)
		{
			if(!isEqual(rec[i], rec[i+1]))
			{
				printf("%d %d %d\n",rec[i].num, rec[i].length,rec[i].width);
			}
		}
	}
	
	return 0;
}
