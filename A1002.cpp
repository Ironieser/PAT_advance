#include<cstdio>
const int N=1000;

int main()
{
    double n[N+1]={0};
    int flag=2;
    int count=0;
    while(flag--)
    {
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            int e;double c; //e 指数 , c 系数
            scanf("%d%lf",&e,&c);
            if(n[e]<1e-6&&n[e]>-1e-6) count++;  //初始 数组中若无此项，则count+1；
//错误点：应在系数求和后再进行一次判断，判断是否相加求和后值为零
            n[e]+=c;
//****************************
            if(n[e]<1e-6&&n[e]>-1e-6) count--; // flaot 型与零判断 使用1e-6
//****************************
        }
    }
    printf("%d",count);
    for(int i=N;i>=0;i--)
    {
        if(n[i])
            printf(" %d %.1lf",i,n[i]);
    }
    return 0;
}
