#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int main()
{
    int n,p,a[maxn];
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int i=0,j=0,count=1;
    while(i<n&&j<n){
        while(j<n&&a[j]<=(long long)a[i]*p){
            j++;
            count=max(count,j-i);
        }
        i++;
    }
    printf("%d",count);
    return 0;
}
