#include<cstdio>
#include<cstring>
struct bign
{
    int d[50];
    int len;
    bign()
    {
        memset(d,0,sizeof(d));
        len=0;
    }
};
bign tobign(char s[])
{
    bign a;
    a.len=strlen(s);
    for(int i=0;i<a.len;i++){
        a.d[i]=s[a.len-1-i]-'0';
    }
    return a;
}
bign mult(bign a,int b)
{
    bign c;
    int t=0;
    for(int i=0;i<a.len;i++){
        t+=a.d[i]*b;
        c.d[c.len++]=t%10;
        t/=10;
    }
    while(t!=0){
        c.d[c.len++]=t%10;
        t/=10;
    }
    return c;
}
bool isright(bign a,bign b)
{
    int ha[10]={0};
    if(a.len!=b.len){
        return false;
    }else{
        for(int i=0;i<a.len;i++){
            ha[a.d[i]]++;
            ha[b.d[i]]--;
        }
//************************************
///´íÎóµã: i<a.len  Ó¦Îªi<10
///   for(int i=0;i<a.len;i++){
//************************************
        for(int i=0;i<10;i++){
            if(ha[i]!=0){
                return false;
            }
        }
    }
    return true;
}
int main()
{
    char s[50];
    scanf("%s",s);
    bign a=tobign(s);
    bign b=mult(a,2);
    if(isright(a,b)){
        printf("Yes\n");
    }else
        printf("No\n");
    for(int i=b.len-1;i>=0;i--){
        printf("%d",b.d[i]);
    }
    return 0;
}
