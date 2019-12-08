#include<cstdio>
const int maxnum=100050;
const int maxn=100500;
int main()
{
    int n;
    scanf("%d",&n);
    int per[maxn];
    int hash[maxnum]={0};
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        per[i]=t;
        hash[t]++;
    }
    int flag=false;
    for(int i=0;i<n;i++){
        if(hash[per[i]]==1){
            printf("%d",per[i]);
            flag=true;
            break;
        }
    }
    if(!flag) printf("None");
    return 0;
}
