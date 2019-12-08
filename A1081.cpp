#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
//�Ľ����üٷ������򲢱��棬������ʱ���ٻ�Ϊ������
struct fraction{
    ll up,down;
    ll num;
}f[200],sum;
ll gcd(ll a,ll b)//���������
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
fraction f_sum(fraction a,fraction b)//�������
{
    a.up=a.up*b.down+b.up*a.down;
    a.down=a.down*b.down;
    a.num+=b.num;
    return a;
}
fraction f_easy(fraction t)//��������
{
    if(t.down<0){
        t.down=-t.down;
        t.up=-t.up;
    }
//   if(abs(t.up)>t.down){
    if(abs(t.up)>=t.down){//�����ӷ�ĸ�����������������û������
        t.num+=t.up/t.down;
        t.up=t.up%t.down;
    }
    ll g=gcd(abs(t.up),abs(t.down));//����ӷ�ĸ��С������
    t.up/=g;
    t.down/=g;
//    if(abs(t.up)==t.down){
///����㣺������ӷ�ĸ��ȵ������1/1��-1/1�������
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
