#include<cstdio>
#include<algorithm>
#include<cstring>
//�����㷨���д��¿�ܣ���Ϊ������
//1.����¼�룬���ֵ�������ʱ�ֽ�������
//2.�����м�¼�����û����м�¼����
//3.���û���ÿһ�ɶԼ�¼���ж�ʶ�𣬲����м��㴦�������
//  ���û���������������������Ҫ��
//�ѵ㣺1��д���û�����Ĳ������ʽ
//          2���û��ɶԼ�¼������������ɣ�����++�����м��������
//          3��cmp��������д
using namespace std;
struct Per
{
    char name[100];
    int month;
    int day;
    int hour;
    int minute;
    int tag;//״̬ 0������1�Ҷϣ�
}per[1050];
int charge[24];//ÿСʱ����
double sum;//ÿ���û����ܻ��ѣ��ں����и�ֵ
void timeprint(Per a);
bool cmp(Per a,Per b)
{
    if(strcmp(a.name,b.name)!=0){
        return strcmp(a.name,b.name)<0;
    }
    else if(a.month!=b.month){//������������ͬһ�·�
        return a.month<b.month;
    }
    else if(a.day!=b.day){
        return a.day<b.day;
    }
    else if(a.hour!=b.hour){
        return a.hour<b.hour;
    }
    else {
        return a.minute<b.minute;
    }
}
void outgrade(Per a,Per b)//���ÿһ�Լ�¼
{
    timeprint(a);
    timeprint(b);
    Per t;
    t=a;
    double m=0;
    int count=0;
    while(!(t.month==b.month&&t.day==b.day&&
t.hour==b.hour&&t.minute==b.minute)){
        m=m+charge[t.hour];
        t.minute++;
        count++;
        if(t.minute==60){
            t.hour++;
            t.minute-=60;
            if(t.hour==24){
                t.day++;
                t.hour-=24;
            }
        }
    }
    printf("%d $%.2lf\n",count,m/100);
    sum+=m/100;
}

void timeprint(Per a)
{
    printf("%02d:%02d:%02d ",a.day,a.hour,a.minute);
}
int main()
{
    for(int i=0;i<24;i++){
        scanf("%d",&charge[i]);
    }
    int n;
    scanf("%d",&n);
    char line[20];
    for(int i=0;i<n;i++){
        scanf("%s",per[i].name);
        scanf("%d:%d:%d:%d",&per[i].month,&per[i].day,&per[i].hour,&per[i].minute);
        scanf("%s",line);
        if(strcmp(line,"on-line")==0) per[i].tag=1;
        else per[i].tag=0;
    }
    sort(per,per+n,cmp);//����
    for(int i=0;i<n;){//�ӵ�һ����¼��ʼ�ж�
        int flag=0;
        int isprint=0;
        sum=0;
        if(((strcmp(per[i].name,per[i-1].name)!=0)&&i<n)||i==0){//���û��ĵ�һ����¼
             if(per[i].tag==1) {flag=1;}//ֻҪ��on �� flag��1 �ȴ����
             i++;
        }
        while(((strcmp(per[i].name,per[i-1].name)==0)&&i<n)||i==0){//����ͬһ�û����ӵڶ�����¼��ʼ����������һ���û�
            if(per[i].tag==1) {flag=1;}//ֻҪ��on �� flag��1 �ȴ����
            else if(per[i].tag==0&&flag==1){ flag=2;isprint++;}//flagΪ1 ʱ������tag==0����һ��on off
            if(isprint==1){
                printf("%s %02d\n",per[i].name,per[i].month);
                isprint++;
            }
            if(flag==2){//����һ�ԣ����д���
                outgrade(per[i-1],per[i]);//ÿһ�Լ�¼���д���Ȼ���ӡ������sum
                flag=0;
            }
            i++;
        }
        if(isprint){//һ���û��˵���¼���
            printf("Total amount: $%.2lf\n",sum);//���sum
        }
    }
    return 0;
}


