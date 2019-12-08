#include<cstdio>
#include<cstring>
//当小数部分为0.00001 类似时，则保存只能为1，出现错误
int main()
{
//    char fu1,fu2;
//    scanf("%c",&fu1);
//    int a,b,c;
//    //a 整数 ， b小数，c指数
//    scanf("%d.%dE%c%d",&a,&b,&fu2,&c);
//    int d[20000];
//    int leng=0,bb=b;
//    if(a==0&&b==0)
//    {
//        printf("0");
//        return 0;
//    }
//    do{
//        d[leng++]=bb%10;
//        bb/=10;
//    }while(bb>0);
//    if(fu1=='-')
//        printf("-");
//    if(fu2=='-')
//    {
//        printf("0.");
//        while(--c)
//        {
//            printf("0");
//        }
//        printf("%d%d",a,b);
//    }
//    else
//    {
//        if(a>0)
//            printf("%d",a);
//        int i=leng-1,j=0;
//        for(i=leng-1,j=0;i>=0&&j<c;i--,j++)
//            printf("%d",d[i]);
//        if(i<0)
//        {
//            for(;j<c;j++)
//                printf("0");
//        }
//        else
//        {
//            printf(".");
//            for(;i>=0;i--)
//                printf("%d",d[i]);
//        }
//
//    }
    char str[10005];int leng;
    fgets(str,10005,stdin);
    leng=strlen(str)-1;
    if(str[0]=='-')
        printf("-");
    int e=0;
    while(str[e]!='E')
        e++;
    int exp=0;
    for(int i=e+2;i<leng;i++)// e =='E' ; e+1=='-'||'+'
    {
        exp=10*exp+str[i]-'0';
    }
    if(exp==0)//指数为0
        for(int i=1;i<e;i++)
            printf("%c",str[i]);
    else if(str[e+1]=='+')//指数为正
    {
        int num=1;
        for(int i=1;i<e&&i<exp+3;i++,num++)
        {
            if(str[i]=='.')
                continue;
            printf("%c",str[i]);

        }
        if(num==e)//小数部分长度小于指数
        {
            for(int i=e;i<exp+3;i++)
                printf("0");
        }
        else//小数部分长度大于指数
        {
            printf(".");
            for(int i=exp+3;i<e;i++)
                printf("%c",str[i]);
        }
    }
    else //指数为负
    {
        printf("0.");
        for(int i=1
            ;i<exp;i++)
            printf("0");
        for(int i=1;i<e;i++)
        {
            if(str[i]=='.')
                continue;
            printf("%c",str[i]);
        }
    }
    return 0;
}
