#include<cstdio>
#include<algorithm>
#include<cstring>
//整体算法先有大致框架，分为三部分
//1.数据录入，按字典序，月日时分进行排序
//2.对所有记录，按用户进行记录处理，
//3.对用户的每一成对记录的判断识别，并进行计算处理，输出；
//  对用户整体进行输出，按照样本要求
//难点：1）写出用户分类的布尔表达式
//          2）用户成对记录计算输出，技巧，分钟++，进行计算输出。
//          3）cmp函数的书写
using namespace std;
struct Per
{
    char name[100];
    int month;
    int day;
    int hour;
    int minute;
    int tag;//状态 0接听。1挂断；
}per[1050];
int charge[24];//每小时花费
double sum;//每个用户的总花费，在函数中赋值
void timeprint(Per a);
bool cmp(Per a,Per b)
{
    if(strcmp(a.name,b.name)!=0){
        return strcmp(a.name,b.name)<0;
    }
    else if(a.month!=b.month){//所有样例均在同一月份
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
void outgrade(Per a,Per b)//输出每一对记录
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
    sort(per,per+n,cmp);//排序
    for(int i=0;i<n;){//从第一个记录开始判断
        int flag=0;
        int isprint=0;
        sum=0;
        if(((strcmp(per[i].name,per[i-1].name)!=0)&&i<n)||i==0){//新用户的第一个记录
             if(per[i].tag==1) {flag=1;}//只要有on ， flag置1 等待配对
             i++;
        }
        while(((strcmp(per[i].name,per[i-1].name)==0)&&i<n)||i==0){//属于同一用户，从第二个记录开始，至出现下一个用户
            if(per[i].tag==1) {flag=1;}//只要有on ， flag置1 等待配对
            else if(per[i].tag==0&&flag==1){ flag=2;isprint++;}//flag为1 时，出现tag==0，有一对on off
            if(isprint==1){
                printf("%s %02d\n",per[i].name,per[i].month);
                isprint++;
            }
            if(flag==2){//出现一对，进行处理
                outgrade(per[i-1],per[i]);//每一对记录进行处理，然后打印，并求sum
                flag=0;
            }
            i++;
        }
        if(isprint){//一个用户账单记录完毕
            printf("Total amount: $%.2lf\n",sum);//输出sum
        }
    }
    return 0;
}


