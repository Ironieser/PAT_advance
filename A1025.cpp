#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu
{
    int room;//考场编号
    char num[20];
    int grade;
    int rr;//考场内排名
    int rank;
}stu[40000];
int r_num[400];//每个考场人数
bool cmp(Stu a,Stu b)//对所有考生进行排序
{
    if(a.grade!=b.grade) return a.grade>b.grade;
    else return strcmp(a.num,b.num)<0;
}
//成绩相同，排名相同，输出按字典序增的方向
//  the output must be sorted in
//  nondecreasing order of their registration numbers.
int main()
{
    int n;
    scanf("%d",&n);
    int count=0;
    for(int i=0;i<n;i++){//分考场录入
        int k;
        scanf("%d",&k);
        int first=count;//first 为考场第一个学生脚标。count为总数
        for(int j=0;j<k;j++){//按考场录入
            stu[count].room=i+1;
            scanf("%s %d",stu[count].num,&stu[count].grade);
            count++;
        }
       sort(stu+first,stu+count,cmp);
        for(int j=first;j<count;j++){//每一个考场进行排名，成绩相同，排名不变
            if(stu[j].grade<stu[j-1].grade||j==first)
                stu[j].rr=j-first+1;
            else
                stu[j].rr=stu[j-1].rr;
        }
    }
    sort(stu,stu+count,cmp);
    for(int i=0;i<count;i++){
        if(stu[i].grade<stu[i-1].grade||i==0){
            stu[i].rank=i+1;
        }
        else
            stu[i].rank=stu[i-1].rank;
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%s %d %d %d\n",stu[i].num,stu[i].rank,stu[i].room,stu[i].rr);
    }
}
