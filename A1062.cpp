#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct Stu
{
    int num;
    int vir;
    int tal;
    int sum;
    int flag;//���
}stu[100020];
//һ���²ž�����
//�����¹��ߣ��Ų�������
//�����²ž�������,�¸��ڲ�
//�ġ��²����ߣ��Ź���
//�塢�²Ŷ�������
bool cmp(Stu a,Stu b);
int main()
{
    int n,lowgra,grtgra;int num;
    scanf("%d %d %d",&n,&lowgra,&grtgra);
    num=n;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&stu[i].num,&stu[i].vir,&stu[i].tal);
        stu[i].sum=stu[i].vir+stu[i].tal;
        if(stu[i].vir<lowgra||stu[i].tal<lowgra)    {stu[i].flag=5;num--;}
        else if(stu[i].vir<grtgra&&stu[i].vir<grtgra&&stu[i].vir>=stu[i].tal)   stu[i].flag=3;
        else if(stu[i].vir>=grtgra&&stu[i].tal>=grtgra) stu[i].flag=1;
        else if(stu[i].vir>=grtgra&&stu[i].tal<grtgra) stu[i].flag=2;
        else stu[i].flag=4;
    }
    sort(stu,stu+n,cmp);
    printf("%d\n",num);
    for(int i=0;i<num;i++){
        if(stu[i].flag!=5)
 //           printf("%d %d %d\n",stu[i].num,stu[i].vir,stu[i].tal);
            cout<<stu[i].num<<" "<<stu[i].vir<<" "<<stu[i].tal<<endl;
        else
            continue;
    }

}
bool cmp(Stu a,Stu b)
{
    if(a.flag!=b.flag) return a.flag<b.flag;
    else if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.vir!=b.vir) return a.vir>b.vir;
    else return a.num<b.num;
}
