#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu
{
    int room;//�������
    char num[20];
    int grade;
    int rr;//����������
    int rank;
}stu[40000];
int r_num[400];//ÿ����������
bool cmp(Stu a,Stu b)//�����п�����������
{
    if(a.grade!=b.grade) return a.grade>b.grade;
    else return strcmp(a.num,b.num)<0;
}
//�ɼ���ͬ��������ͬ��������ֵ������ķ���
//  the output must be sorted in
//  nondecreasing order of their registration numbers.
int main()
{
    int n;
    scanf("%d",&n);
    int count=0;
    for(int i=0;i<n;i++){//�ֿ���¼��
        int k;
        scanf("%d",&k);
        int first=count;//first Ϊ������һ��ѧ���űꡣcountΪ����
        for(int j=0;j<k;j++){//������¼��
            stu[count].room=i+1;
            scanf("%s %d",stu[count].num,&stu[count].grade);
            count++;
        }
       sort(stu+first,stu+count,cmp);
        for(int j=first;j<count;j++){//ÿһ�����������������ɼ���ͬ����������
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
