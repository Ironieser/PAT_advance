#include<cstdio>
const int N=1000;
int main()
{
    double A1[N+1]={0};
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int e; double c;
        scanf("%d%lf",&e,&c);
        A1[e]=c;
    }
    double A2[2*N+1]={0};
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int e;double c;
        scanf("%d%lf",&e,&c);
        for(int j=0;j<=N;j++)
        {
            A2[e+j]+=c*A1[j];
        }

    }
    int count=0;
    for(int i=0;i<=2*N;i++)
    {
        if(A2[i]>1e-6||A2[i]<-1e-6) count++;
    }
    printf("%d",count);
    for(int i=2*N;i>=0;i--)
    {
        if(A2[i]>1e-6||A2[i]<-1e-6)
            printf(" %d %.1lf",i,A2[i]);
    }
    return 0;
}
