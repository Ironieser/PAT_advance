#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxint=50000;
struct Stu
{
    char name[20];
    char id[20];
    int gr;
    bool flag;
}stu[maxint];
bool cmp(Stu a,Stu b)
{
    return a.gr>b.gr;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].gr);
    }
    sort(stu,stu+n,cmp);
    int min,max;
    scanf("%d%d",&min,&max);
    int count=0;
    for(int i=0;i<n;i++){
        if(stu[i].gr<=max&&stu[i].gr>=min){
            count++;
            printf("%s %s\n",stu[i].name,stu[i].id);
        }
        if(stu[i].gr<min){
            break;
            }
        }

    if(count==0)
        {printf("NONE\n");}
    return 0;
}
