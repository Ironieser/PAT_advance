#include<stdio.h>
#include<string.h>
//将求公共后缀改为求公共前缀
int main()
{
    char s[101][257];
    int n;
    int minlen=258;
    scanf("%d",&n);
    getchar();
//*******************************
//fgets()中的内存长度，需外加一个'\n'和'\0'
//即最大长度为需录入字符长度+2；
//遇到个别测试点不通过的问题多为边界问题，
//而非算法问题。
//********************************
    for(int i=0;i<n;i++){
        fgets(s[i],258,stdin);  //录入字符串并反转
        int len=strlen(s[i]);//行尾有换行符，长度减一
        s[i][len-1]='\0';
        len--;
//        gets(s[i]);
//        int len=strlen(s[i]);
        len<minlen?minlen=len:1;
        for(int j=0;j<len/2;j++){//反转存储
            char temp;
            temp=s[i][len-j-1];
            s[i][len-j-1]=s[i][j];
            s[i][j]=temp;
        }
    }
    int num=0;
    for(int i=0;i<minlen;i++){//判断j个字符串中，前i个字符相等
        char temp=s[0][i];
        int flag=1;
        for(int j=1;j<n;j++){
                if(s[j][i]!=temp){
                    flag=0;
                    break;
                }
        }
        if(flag)
            num++;
        else
            break;
    }
    if(num==0){
        printf("nai");
        return 0;
    }
    for(int i=num-1;i>=0;i--){
        printf("%c",s[0][i]);
    }
    return 0;
}

//算法错误  题意理解错误
//题意每每一句话的最后几个字符只要有相同的部分，便输出
//若无，则输出nai
//#include<cstdio>
//#include<cstring>
//struct Sen
//{
//    char ch[300];
//    int flag=0;
//}sen[110],temp;
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    getchar();
//    int num=0;//已录入尾缀数量
//    while(n--)
//    {
//        fgets(temp.ch,300,stdin);
//        int len=strlen(temp.ch);
//        for(int i=0, j=0;i<len-1;i++)
//        {
//
//            if(temp.ch[i]==' '){
//                for(;j>=0;j--){
//                    sen[0].ch[j]='\0';
//                }
//                j=0;continue;
//            }
//            else{
//                sen[0].ch[j++]=temp.ch[i];
//            }
//        }
//        int tag=0;
//        for(int i=1;i<=num;i++){
//            if((strcmp(sen[0].ch,sen[i].ch))==0)
//                {sen[i].flag++;break;tag=1;}
//        }
//        if(!tag)
//        {
//            num++;
//            sen[num]=sen[0];
//            sen[num].flag++;
//
//        }
//         for(int j=0;j<300;j++){
//            sen[0].ch[j]='\0';
//        }
//    }
//    int max=1;
//    for(int i=1;i<num;i++){
//        if(sen[i].flag>sen[max].flag)
//            max=i;
//    }
//    if(sen[max].flag>1)
//        printf("%s",sen[max].ch);
//    else
//        printf("nai");
//}
