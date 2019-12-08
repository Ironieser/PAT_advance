#include<cstdio>
int main()
{

//    int a,b,c;
//    a=-2147483647;
//    b=-2147483647;
//    c=-214748364;
//    printf("%d\n",a+b>c);
//    printf("%d\n",a-c>-b);
    int n;
    scanf("%d",&n);
//    for(int i=1;i<=n;i++)
//    {
//        long long a,b,c;
//        int flag=0;
//        scanf("%lld %lld %lld",&a,&b,&c);
//        long long temp;
//        temp=a+b;
//        if(a>0&&b>0&&temp<0)
//        {
//            flag=1;
////            if(temp<a&&temp<b)
////                flag=1;
////            else
////                if(temp>c)
////                    flag=1;
////                else
////                    flag=0;
//        }
//        else if(a<0&&b<0)
//        {
//            if(temp>a&&temp>b)
//                flag=0;
//            else  if(temp>c)
//                flag=1;
//            else
//                flag=0;
//        }
//        else if(temp>c)
//        {
//            flag=1;
//        }
//        else
//            flag=0;
//        if(flag)
//            printf("Case #%d: true\n",i);
//        else
//            printf("Case #%d: false\n",i);
//    }
    for(int i=1;i<=n;i++)
    {
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        int flag=0;
////*******************************
        if(a>0&&b>0)
        {
            if(c<=0||a-c>-b)
                flag=1;
        }
        else if(a<0&&b<0)
        {

           if(c<0&&a-c>-b&&b!=-9223372036854775808)
                flag=1;
        }
        else if(a+b>c)
            flag=1;
        else
            flag=0;
////********************************
        if(flag)
            printf("Case #%d: true\n",i);
        else
            printf("Case #%d: false\n",i);
    }
    return 0;
}
