#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu
{
//    int gr[10]={0};//�ɼ�����;
//    int good=0;//������Ŀ����
//    bool tag=false;//�Ƿ����ͨ��һ��
//    int sum=0;
    int idd;
    int gr[10];//�ɼ�����;
    int good;//������Ŀ����
    bool tag;//�Ƿ����ͨ��һ��
    int sum;
}stu[10050];//�Ǳ���Ϊid
//*****************************************
//cmp�жϺ�����д��
//��tag=false ���������������Ӧ��������
//tag=true��sum=0�ļ�¼��
//�������Ҫ��Ϊ�������ύ�����������󣬻����ύ
//���򣬼�ʹgrade==0��sum==0��ҲҪ������
//ע�������ԡ�sort��������Ҫ����ʱ�临�Ӷ�
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
    int count=0;//�ύ�ɹ�����
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=k;i++){
        scanf("%d",&gd[i]);//1~5
    }
    for(int i=0;i<10050;i++){
        for(int j=0;j<10;j++){stu[i].gr[j]=-1;}//��ʼ�ɼ�Ϊ-1
        stu[i].good=0;
        stu[i].tag=false;
        stu[i].sum=0;
    }
 //   int max=0;
    for(int i=0;i<m;i++){
        int id,kk,g;
        scanf("%d%d%d",&id,&kk,&g);
        if(stu[id].gr[kk]==-1) stu[id].gr[kk]=0;
        if(g>=0){//�������δͨ����������
            stu[id].idd=id;
 //           if(id>max) max=id;
            if(g==gd[kk]&&stu[id].gr[kk]!=gd[kk])//ĿǰΪ���֡���֮ǰ������
                stu[id].good++;//������Ŀ������һ
            if(g>stu[id].gr[kk]){//������߷�
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
 //sort��������Ҫ����ʱ�临�Ӷ�����
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
