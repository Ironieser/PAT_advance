#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
void toarr(int num,int a[])
{
    int t=num;
    for(int i=3;i>=0;i--){
        a[i]=t%10;
        t/=10;
    }
}
int tonum(int a[])
{
    int num=0;
    for(int i=0;i<4;i++){
        num=10*num+a[i];
    }
    return num;
}
int main()
{
    int a[4]={0},b[4]={0};
    int num,ma,mi;
    scanf("%d",&num);
    int temp=-1;
    //当输入为零时，num！=temp，进行一次输出后停止
    do{
        toarr(num,a);
        toarr(num,b);
        sort(a,a+4);
        mi=tonum(a);
        sort(b,b+4,cmp);
        ma=tonum(b);
        if(temp!=ma-mi){//包含num初始值为0的情况
            printf("%04d - %04d = %04d\n",ma,mi,ma-mi);
            num=ma-mi;
            temp=num;
        }
        else{
            return 0;
        }
    }while(true);
    return 0;
}
