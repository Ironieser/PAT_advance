#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=40010;
const int K=2600;
//算法可以优化，使用数组依次储存所有姓名姓名，
//存入course数组时，存入每个学生的顺序，
//按字典序对每门课的学生进行排序时，采用sort
//cmp函数如下：
//                bool cmp(int a,int b)
//                {//a,b 为course[i]数组中,学生的录入顺序
//                    return strcmp(name[a],name[b])<0;
//                    //按照字典序递增进行储存
//                }
vector <int> course[K];//存储每一门课程的学生
int getid(char s[])
{
    int id=0;
    for(int i=0;i<3;i++){
        id=26*id+s[i]-'A';
    }
    id=10*id+s[3]-'0';
    return id;
}
void printName(int id)
{
    char s[5];
    s[3]=id%10+'0';
    id/=10;
    s[4]='\0';
    for(int i=2;i>=0;i--){
        s[i]=id%26+'A';
        id/=26;
    }
    printf("%s\n",s);
}
int main()
{
    int n,k;
    char  name[N][10];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int x;
        scanf("%s %d",name[i],&x);
        int id=getid(name[i]);
        for(int j=0;j<x;j++){
            int course_num;
            scanf("%d",&course_num);
            course[course_num].push_back(id);
        }
    }
    for(int i=1;i<=k;i++){
        sort(course[i].begin(),course[i].end());
        printf("%d %d\n",i,course[i].size());
        for(int j=0;j<course[i].size();j++){
            printName(course[i][j]);
        }
    }
    return 0;
}
