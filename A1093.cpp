#include<cstdio>
#include<cstring>
int main()
{
    char s[100050];
    int p=0,t=0,sum=0;
    scanf("%s",s);
    int len=strlen(s);
    int num[2][100050]={0};
    for(int i=0;i<len;i++){//计数p
        if(s[i]=='P') p++;
        else if(s[i]=='A') { num[0][i]=p; }
    }
    for(int i=len;i>0;i--){//计数t
        if(s[i]=='T') t++;
        else if(s[i]=='A') { num[1][i]=t; }
    }
    for(int i=0;i<len;i++){
        sum+=num[1][i]*num[0][i];
        sum%=1000000007;
    }
    printf("%d",sum);
    return 0;
}
