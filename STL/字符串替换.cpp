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
            s.replace(flag, 3, s2); //����� 3 Ϊ s1 �ĳ��� 
            // string &replace(size_t pos,size_t len,const &str)���滻λ��(pos����len���ַ�) 
            flag = s.find(s1, flag + 1);
        }
        cout << s << endl;
    }
    return 0;
}            
