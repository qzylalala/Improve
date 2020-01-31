#include<bits/stdc++.h>
#include<regex>

using namespace std;

int main(){
	int n,m;
    vector<pair<regex,string>> ve = {{regex("<int>"),"([0-9]+)"},
			                         {regex("<str>"),"([^/]+)"},
			                         {regex("<path>"),"(.+)"}};
    vector<pair<regex,string>> rules;
    scanf("%d %d", &n, &m);
    string p, r;
    for(int i = 1; i <= n; i++){
        cin >> p >> r;
		for(auto j:ve){
	    	p = regex_replace(p, j.first, j.second);
		}
	    rules.push_back({regex(p), r});
	}
	string s;
	smatch result;
	for(int i = 1;i <= m; i++){
	    cin >> s;
	    int id = 0;
	    for(auto j:rules){
		if(regex_match(s, result, j.first)){
		    id = 1;
		    cout << j.second;
		    for(int k = 1;k <= result.size(); k++){
			int flag = 0;
			string s = result[k];
			for(int h = 0; h < s.length(); h++){
			    if(!s[h]){
				flag=1;
				break;
			    }
			}
			if(!flag){
			    while(s[0] == '0'){
			    s.erase(0,1);
			    }
			}
			cout<<" "<<s;
		    }
		cout<<endl;
		break;
	    }
        }
	if(!id) cout<<"404"<<endl;
    }
    return 0;
}
