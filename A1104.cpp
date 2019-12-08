#include<cstdio>
#include<algorithm>
int maxn=100050;
int main()
{
    int n;double sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        double t;
        scanf("%lf",&t);
        sum+=t*i*(n-i+1);
    }
    printf("%.2lf",sum);
    return 0;
}
///**********************
///遍历算法，会超时
///**********************
//int maxn=100050;
//int main()
//{
//    int n;double a[maxn];
//    scanf("%d",&n);
//    double t;
//    for(int i=0;i<n;i++){
//        scanf("%lf",&t);
//        if(i>0) a[i]=a[i-1]+t;
//        else a[i]=t;
//    }
//    double sum=0;
//    for(int i=0;i<n;i++){
//        for(int j=i;j<n;j++){
//            if(i>0) sum+=a[j]-a[i-1];
//            else sum+=a[j];
//        }
//    }
//    printf("%.2lf",sum);
//    return 0;
//}
