#include<cstdio>
#include<cstring>
int main()
{
    char str1[110];
    scanf("%s",str1);
    int len;
    len=strlen(str1);
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum+=str1[i]-'0';
    }
    char str2[][8]={"zero","one","two","three","four","five","six",
    "seven","eight","nine","ten"};
    int n[1000];
    int num=0;

    do{
        n[num++]=sum%10;
        sum/=10;
    }while(sum!=0);
    for(num--;num>=0;num--){
        printf("%s",str2[n[num]]);
        if(num!=0)
            printf(" ");
    }
}
