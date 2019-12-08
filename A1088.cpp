#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct fra{
    ll up,down;
}f[2];
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
fra f_easy(fra a)
{
    if(a.down<0){
        a.down=-a.down;
        a.up=-a.up;
    }
    if(a.up==0) a.down=1;
    int g=gcd(abs(a.up),abs(a.down));
    a.up/=g;
    a.down/=g;
    return a;
}
fra f_plus(fra a,fra b)
{
    a.up=a.up*b.down+a.down*b.up;
    a.down=a.down*b.down;
    a=f_easy(a);
    return a;
}
fra f_minu(fra a,fra b)
{
    a.up=a.up*b.down-b.up*a.down;
    a.down=a.down*b.down;
    a=f_easy(a);
    return a;
}
fra f_multi(fra a,fra b)
{
    a.up*=b.up;
    a.down*=b.down;
    a=f_easy(a);
    return a;
}
fra f_div(fra a,fra b)
{
    a.up*=b.down;
    a.down*=b.up;
    a=f_easy(a);
    return a;
}
void f_out(fra a)
{
    a=f_easy(a);
    if(a.down==1) {
        if(a.up>=0)
            printf("%lld",a.up);
        else{
            printf("(%lld)",a.up);
        }
    }
    else if(abs(a.up)>abs(a.down)){
        if(a.up>=0)
            printf("%lld %lld/%lld",a.up/a.down,a.up%a.down,a.down);
        else
            printf("(%lld %lld/%lld)",a.up/a.down,abs(a.up)%a.down,a.down);
    }
    else{
        if(a.up>=0)
            printf("%lld/%lld",a.up,a.down);
        else
            printf("(%lld/%lld)",a.up,a.down);
    }
}
int main()
{
    for(int i=0;i<2;i++){
        scanf("%lld/%lld",&f[i].up,&f[i].down);
    }
    fra t;
    f_out(f[0]);
    printf(" + ");
    f_out(f[1]);
    printf(" = ");
    t=f_plus(f[0],f[1]);
    f_out(t);
    printf("\n");

    f_out(f[0]);
    printf(" - ");
    f_out(f[1]);
    printf(" = ");
    t=f_minu(f[0],f[1]);
    f_out(t);
    printf("\n");

    f_out(f[0]);
    printf(" * ");
    f_out(f[1]);
    printf(" = ");
    t=f_multi(f[0],f[1]);
    f_out(t);
    printf("\n");

    f_out(f[0]);
    printf(" / ");
    f_out(f[1]);
    printf(" = ");
    if(f[1].up==0){
        printf("Inf");
    }else{
    t=f_div(f[0],f[1]);
    f_out(t);
    }
    return 0;
}
