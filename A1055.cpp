#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Per
{
    char name[20];
    int age;
    int money;
}per[100100],per2[100100];
int k[2000][3];
int n;
int nn;//第二个数组的长度
bool cmp(Per a,Per b)
{
    if(a.money!=b.money)
        return a.money>b.money;
    else if(a.age!=b.age)
        return a.age<b.age;
    else
        return strcmp(a.name,b.name)<0;//字典序递增
}

void outper(int t)
{
    int count=0;
    int m=k[t][0];
    int min=k[t][1];
    int max=k[t][2];
    printf("Case #%d:\n",t+1);
    for(int i=0;i<nn&&count<m;i++){//加入数组优化后，数组长度为nn
        if(per2[i].age>=min&&per2[i].age<=max)
           {
               printf("%s %d %d\n",per2[i].name,per2[i].age,per2[i].money);
               count++;
           }
    }
    if(count==0)
        printf("None\n");
}
int main()
{
    int kk;
    scanf("%d%d",&n,&kk);
    for(int i=0;i<n;i++){
        scanf("%s %d %d",per[i].name,&per[i].age,&per[i].money);
    }
    for(int i=0;i<kk;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&k[i][j]);
        }
    }
    sort(per,per+n,cmp);
//**********************数组优化***********
    int ag[300]={0};//年龄范围0~200
    nn=0;
    for(int i=0;i<n;i++){
        if(ag[per[i].age]<100){
            ag[per[i].age]++;
            per2[nn++]=per[i];
        }
    }
//*************************************
    for(int i=0;i<kk;i++){//超时  10^3  * 10^5 ==10^8,
        //对初始记录的进行优化，使其最少减少为10^4;
        outper(i);//更改后数组长度为nn；
    }
    return 0;
}
