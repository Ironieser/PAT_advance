#include<stdio.h>
#include<string.h>
//���󹫹���׺��Ϊ�󹫹�ǰ׺
int main()
{
    char s[101][257];
    int n;
    int minlen=258;
    scanf("%d",&n);
    getchar();
//*******************************
//fgets()�е��ڴ泤�ȣ������һ��'\n'��'\0'
//����󳤶�Ϊ��¼���ַ�����+2��
//����������Ե㲻ͨ���������Ϊ�߽����⣬
//�����㷨���⡣
//********************************
    for(int i=0;i<n;i++){
        fgets(s[i],258,stdin);  //¼���ַ�������ת
        int len=strlen(s[i]);//��β�л��з������ȼ�һ
        s[i][len-1]='\0';
        len--;
//        gets(s[i]);
//        int len=strlen(s[i]);
        len<minlen?minlen=len:1;
        for(int j=0;j<len/2;j++){//��ת�洢
            char temp;
            temp=s[i][len-j-1];
            s[i][len-j-1]=s[i][j];
            s[i][j]=temp;
        }
    }
    int num=0;
    for(int i=0;i<minlen;i++){//�ж�j���ַ����У�ǰi���ַ����
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

//�㷨����  ����������
//����ÿÿһ�仰����󼸸��ַ�ֻҪ����ͬ�Ĳ��֣������
//���ޣ������nai
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
//    int num=0;//��¼��β׺����
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
