#include<cstdio>
int main()
{
    double a[3][3],b[3]={0};
    //int flag[3]={0};
//**********little tips************//
    char m[3]={'W','T','L'};
//*******************************//
    for(int i=0;i<3;i++)
    {
        int flag;
        for(int j=0;j<3;j++)
           {
                scanf("%lf",&a[i][j]);
                a[i][j]>b[i]?b[i]=a[i][j],flag=j:1;
           }
        printf("%c ",m[flag]); //每读入一行 便输入 wtl；
    }
//    for(int i=0;i<3;i++)
//    {
//        printf("%c ",m[flag[i]]);
//    }
    double sum=0;
    sum=(b[0]*b[1]*b[2]*0.65-1)*2;
    printf("%.2lf",sum);
}
