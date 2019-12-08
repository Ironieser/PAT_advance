#include<cstdio>
#include<cstring>
struct bign
{
    int d[1000];
    int len;
    bign()
    {
        memset(d,0,sizeof(d));
        len=0;
    }
};
bign tobign(char s[])
{//转换为bign
    bign a;
    a.len=strlen(s);
    for(int i=0;i<a.len;i++){
        a.d[i]=s[a.len-1-i]-'0';
    }
    return a;
}
bool isnum(bign a)
{//是否为回文
    if(a.len==1){
        return true;
    }
    else{
        for(int i=0;i<a.len/2;i++){
            if(a.d[i]!=a.d[a.len-1-i])
                return false;
        }
    }
    return true;
}
void print(bign a,int step)
{//输出
    for(int i=0;i<a.len;i++){
        printf("%d",a.d[a.len-i-1]);
    }
    printf("\n%d",step);
}
bign add(bign a)
{//加相反数
    bign c;
    int t=0;
    for(int i=0;i<a.len;i++){
        t+=a.d[i]+a.d[a.len-1-i];
        c.d[c.len++]=t%10;
        t/=10;
    }
    if(t!=0){
        c.d[c.len++]=t;
    }
    return c;
}
int main()
{
    char s[20];int k;
    scanf("%s %d",s,&k);
    bign n=tobign(s);
    if(isnum(n)){
        print(n,0);
    }else{
        for(int i=0;i<k;i++){
            n=add(n);
            if(isnum(n)||i+1==k){
                print(n,i+1);
                break;
            }
        }
    }
    return 0;
}
