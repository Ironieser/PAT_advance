#include<cstdio>
#include<map>
using namespace std;
map <int ,int > num;
//利用map作为大数据的bool数组
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int max=0;
    num[0]=0;
    for(int i=0;i<n*m;i++){
        int t;
        scanf("%d",&t);
        if(num.find(t)!=num.end()) num[t]++;
        else num[t]=1;
        if(num[t]>num[max]) {max=t;}
    }
    printf("%d",max);
    return 0;
}
