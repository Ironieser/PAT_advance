#include<cstdio>
#include<cstring>
const int maxn=2000;
int main()
{
    char s1[maxn],s2[maxn];
    scanf("%s%s",s1,s2);
    int len1=strlen(s1),len2=strlen(s2);
    int hash[200]={0};
    for(int i=0;i<len1;i++){
        int c=s1[i];
        hash[c]++;
    }
    int count=0;//缺少珠子个数
    for(int i=0;i<len2;i++){
        int c=s2[i];
        if(hash[c]){
            hash[c]--;
        }
        else{
            count++;
        }
    }
    if(count){
        printf("No %d",count);
    }
    else{
        printf("Yes %d",len1-len2);
    }
    return 0;
}
