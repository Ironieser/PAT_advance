#include<cstdio>
#include<cmath>
int rev(int a,int d)
{
    int t[100000]={0};
    ///错误点：保存逆序数组的大小
    int num=0;
    do{
        t[num++]=a%d;
        a/=d;
    }while(a);
    int ans=0;
    for(int i=0;i<num;i++){
        ans=ans*d+t[i];
    }
    return ans;
}
bool isprime(int a)
{
    if(a<=1) return false;
//    for(int i=2;i*i<=a;i++){
    for(int i=2;i<=(int)sqrt(1.0*a);i++){
        if(a%i==0)
            return false;
    }
    return true;
}
int main()
{
    do{
        int n,d;
        scanf("%d",&n);
        if(n<0) break;
        else {
            scanf("%d",&d);
        }
        int a=n;
        int b=rev(n,d);
        if(isprime(a)&&isprime(b)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }while(true);
    return 0;
}
