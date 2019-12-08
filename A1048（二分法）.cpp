#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010];
int bin(int left,int right,int val)
{
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(a[mid]==val) return mid;
        else if(a[mid]>val)  right=mid-1;
        else left=mid+1;
    }
    return -1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    bool tag=false;
    for(int i=0;i<n;i++){
        int flag=bin(i,n,m-a[i]);
        if(flag>=0&&flag!=i){
            printf("%d %d\n",a[i],m-a[i]);
            tag=true;
            break;
        }
    }
    if(!tag){
        printf("No Solution");
    }
}
