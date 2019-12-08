#include<cstdio>
int main()
{
    int n;
    int now=0,to,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&to);
        if(to>now){
            s+=(to-now)*6;
        }
        else s+=(now - to)* 4;
        now=to;
        s+=5;
    }
    printf("%d",s);
    return 0;
}
