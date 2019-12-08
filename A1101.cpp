#include<cstdio>
#include<algorithm>
using namespace std;
int maxn=100050;
int main()
{
    int a[maxn],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ml[maxn],mr[maxn];
    int max=-1;
    for(int i=0;i<n;i++){
        ml[i]=max;
        if(max<a[i]) max=a[i];
    }
   int min=(1<<31)-1;
    for(int i=n-1;i>=0;i--){
        mr[i]=min;
        if(min>a[i]) min=a[i];
    }
    int num=0,b[maxn]={0};
    for(int i=0;i<n;i++){
        if(ml[i]<a[i]&&mr[i]>a[i]){
            b[num]=a[i];
            num++;
        }
    }
    sort(b,b+num);
    printf("%d\n",num);
    if(num==0){ printf("\n");}
    //如果主元数量为零，则第一行输出零
    //第二行输出换行
    for(int i=0;i<num;i++){
        if(i!=0) printf(" ");
        printf("%d",b[i]);
    }
    return 0;
}
