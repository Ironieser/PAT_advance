#include<set>
#include<cstdio>
using namespace std;
const int N=60;
const int K=2500;
set <int> arr[N];
set <int>::iterator ita, itb;
//set <int>::iterator itb;
void print_sim(int a,int b)
{
    int same=0,dif=0;
    ita=arr[a].begin();
    itb=arr[b].begin();
//    while(ita!=arr[a].end()&&itb!=arr[b].end()){
//        if(*itb==*ita){
//            same++;
//            ita++;
//            itb++;
//        }
//        else if(*itb<*ita){ itb++; }
//        else{ ita++; }
//    }
    while(itb!=arr[b].end()){
        set<int>:: iterator te=arr[a].end();
        if(te!=arr[a].find(*itb)){
        //使用find函数，如果未找到，返回set.end()
        //count 函数， 一对迭代器和一个参数，返回参数出现次数
        //int num=count(set.begin(),set.begin(),value);
            same++;
        }
        itb++;
    }
    dif=arr[a].size()+arr[b].size()-same;
    double ans=same*100.0/dif;
    printf("%.1lf%%\n",ans);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++){
            int y;
            scanf("%d",&y);
            arr[i].insert(y);
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        print_sim(a,b);
    }
    return 0;
}
