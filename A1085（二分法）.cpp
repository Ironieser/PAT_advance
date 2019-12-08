#include<cstdio>
#include<algorithm>
using namespace std;
int num[100500];
int n,p;
//************************************
//本题错误点较多：题意理解出现偏差
//最小数不一定必须为数组num[0];
//题意为求第一个最大值小于最小数p倍的数的位置
//*****************************************
int search(int i)
{
    int left=i+1,right=n-1,mid;
///最后一个测试点错误：不属于同一格式，赋值前必须先进行强制转换
    long long x=(long long )num[i]*p;

   if(num[n-1]<=x) return n;
    while(left<right){
//     mid=left+(right-left)/2;
        mid=(left+right)/2;
        if(num[mid]>x){
             right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return left;
}
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    int ans=1;
    for(int i=0;i<n;i++){
        int j=search(i);
//***********************************
///使用upper_bound 函数，求数列中第一个大于p 的值。
//        int j=upper_bound(num+i+1,num+n,(long long )num[i]*p)-num;
//***********************************
        ans=max(ans,j-i);
    }
    printf("%d\n",ans);

    return 0;
}
