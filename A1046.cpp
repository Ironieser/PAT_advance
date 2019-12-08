#include<cstdio>
int main()
{
    int N,n[100000]={0};
    scanf("%d",&N);
    int sum=0;
     for(int i=2;i<=N+1;i++)
    {
        scanf("%d",&n[i]);
        n[i]+=n[i-1];
    }
    sum=n[N+1];
    int M;
    scanf("%d",&M);
    while(M--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int temp=a;
        a<b?a:(a=b,b=temp);
        int sum1,sum2;
        sum1=n[b]-n[a];
        sum2=sum-sum1;
        printf("%d\n",sum1<sum2?sum1:sum2);
    }
/////*********下面的算法，最坏情况遍历总次数为10^5 x 10^4 导致超时*********************
//    for(int i=1;i<=N;i++)
//        {
//            scanf("%d",&n[i]);
//            sum+=n[i];
//        }
//    int M;
//    scanf("%d",&M);
//    while(M--)
//    {
//        int a,b;
//        scanf("%d %d",&a,&b);
//        int temp=a;
//        a<b?a:(a=b,b=temp);
//        int sum1=0,sum2=0;
//        for(int i=a;i<b;i++)
//        {
//            sum1+=n[i];
//        }
//        sum2=sum-sum1;
////        for(int i=b;i%N!=a;i++)
////        {
////            if(i>N) i=i%N;
////            sum2+=n[i];
////        }
//        printf("%d\n",sum1<sum2?sum1:sum2);
//
//    }
    return 0;
}
