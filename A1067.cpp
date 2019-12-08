#include<cstdio>
const int maxn=100200;
int arr[maxn];
int p[maxn];//存放数字的位置
int count=0;
void Swap(int a,int b)
{//将arr[i]与0交换，并保存交换后的地址
    a=0;
    int temp=p[b];
    p[b]=p[a];
    p[a]=temp;

    arr[p[a]]=a;
    arr[p[b]]=b;
    count++;
}
//*************************
///设置一个k，来记录不在本位的最小数，
///每当0回到本位，便开始继续判断数字是否均回到本位
///一旦出现未回到本位的数字，便记录位置k
//*************************
int k=1;
int  isok(int n)
{
    for( int i=k;i<n;i++){
        if(arr[i]!=i){
            k=i;
            return i;
        }
    }
    return -1;
}
//*************************
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        arr[i]=temp;
        p[temp]=i;//数字作为角标，存放数字位置;
    }
//*************************************
///此错误为算法错误，并不能求出最小的交换次数
///在决定算法时，应先使用样例进行判断
//***************************************
//    for(int i=1;i<n;i++){
//        if(arr[i]!=i){//如果第i个位置不是i
//            if(arr[i]!=0){//如果第i个位置不是0；
//                Swap(arr[i]);//将arr[i]与0交换，并保存交换后的地址
//            }
//            Swap(arr[p[i]]);//将0与该位置的数交换；
//        }
//    }
//***********************************
    while(isok(n)!=-1){
        if(arr[0]!=0){
            int tag=p[0];//0所在位置的,与该位置应对应的数交换
            Swap(0,tag);
        }
        else{
            int tag;
            tag=isok(n);
            if(tag==-1) break;
            else {
                Swap(0,tag);
            }
        }
    }
    printf("%d",count);
}
