#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s, s1, s2;
    while(getline(cin,s))
    {
        int flag;
        s1 = "you";
        s2 = "we";
        flag = s.find(s1,0);
        while(flag != string::npos)
        {
            s.replace(flag, 3, s2); //这里的 3 为 s1 的长度 
            // string &replace(size_t pos,size_t len,const &str)被替换位置(pos往后len个字符) 
            flag = s.find(s1, flag + 1);
        }
        cout << s << endl;
    }
    return 0;
}            
