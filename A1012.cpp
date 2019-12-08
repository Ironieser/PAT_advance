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
    //�洢ÿһ�������ĳɼ�
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
//����㣺
//�ɼ���ͬ ����Ӧ����ͬ ����1 2 3 3 5��
//�ɼ�С��ǰ�� �����������ɼ���ǰ����ͬ
//������Ҳ��ǰ����ͬ
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
    for(int i=0;i<n;i++){//���ɼ���ͬ����������
        if(stu[i].com<stu[i-1].com||i==0) stu[i].cr=i;
        else stu[i].cr=i-1;
    }
    sort(stu,stu+n,cmp_m);
    for(int i=0;i<n;i++){//���ɼ���ͬ����������
        if(stu[i].mth<stu[i-1].mth||i==0) stu[i].mr=i;
        else stu[i].mr=i-1;
    }
    sort(stu,stu+n,cmp_e);
    for(int i=0;i<n;i++){//���ɼ���ͬ����������
        if(stu[i].eng<stu[i-1].eng||i==0) stu[i].er=i;
        else stu[i].er=i-1;
    }
    sort(stu,stu+n,cmp_avg);
    for(int i=0;i<n;i++){//���ɼ���ͬ����������
        if(stu[i].avg<stu[i-1].avg||i==0) stu[i].ar=i;
        else stu[i].ar=i-1;
    }
//*********************************************
//�˶γɼ��������� ���Խ��м�
//��ʽ�����ɼ��������飬ʹ��һ����� nowtag
cmp()�����У�Ԫ��Ϊgrade[nowtag];
nowtag����Ϊȫ�ֱ�����nowtag++����Ϊ��һ���ɼ�
��ʼ����������ÿ����һ�Σ�¼��һ�γɼ���������һ����ά����
stu_rank[2000][4]={0},ÿ��id��Ӧ������б�ţ�����Ϊ������
���ζԸ����ɼ����򣬲����д洢��
�����óɼ�ʱ���������ȼ����д洢��0>1>2>3��
�ڳɼ�������ͬʱ�������������������ɼ���ͬʱ������rank
����int min =0; for(int i=1;i<n;i++)  if(rank[i]<rank[min]){min=i;}
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
