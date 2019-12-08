#include<cstdio>
#include<algorithm>
using namespace std;
int a[150],b[150],n;
int t[150];
bool isSame(int t[],int b[])//判断数组是否相等
{
    for(int i=0;i<n;i++){
        if(t[i]!=b[i]){
            return false;
        }
    }
    return true;
}
bool insert()
{
    bool flag=false;
     for(int i=1;i<n;i++){
        if(i!=1&&isSame(t,b)){
            flag=true;//再进行一次排序
        }
        //插入排序
        int temp=t[i],j=i;
        while(j>0&&temp<t[j-1]){
            t[j]=t[j-1];
            j--;
        }
        t[j]=temp;
        if(flag) return flag;
    }
    return flag;
}
void merge()
{
    bool flag=false;
    for(int step=2;step/2<=n;step*=2){
        if(step!=2&&isSame(a,b)){
            flag=true;
        }
        for(int i=0;i<n;i+=step){
            sort(a+i,a+min(i+step,n));
            //从a+i开始至a+step-1
            //最后一个分组的长度小于step；
        }
        if(flag) return ;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        t[i]=a[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    if(insert()){
        printf("Insertion Sort\n");
        for(int i=0;i<n;i++){
            if(i!=0) printf(" ");
            printf("%d",t[i]);
        }
    }
    else{
        printf("Merge Sort\n");
        merge();
        for(int i=0;i<n;i++){
            if(i!=0) printf(" ");
            printf("%d",a[i]);
        }
    }
    return 0;
}
