#include<cstdio>
#include<cstring>
//��С������Ϊ0.00001 ����ʱ���򱣴�ֻ��Ϊ1�����ִ���
int main()
{
//    char fu1,fu2;
//    scanf("%c",&fu1);
//    int a,b,c;
//    //a ���� �� bС����cָ��
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
    if(exp==0)//ָ��Ϊ0
        for(int i=1;i<e;i++)
            printf("%c",str[i]);
    else if(str[e+1]=='+')//ָ��Ϊ��
    {
        int num=1;
        for(int i=1;i<e&&i<exp+3;i++,num++)
        {
            if(str[i]=='.')
                continue;
            printf("%c",str[i]);

        }
        if(num==e)//С�����ֳ���С��ָ��
        {
            for(int i=e;i<exp+3;i++)
                printf("0");
        }
        else//С�����ֳ��ȴ���ָ��
        {
            printf(".");
            for(int i=exp+3;i<e;i++)
                printf("%c",str[i]);
        }
    }
    else //ָ��Ϊ��
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
