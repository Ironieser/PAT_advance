#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
//***************************
///分区块进行代码书写，先完成主函数，再去写子函数
///合理使用Map进行代码编写，
//*************************
using namespace std;
typedef long long LL;
LL inf=(1LL<<63)-1;//1LL中LL为long long 的尾缀标记，将1转换为LL型
LL Map[256];

void ForMap() //Map 初始化
{
    for(char c='0';c<='9';c++){
        Map[c]=c-'0';
    }
    for(char c='a';c<='z';c++){
        Map[c]=c-'a'+10;
    }
}
LL To_d(string N,LL radix,LL val)//转化为10进制的数
{
    LL num=0;
    for(int i=0;i<N.size();i++){
        num=num*radix+Map[N[i]];
        if(num<0||num>val) return -1;
    }
    return num;
}
int  findlargeDigit(string N)//求最大数位
{
    int  t=-1;
    for(int i=0;i<N.size();i++){
        if(Map[N[i]]>t) t=Map[N[i]];
    }
    return t+1;//最大数位+1；
}
int cmp(string N,LL radix ,LL val)
{
    LL num=To_d(N,radix,val);
    if(num==-1) return 1;
    else if(num==val) return 0;
    else return -1;
}
LL binarySearch(string N,LL left ,LL right , LL val)
{
    LL mid;
    while(left<=right){
        mid=(right+left)/2;
        int flag=cmp(N,mid,val);
        if(flag==0) return mid;
        else if(flag==-1) left=mid+1;
        else right = mid - 1;
    }
    return -1;
}
int main()
{
    string  n1,n2;
    int tag,radix;
    LL num=0;
    cin>>n1>>n2>>tag>>radix;
    if(tag==2){swap(n1,n2);}
    ForMap();
    num=To_d(n1,radix,inf);
    LL low=findlargeDigit(n2);
    LL high=max(low,num);
    LL flag=binarySearch(n2,low,high,num);
    if(flag==-1) printf("Impossible");
    else printf("%lld",flag);
}
