#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
///需要分析所有可能出现的情况
///输入的数字可能为：
//0000123.000123
//000.000、000.000123、0
//思路为计算科学记数法的系数
//通过小数点的位置，进行指数计算
//再计算开始时，需要去除前置0；对去除后的结果
//进行判断，如果a.size()==0,则为0；
//若a[0]=='.' ， 则为小于零的数,指数<0;
//否则，为大于零的数，指数>0;
////////////////////////////////////////
//学习使用string
string getnum(string a)
{
    string t;
    int e=0;//指数
    int k=0;//小数点标志
    while(a[0]=='0'&&a.size()>0){//去除前导0
        a.erase(a.begin());
    }
    if(a[0]=='.'){//数字小于0
        a.erase(a.begin());//去除小数点
        while(a[0]=='0'&&a.size()>0){//去除前置零
            a.erase(a.begin());
            e--;
        }
    }else{//数字大于0
        while(a[k]!='.'&&k<a.size()){//寻找小数点
            k++;
            e++;
        }
        if(k<a.size()){//找到小数点
            a.erase(a.begin()+k);
        }
    }
    if(a.size()==0){//数字为0
        e=0;
    }
    t+="0.*10^";
    if(a.size()!=0){
        if(a.size()>=n){//精度足够
            t.insert(t.begin()+2,a.begin(),a.begin()+n);
        }else{//精度不够
            t.insert(t.begin()+2,a.begin(),a.end());
            for(int i=0;i<n-a.size();i++){//尾部补充0
                t.insert(t.begin()+2+a.size(),'0');
            }
        }
    }else{
        for(int i=0;i<n-a.size();i++){
            t.insert(t.begin()+2,'0');
        }
    }
    string str;//一下为指数计算
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
