#include<cstdio>
#include<cstring>
int main()
{
    char s[4][65];
    for(int i=0;i<4;i++)
    {
        fgets(s[i],65,stdin);
    //    s[i][0]=strlen(s[i])-1;
    }
    char d,h;int i=0;
    int m;
    int len, len1;
    len=strlen(s[0])-1;
    //Çóday
    for(i=0;i<len;i++)
    {
        if(s[0][i]>='A'&&s[0][i]<='G'&&s[0][i]==s[1][i])// A~G
        {
           d=s[0][i];
           break;
        }
    }
    //Çóhour
    len=strlen(s[0])-1;
    len1=strlen(s[1])-1;
    for(i++;i<len&&i<len1;i++)//0~9 A~N
    {
         if(s[0][i]==s[1][i]&&((s[0][i]>='0'&&s[0][i]<='9')||
                                    (s[0][i]>='A'&&s[0][i]<='N')))
        {
           h=s[0][i];break;
        }
    }
    //Çóminutes
//    int num=0;
    len=strlen(s[2])-1;
    len1=strlen(s[3])-1;
    for(int j=0;j<len&&j<len1;j++)
    {
        if((s[2][j]>='A'&&s[2][j]<='Z')||(s[2][j]>='a'&&s[2][j]<='z'))
        {
            if(s[3][j]==s[2][j])
            {m=j;break;}
        }
    }
    char day[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    printf("%s ",day[d-'A']);
    if(h>='0'&&h<='9')
        printf("%02d",h-'0');
    else
        printf("%d",h-'A'+10);

    printf(":%02d",m);
    return 0;


}
