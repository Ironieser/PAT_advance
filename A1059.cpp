#include<cstdio>
#include<cmath>
const int maxn=1000;
///经测试，最大的n不超过10^6
int prime[maxn];
int pnum;
int p[maxn]={false};
struct factors{//factors
    int x;
    int y;
}f[20];

//bool isprime(int a)
//{
//    if(a<=1) return false;
//    for(int i=0;i<(int)sqrt(1.0*a);i++){
//        if(a%i==0) return false;
//    }
//    return true;
//}
void find_prime()
{//使用筛选法，不需要书写isprime函数
    for(int i=2;i<maxn;i++){
        if(!p[i]){
            prime[pnum++]=i;
            for(int j=i+i;j<maxn;j+=i){
                p[j]=true;
            }
        }
    }
}

int main()
{
    find_prime();
    int n;
    scanf("%d",&n);
    int t=n;
    int num=0;
    if(n==1){
//错误点：漏判n==1 的情况，
//情况需要专门进行判断输出
        f[num].x=1;
        f[num++].y=1;
    }else{
        for(int i=0;prime[i]<=(int)sqrt(1.0*n)&&n>0;i++){
            if(n%prime[i]==0){
                f[num].x=prime[i];
                f[num].y=0;
                while(n%prime[i]==0){
                    f[num].y++;
                    n/=prime[i];
                }
                num++;
            }
        }
    }
    if(n!=1){
        f[num].x=n;
        f[num].y++;
        num++;
    }
    printf("%d=",t);
    for(int i=0;i<num;i++){
        if(i!=0) printf("*");
        printf("%d",f[i].x);
        if(f[i].y>1)
            printf("^%d",f[i].y);
    }
    return 0;
}
