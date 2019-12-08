#include<cstdio>
#include<cstring>
int main()
{
    int n;
    scanf("%d",&n);
    int num=0;
    char user[1000][12],key[1000][12];
    int ch[1000]={0};
    for(int j=0;j<n;j++)
    {

        scanf("%s %s",user[j],key[j]);
        int len=strlen(key[j]);
        int flag=0;
        for(int i=0;i<len;i++)
        {
            if(key[j][i]=='1')
            {
                key[j][i]='@';
                flag=1;
            }
            else if(key[j][i]=='0'){
                key[j][i]='%';
                flag=1;
            }
            else if(key[j][i]=='l'){
                key[j][i]='L';
                flag=1;
            }
            else if(key[j][i]=='O'){
                key[j][i]='o';
                flag=1;
            }
        }
        if(flag==1)
        {
            ch[j]=1;
            num++;
        }
    }
    if(num==0&&n!=1){
        printf("There are %d accounts and no account is modified",n);
        return 0;
    }
    else if(num==0&&n==1){
        printf("There is %d account and no account is modified",n);
        return 0;
    }
    else{
        printf("%d\n",num);
        for(int i=0;i<n;i++){
            if(ch[i]){
                printf("%s %s\n",user[i],key[i]);
            }
        }
    }
}
