#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu
{
//    int gr[10]={0};//成绩数组;
//    int good=0;//满分题目数量
//    bool tag=false;//是否编译通过一次
//    int sum=0;
    int idd;
    int gr[10];//成绩数组;
    int good;//满分题目数量
    bool tag;//是否编译通过一次
    int sum;
}stu[10050];//角标作为id
//*****************************************
//cmp判断函数书写：
//若tag=false 则不输出，在排序中应将其排在
//tag=true，sum=0的记录后
//不输出的要求为：所有提交结果均编译错误，或无提交
//否则，即使grade==0，sum==0，也要输出结果
//注：经测试。sort函数不需要考虑时间复杂度
//*****************************************
bool cmp(Stu a,Stu b)
{
    if(a.tag!=b.tag) return a.tag>b.tag;
    else if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.good!=b.good) return a.good>b.good;
    else return a.idd<b.idd;
}
int main()
{
    int n,k,m;
    int gd[10]={0};
    int count=0;//提交成功人数
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=k;i++){
        scanf("%d",&gd[i]);//1~5
    }
    for(int i=0;i<10050;i++){
        for(int j=0;j<10;j++){stu[i].gr[j]=-1;}//初始成绩为-1
        stu[i].good=0;
        stu[i].tag=false;
        stu[i].sum=0;
    }
 //   int max=0;
    for(int i=0;i<m;i++){
        int id,kk,g;
        scanf("%d%d%d",&id,&kk,&g);
        if(stu[id].gr[kk]==-1) stu[id].gr[kk]=0;
        if(g>=0){//否则编译未通过，不保存
            stu[id].idd=id;
 //           if(id>max) max=id;
            if(g==gd[kk]&&stu[id].gr[kk]!=gd[kk])//目前为满分。且之前非满分
                stu[id].good++;//满分题目数量加一
            if(g>stu[id].gr[kk]){//存入最高分
                stu[id].sum=stu[id].sum-stu[id].gr[kk]+g;
                stu[id].gr[kk]=g;
            }
            if(stu[id].tag==false){
                stu[id].tag=true;
                count++;
            }
        }
    }
 //   sort(stu,stu+max+1,cmp);
 //sort函数不需要考虑时间复杂度问题
    sort(stu,stu+10050,cmp);
    int rank=1;
    printf("1 %05d %d",stu[0].idd,stu[0].sum);
    for(int i=1;i<=k;i++){
        if(stu[0].gr[i]>=0) printf(" %d",stu[0].gr[i]);
        else printf(" -");
    }
    printf("\n");

    for(int i=1;i<count;i++){
        if(stu[i].sum==stu[i-1].sum){
            printf("%d %05d %d",rank,stu[i].idd,stu[i].sum);
        }
        else{
            printf("%d %05d %d",i+1,stu[i].idd,stu[i].sum);
            rank=i+1;
        }
        for(int j=1;j<=k;j++){
            if(stu[i].gr[j]>=0) printf(" %d",stu[i].gr[j]);
            else printf(" -");
        }
        printf("\n");
    }
    return 0;
}
