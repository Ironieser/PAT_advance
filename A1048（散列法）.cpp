#include<cstdio>
//此为散列做法，需用二分查找，two pointers 再完成两次
const int maxm=1100;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int hash[maxm]={0};
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        hash[t]++;
    }
    bool flag=false;
    for(int i=0;i<m;i++){
        //i<m;即为，当硬币面值大于应付金额时，即不可支付，判断结束
        if(hash[i]){
            hash[i]--;
            if(hash[m-i]){
                printf("%d %d",i,m-i);
                flag=true;
                break;
            }
            else
                hash[i]++;
        }
    }
    if(!flag)
        printf("No Solution");
    return 0;
}
