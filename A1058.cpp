#include<cstdio>
int main()
{
    int a[3],b[3]={0};
    int i=2;
    while(i--)
    {
        scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
        b[0]+=a[0];
        b[1]+=a[1];
        b[2]+=a[2];
    }
    if(b[2]>=29)//±ß½çÖµÅÐ¶Ï >=
    {
        b[1]++;b[2]-=29;
    }
    if(b[1]>=17)
    {
        b[0]++;
        b[1]-=17;
    }
    printf("%d.%d.%d",b[0],b[1],b[2]);
    return 0;
}
