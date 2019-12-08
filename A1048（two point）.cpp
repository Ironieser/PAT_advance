#include<cstdio>
#include<algorithm>
//two point 法
using namespace std;
int maxn=100050;
int main()
{
    int n,m;
    int a[maxn];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int i=0,j=n-1;
    while(i<j){//设置两个下标，i，j  根据a[i]+a[j]与m的关系进行计算
        if(a[i]+a[j]>m) j--;
        else if(a[i]+a[j]<m) i++;
        else {
            printf("%d %d",a[i],a[j]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
