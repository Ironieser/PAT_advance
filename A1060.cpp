#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
///��Ҫ�������п��ܳ��ֵ����
///��������ֿ���Ϊ��
//0000123.000123
//000.000��000.000123��0
//˼·Ϊ�����ѧ��������ϵ��
//ͨ��С�����λ�ã�����ָ������
//�ټ��㿪ʼʱ����Ҫȥ��ǰ��0����ȥ����Ľ��
//�����жϣ����a.size()==0,��Ϊ0��
//��a[0]=='.' �� ��ΪС�������,ָ��<0;
//����Ϊ�����������ָ��>0;
////////////////////////////////////////
//ѧϰʹ��string
string getnum(string a)
{
    string t;
    int e=0;//ָ��
    int k=0;//С�����־
    while(a[0]=='0'&&a.size()>0){//ȥ��ǰ��0
        a.erase(a.begin());
    }
    if(a[0]=='.'){//����С��0
        a.erase(a.begin());//ȥ��С����
        while(a[0]=='0'&&a.size()>0){//ȥ��ǰ����
            a.erase(a.begin());
            e--;
        }
    }else{//���ִ���0
        while(a[k]!='.'&&k<a.size()){//Ѱ��С����
            k++;
            e++;
        }
        if(k<a.size()){//�ҵ�С����
            a.erase(a.begin()+k);
        }
    }
    if(a.size()==0){//����Ϊ0
        e=0;
    }
    t+="0.*10^";
    if(a.size()!=0){
        if(a.size()>=n){//�����㹻
            t.insert(t.begin()+2,a.begin(),a.begin()+n);
        }else{//���Ȳ���
            t.insert(t.begin()+2,a.begin(),a.end());
            for(int i=0;i<n-a.size();i++){//β������0
                t.insert(t.begin()+2+a.size(),'0');
            }
        }
    }else{
        for(int i=0;i<n-a.size();i++){
            t.insert(t.begin()+2,'0');
        }
    }
    string str;//һ��Ϊָ������
    do{
        if(e<0){
            t+='-';
            e=-e;
        }
        str+=e%10+'0';
        e/=10;
    }while(e!=0);
    reverse(str.begin(),str.end());
    t+=str;
    return t;
}
int main()
{
    string a,b,x,y;
    cin>>n>>a>>b;
    x=getnum(a);
    y=getnum(b);
    if(x==y){
        cout<<"YES "<<x;
    }else{
        cout<<"NO "<<x<<" "<<y;
    }
    return 0;
}
