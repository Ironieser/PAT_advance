#include<cstdio>
#include<algorithm>
using namespace std;
const int maxnc=100500;
const int maxnp=100500;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int nc;//coupon
    int c[maxnc],p[maxnp];
    scanf("%d",&nc);
    for(int i=0;i<nc;i++){
        scanf("%d",&c[i]);
    }
    int np;//product
    scanf("%d",&np);
    for(int i=0;i<np;i++){
        scanf("%d",&p[i]);
    }
    sort(c,c+nc,cmp);
    sort(p,p+np,cmp);
    int sum=0;
    for(int i=0,j=0;i<nc&&j<np;){
        if(c[i]>=0&&p[j]>=0){
            sum+=c[i]*p[j];
            i++;j++;
        }
        else
            break;
    }
    for(int i=nc-1,j=np-1;i>=0&&j>=0;){
        if(c[i]<=0&&p[j]<=0){
            sum+=c[i]*p[j];
            i--;j--;
        }
        else
            break;
    }
    printf("%d",sum);
    return 0;
}
