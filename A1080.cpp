#include<cstdio>
#include<cstring>
#include<algorithm>
//模块化进行算法设计，输入，排序，按学校判断，输出
using namespace std;
const int maxn=45000;
const int maxm=200;
const int maxk=10;
struct Stu
{
    int id;
    int ge,gi;
    int ad[maxk];
    int sum;
    int rank;
}stu[maxn];
struct Sch
{
    int minrank;
    int qouta;
    int qt;
    int stuid[maxn];
}sch[maxm];
int qouta[maxm]={0};
bool cmp(Stu a ,Stu b)
{
    if(a.sum!=b.sum) return a.sum>b.sum;
    else return a.ge>b.ge;//
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d",&sch[i].qouta);
        sch[i].qt=0;
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&stu[i].ge,&stu[i].gi);
        stu[i].id=i;
        stu[i].sum=stu[i].ge+stu[i].gi;
        for(int j=0;j<k;j++){
            scanf("%d",&stu[i].ad[j]);
        }
    }
    //****************************
    sort(stu,stu+n,cmp);
    for(int i=0;i<n;i++){//对学生进行排名
        if(i==0||stu[i].sum<stu[i-1].sum||
           (stu[i].sum==stu[i-1].sum&&stu[i].ge<stu[i-1].ge)){
            stu[i].rank=i;
           }
        else{
            stu[i].rank=stu[i-1].rank;
        }
    }
    for(int i=0;i<n;i++){//每一名学生进行申请
        bool adm=false;
        for(int j=0;j<k;j++){
            int temp=stu[i].ad[j];//第i个学生的第j个志愿
            if(sch[temp].qouta>0&&
(sch[temp].qt<sch[temp].qouta||sch[temp].minrank==stu[i].rank)){
                sch[temp].minrank=stu[i].rank;
                sch[temp].stuid[sch[temp].qt]=stu[i].id;
                sch[temp].qt++;
                adm=true;
            }
            if(adm==true) break;
        }
    }
    for(int i=0;i<m;i++){//每一个学校,每完成一个学校，均需换行，或代以视为无输出，空换行
        sort(sch[i].stuid,sch[i].stuid+sch[i].qt);
        for(int j=0;j<sch[i].qt;j++){
            if(j!=0)
                printf(" ");
            printf("%d",sch[i].stuid[j]);
        }
  //      if(i!=m-1)
            printf("\n");
    }
    return 0;
}
