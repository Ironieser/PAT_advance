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
            int e;double c; //e ָ�� , c ϵ��
            scanf("%d%lf",&e,&c);
            if(n[e]<1e-6&&n[e]>-1e-6) count++;  //��ʼ ���������޴����count+1��
//����㣺Ӧ��ϵ����ͺ��ٽ���һ���жϣ��ж��Ƿ������ͺ�ֵΪ��
            n[e]+=c;
//****************************
            if(n[e]<1e-6&&n[e]>-1e-6) count--; // flaot �������ж� ʹ��1e-6
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
