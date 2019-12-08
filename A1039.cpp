#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int getid(char s[])
{
    int id=0;
    for(int i=0;i<3;i++)
    {
        id=26*id+s[i]-'A';
    }
    id=id*10+s[3]-'0';
    return id;
}
const int N=40010;
const int M=26*26*26*10+1;
vector <int> selectCourse[M];//ÿһ��ѧ����Ӧһ��course��
int main()
{
    char name[5];
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++){ //���γ����δ洢
        int c,x;//�γ̺ţ�����
        scanf("%d%d",&c,&x);
        for(int i=0;i<x;i++){
            scanf("%s",name);
            int id=getid(name);
            selectCourse[id].push_back(c);//���γ̺Ŷ����Ӧѧ�������飻
        }
    }
//*****************************
///¼��ѧ������ͬʱ������������ڽ���
//*****************************
    for(int i=0;i<n;i++){
        scanf("%s",name);
        int id=getid(name);
        printf("%s %d",name,selectCourse[id].size());
        sort(selectCourse[id].begin(),selectCourse[id].end());
        for(int j=0;j<selectCourse[id].size();j++){
            printf(" %d",selectCourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}
