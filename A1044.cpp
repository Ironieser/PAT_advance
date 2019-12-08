#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100050;
int sum[maxn];//存放数据
int n,m;

int binarySearch(int left,int right,int val)
{//二分查找函数，找出第一个大于或等于val的值
    int mid;
    int temp=sum[left-1];
    while(left<right){
        mid=(left+right)/2;
        int t=sum[mid]-temp;
        if(t>=val){
            right=mid;
        }
        else left=mid+1;
    }
    return left;
}

int main()
{
    scanf("%d%d",&n,&m);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        sum[i]=sum[i-1]+temp;
    }
    int arr[maxn][2]={0},ans;
    long long minsum=(1LL<<63)-1;
    int count=0;
    bool tag=false;//进行标记。指示出有无相等条件值
    for(int i=1;i<=n;i++){//从第一个元素开始往后取
        int flag=binarySearch(i,n,m);
        ans=sum[flag]-sum[i-1];
        //对查找出来的值进行判断
        if(ans==m){//如果值等于要求，则以后均输出等于要求的值
            printf("%d-%d\n",i,flag);
            tag=true;
        }
         else if(!tag&&ans>m){//若查找值大于要求，且无合适的值
             //则保存最小的值sum，将其的位置保存在二维数组之中
            if(ans==minsum){
                arr[count][0]=i;
                arr[count][1]=flag;
                count++;
            }
            else if(ans<minsum){
                count=0;
                arr[count][0]=i;
                arr[count][1]=flag;
                count++;
                minsum=ans;
            }
        }
    }
    if(!tag){//如果无相等条件下的合适值，则输出最小的值
        for(int i=0;i<count;i++){
            printf("%d-%d\n",arr[i][0],arr[i][1]);
        }
    }

    return 0;
}
