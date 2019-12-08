#include<cstdio>
struct stu
{
    char name[12];
    char g;// F || M
    char num[12];
    int grade;//0~100
}m,f,t;
int main()
{
    int n;
    scanf("%d",&n);
    m.grade=101,f.grade=-1;//m.grade min;f.grade max;
    while(n--)
    {
        scanf("%s %c %s %d",t.name,&t.g,t.num,&t.grade);
        if(t.g=='F')
        {
            if(t.grade>f.grade)
                f=t;
        }
        else
        {
            if(t.grade<m.grade)
                m=t;
        }
    }
    // 使用flag标记，使代码过于繁琐，对于简单程序，
    //可不使用flag
    int flag1,flag2;
    if(f.grade==-1)
     {
        printf("Absent\n");
        flag1=0;
     }
     else
     {
         printf("%s %s\n",f.name,f.num);
         flag1=1;
     }
    if(m.grade==101)
     {
        printf("Absent\n");
        flag2=0;
     }
     else
     {
         printf("%s %s\n",m.name,m.num);
         flag2=1;
     }
     if((!flag1)||(!flag2))
     {
         printf("NA\n");
     }
     else
     {
         printf("%d",f.grade-m.grade);
     }
     return 0;

}
