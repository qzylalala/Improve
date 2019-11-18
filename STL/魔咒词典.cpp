#include<bits/stdc++.h>

using namespace std;

map<string, string> Dictionary;

int main(){
	char in[105];
	int count, i, n, t;
	count = 0;
	char* p, *q;
	while(gets(in)){
		if(in[0] == '@') 
			break;
		p = strtok(in, "[]");
		q = p;
		p = strtok(NULL, "[]");
		p++;
		Dictionary[p] = q;
		Dictionary[q] = p;
		count++;
	}
	scanf("%d", &n);
	getchar();
	for(i = 0;i < n; i++){
		gets(in);
		p = strtok(in, "[]");
		if(Dictionary.find(p) == Dictionary.end())
			puts("what?");
		else printf("%s\n", Dictionary[p].c_str());
	}
	
	return 0;
}
