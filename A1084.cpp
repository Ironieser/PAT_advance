#include<cstdio>
#include<cstring>
int main()
{
    char s1[100],s2[100];
    fgets(s1,100,stdin);
    s1[strlen(s1)-1]='\0';
    fgets(s2,100,stdin);
    s2[strlen(s2)-1]='\0';
    int len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    bool hash[200]={false};
    for(int i=0,j=0;i<len1;i++){
        int temp=(int)s1[i];
        if((s1[i]!=s2[j]&&j<len2)||j>=len2){
                if(temp>='a'&&temp<='z')
                    temp-=32;
                if(!hash[temp])
                    printf("%c",temp);
                hash[temp]=true;
        }
        else j++;
    }
}


