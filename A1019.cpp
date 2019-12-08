#include<cstdio>
int main()
{
    int n,b,a[32];
    scanf("%d%d",&n,&b);
    int i=0;
    do
    {
        a[i++]=n%b;
        n=n/b;
    }while(n>0);
    int num=i;
    int flag=1;
    //默认为回文数 解决了边界值 输入为0 的问题
    for(i=0;i<num/2;i++)
    {
        if(a[i]!=a[num-1-i])
        {
            flag=0;break;
        }
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    for(i=num-1;i>=0;i--)
    {
        printf("%d",a[i]);
        if(i!=0) printf(" ");
    }

}
