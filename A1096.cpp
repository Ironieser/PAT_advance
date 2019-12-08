#include<cstdio>
#include<cmath>
typedef long long ll;
int main()
{
    ll n;
    scanf("%lld",&n);
    ll maxlen=0,ans;
    ll a,t,len,maxans;
    for(ll i=2;i<=(ll)sqrt(1.0*n);i++){
        ans=1;
        len=0;
        t=i;
        int temp=i;
        while(n%(temp*ans)==0){
        //错误点：未设置变量temp时
        //在循环体内错误使用变量i，使遍历出错
            len++;
            ans=ans*temp;
            temp++;
        }
        if(len>maxlen){
            maxlen=len;
            maxans=ans;
            a=t;
        }
    }
    if(maxlen==0){
            printf("1\n%lld",n);
        return 0;
    }
    printf("%lld\n",maxlen);
    for(ll i=0;i<maxlen;i++){
        if(i!=0) printf("*");
        printf("%lld",i+a);
    }
    return 0;
}
