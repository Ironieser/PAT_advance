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
        //����㣺δ���ñ���tempʱ
        //��ѭ�����ڴ���ʹ�ñ���i��ʹ��������
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
