#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//*********************************
///此判断条件，很关键
///避免了按字典序由小到大的：32+321和321+32的情况
///a+b<b+a,则应按照a+b 的方式进行拼接
///此结论可推导至N的数串
///重点：学会使用string
//**********************************
bool cmp(string a,string b)
{
    return a+b<b+a;
}
//*********************************
int main()
{
    string str[10010],s="\0";
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    sort(str,str+n,cmp);
    for(int i=0;i<n;i++){
        s+=str[i];
    }
    while(s.size()!=0&&s[0]=='0'){
        s.erase(s.begin());//去除前面的0；
    }
    if(s.size()==0) cout<<0;
    else cout<<s;
    return 0;
}
