#include<cstdio>
int main()
{
    int d[3];
//    char m[3][3];
    for(int i=0;i<3;i++)
        scanf("%d",&d[i]);
    char a[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    printf("#");
    for(int i=0;i<3;i++)
    {
        printf("%c%c",a[d[i]/13],a[d[i]%13]);
    }
    return 0;
}
