#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=40010;
const int K=2600;
//�㷨�����Ż���ʹ���������δ�����������������
//����course����ʱ������ÿ��ѧ����˳��
//���ֵ����ÿ�ſε�ѧ����������ʱ������sort
//cmp�������£�
//                bool cmp(int a,int b)
//                {//a,b Ϊcourse[i]������,ѧ����¼��˳��
//                    return strcmp(name[a],name[b])<0;
//                    //�����ֵ���������д���
//                }
vector <int> course[K];//�洢ÿһ�ſγ̵�ѧ��
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
