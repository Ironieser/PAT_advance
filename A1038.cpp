#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//*********************************
///���ж��������ܹؼ�
///�����˰��ֵ�����С����ģ�32+321��321+32�����
///a+b<b+a,��Ӧ����a+b �ķ�ʽ����ƴ��
///�˽��ۿ��Ƶ���N������
///�ص㣺ѧ��ʹ��string
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
        s.erase(s.begin());//ȥ��ǰ���0��
    }
    if(s.size()==0) cout<<0;
    else cout<<s;
    return 0;
}
