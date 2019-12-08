#include<cstdio>
#include<algorithm>
using namespace std;
int s1[200050];
//一开始内存溢出，选择仅设置一个数组，
//当开始录入第二数组，直接进行判断，
int main()
{
    int n1,n2;
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&s1[i]);
    }
    s1[n1]=(1<<31)-1;
    scanf("%d",&n2);
    int mid=(n1+n2-1)/2;
    int i=0,num=0;
    int temp;
    for(int j=0;j<n2;j++){
        scanf("%d",&temp);
        if(num==mid){//读入要给数字，若是中位数，判断输出
            printf("%d",min(temp,s1[i]));
            return 0;
        }
        while(temp>=s1[i]) {//如果输入数字大于数组一，则向后调整数组一的指针
                i++;num++;//下标+1，总数+1
                if(num==mid){
                    printf("%d",min(temp,s1[i]));
                    return 0;
                }
        }
        num++;//本次录入结束，进行下一次判断
    }
    printf("%d",s1[mid-n2]);//数组二全部读入，中位数未求出，则在数字一中对应位置打印
    return 0;
}
