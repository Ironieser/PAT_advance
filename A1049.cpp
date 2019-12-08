#include<cstdio>
//思路：
//将数字分为左边，当前位，右边三部分
//按照规律，根据当前位与1的关系，可推算出
//此位为1的数字的总个数
//当temp>1  ,num=(left+1)*t;
//当temp==1,num=(left)*t+right+1;
//当temp==0,num=(left)*t
int main()
{
    int n,left,right,t=1;
    int ans=0;
    scanf("%d",&n);
    while(n/t!=0){
        right=n%t;
        left=n/(t*10);
        int temp;
        temp=n/t%10;
        if(temp>1){
            ans+=(left+1)*t;
        }
        else if(temp==1){
            ans+=(left)*t+right+1;
        }
        else{
            ans+=(left)*t;
        }
        t*=10;
    }
    printf("%d",ans);
    return 0;
}
