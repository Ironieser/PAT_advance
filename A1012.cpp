#include<cstdio>
#include<algorithm>
using namespace std;
struct Stu
{
    int id;
    int com;
    int mth;
    int eng;
    int avg;
    //存储每一次排名的成绩
    int cr;
    int mr;
    int er;
    int ar;
}stu[2050];
bool cmp_c(Stu a,Stu b)
{
    return a.com>b.com;
}
bool cmp_m(Stu a,Stu b)
{
    return a.mth>b.mth;
}
bool cmp_e(Stu a,Stu b)
{
    return a.eng>b.eng;
}
bool cmp_avg(Stu a,Stu b)
{
    return a.avg>b.avg;
}
void outrank(Stu a)
{
    int  tag=5;
    char pr[4]={'A','C','M','E'};
    int minrank=3000;
    if(a.cr<minrank||(a.cr==minrank&&tag>1)){minrank=a.cr;tag=1;}
    if(a.mr<minrank||(a.mr==minrank&&tag>2)){minrank=a.mr;tag=2;}
    if(a.er<minrank||(a.er==minrank&&tag>3)){minrank=a.er;tag=3;}
    if(a.ar<minrank||(a.ar==minrank&&tag>0)){minrank=a.ar;tag=0;}
    printf("%d %c\n",minrank+1,pr[tag]);
}
//错误点：
//成绩相同 排名应该相同 例：1 2 3 3 5；
//成绩小于前者 正常排名，成绩与前者相同
//则排名也与前者相同
int main()
{
    int n,m;
    int num[2050];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&stu[i].id,&stu[i].com,
              &stu[i].mth,&stu[i].eng);
        stu[i].avg=(stu[i].com+stu[i].mth+stu[i].eng);
//        if((stu[i].com+stu[i].mth+stu[i].eng)%3==2){
//            stu[i].avg++;
//        }
    }
    for(int i=0;i<m;i++){
        scanf("%d",&num[i]);
    }
//*********************************************
    sort(stu,stu+n,cmp_c);
    for(int i=0;i<n;i++){//若成绩相同，则并列排名
        if(stu[i].com<stu[i-1].com||i==0) stu[i].cr=i;
        else stu[i].cr=i-1;
    }
    sort(stu,stu+n,cmp_m);
    for(int i=0;i<n;i++){//若成绩相同，则并列排名
        if(stu[i].mth<stu[i-1].mth||i==0) stu[i].mr=i;
        else stu[i].mr=i-1;
    }
    sort(stu,stu+n,cmp_e);
    for(int i=0;i<n;i++){//若成绩相同，则并列排名
        if(stu[i].eng<stu[i-1].eng||i==0) stu[i].er=i;
        else stu[i].er=i-1;
    }
    sort(stu,stu+n,cmp_avg);
    for(int i=0;i<n;i++){//若成绩相同，则并列排名
        if(stu[i].avg<stu[i-1].avg||i==0) stu[i].ar=i;
        else stu[i].ar=i-1;
    }
//*********************************************
//此段成绩进行排名 可以进行简化
//方式：将成绩设置数组，使用一个标号 nowtag
cmp()函数中，元素为grade[nowtag];
nowtag设置为全局变量，nowtag++，则为下一个成绩
开始进行排名，每排名一次，录入一次成绩，可设置一个二维数组
stu_rank[2000][4]={0},每个id对应数组的行标号，其列为排名，
依次对各个成绩排序，并进行存储，
在设置成绩时，按照优先级进行存储，0>1>2>3；
在成绩排名相同时，不更改最优排名，成绩不同时，更改rank
即：int min =0; for(int i=1;i<n;i++)  if(rank[i]<rank[min]){min=i;}
//*********************************************
//*********************************************/
    for(int i=0;i<m;i++){
        bool flag=false;
        for(int j=0;j<n;j++){
            if(stu[j].id==num[i]){
                outrank(stu[j]);
            flag=true;
            break;
            }
        }
        if(!flag){
            printf("N/A\n");
        }
    }
    return 0;
}
