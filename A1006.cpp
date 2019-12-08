//错误点：if后的判断条件写错...
//可优化算法：将录入时间转化为秒进行存储
//s=3600*h+60*m+s;
#include<cstdio>
struct Per
{
    char num[20];
    int ih,im,is,oh,om,os;
}unlock,lock,temp;
bool early(Per &A,Per &B);
bool later(Per &A,Per &B);
int main()
{
    int m;
    scanf("%d",&m);
    unlock.ih=24,unlock.im=60,unlock.is=60;
    lock.oh=lock.om=lock.os=0;
    if(!m) {printf("0");return 0;}
    while(m--)
    {
        scanf("%s %d:%d:%d",temp.num,&temp.ih,&temp.im,&temp.is);
        scanf("%d:%d:%d",&temp.oh,&temp.om,&temp.os);
        if(early(temp,unlock))
            unlock=temp;
        if(later(temp,lock))
            lock=temp;
    }
    printf("%s %s\n",unlock.num,lock.num);
    return 0;
}
bool early(Per &A,Per &B)
{
    if(A.ih!=B.ih)  return A.ih<B.ih;
    if(A.im!=B.im)  return A.im<B.im;
    return A.is<B.is;
}

bool later(Per &A,Per &B)
{
    if(A.oh!=B.oh) return A.oh>B.oh;
    if(A.om!=B.om)return A.om>B.om;
    return A.os>B.os;
}
