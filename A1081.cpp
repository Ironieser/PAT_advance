#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
//改进，用假分数化简并保存，最后输出时，再化为带分数
struct fraction{
    ll up,down;
    ll num;
}f[200],sum;
ll gcd(ll a,ll b)//求最大公因数
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
fraction f_sum(fraction a,fraction b)//分数求和
{
    a.up=a.up*b.down+b.up*a.down;
    a.down=a.down*b.down;
    a.num+=b.num;
    return a;
}
fraction f_easy(fraction t)//分数化简
{
    if(t.down<0){
        t.down=-t.down;
        t.up=-t.up;
    }
//   if(abs(t.up)>t.down){
    if(abs(t.up)>=t.down){//将分子分母相等情况在这儿处理，就没问题了
        t.num+=t.up/t.down;
        t.up=t.up%t.down;
    }
    ll g=gcd(abs(t.up),abs(t.down));//求分子分母最小公因数
    t.up/=g;
    t.down/=g;
//    if(abs(t.up)==t.down){
///错误点：解决分子分母相等的情况，1/1和-1/1两种情况
//        if(t.up>0)  t.num++;
//        else t.num--;
//        t.up=0;
//    }
    return t;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld/%lld",&f[i].up,&f[i].down);
        f[i].num=0;
    }
    sum.up=0;
    sum.down=1;
    sum.num=0;
    for(int i=0;i<n;i++){
        sum=f_sum(sum,f[i]);
        sum=f_easy(sum);
    }
//    sum=f_easy(sum);
    if(sum.down==1) {
        printf("%lld",sum.num);
    }
    else {
        if(sum.num!=0) printf("%lld ",sum.num);
        printf("%lld/%lld",sum.up,sum.down);
    }
    return 0;
}
