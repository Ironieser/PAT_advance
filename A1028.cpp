#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu
{
    int id;
    char name[20];
    int gr;
}stu[100500];
bool cmp1(Stu a,Stu b)
{
    return a.id<b.id;
}
bool cmp2(Stu a,Stu b)
{
    int flag=strcmp(a.name,b.name);
    if(flag!=0)
        return flag<0;
    else
        return a.id<b.id;
}
bool cmp3(Stu a,Stu b)
{
    if(a.gr!=b.gr) return a.gr<b.gr;
    else return a.id<b.id;
}
void sortall(Stu *pa,Stu *pb,int tag)//根据输入tag 选择排序类型
{
    switch(tag){
        case 1:sort(pa,pb,cmp1);break;  //id 递增
        case 2:sort(pa,pb,cmp2);break;
        case 3:sort(pa,pb,cmp3);break;
    }
}
int main()
{
    int n,tag;
    scanf("%d%d",&n,&tag);
    for(int i=0;i<n;i++){
        scanf("%d%s%d",&stu[i].id,stu[i].name,&stu[i].gr);
    }
    sortall(stu,stu+n,tag);
    for(int i=0;i<n;i++){
        printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].gr);
    }
}
