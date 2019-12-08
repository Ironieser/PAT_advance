#include<cstdio>
#include<cstring>
const int maxn=10050;
int main()
{//本题字符串尾的'\n'对结果无影响，故无需调整字符串
    char s1[maxn],s2[maxn];
    fgets(s1,maxn,stdin);
    fgets(s2,maxn,stdin);
    int len1=strlen(s1),len2=strlen(s2);
    bool hash[200]={false};
    for(int i=0;i<len2;i++){
  //      int c=s2[i];hash[c]=true;
       hash[(int)(s2[i])]=true;
    }
    for(int i=0;i<len1;i++){
        int c=s1[i];
        if(hash[c])
            continue;
        else
            printf("%c",s1[i]);
    }
	return 0;
}
