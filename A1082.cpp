#include<cstdio>
#include<cstring>
char num[][10]={"ling","yi","er","san","si",
"wu","liu","qi","ba","jiu","shi"};
char ch[][10]={"ling","Shi","Bai","Qian","Wan","Yi"};
int main()
{
    char s[15];
    scanf("%s",s);
    int len=strlen(s);
    int left=0,right=len-1;
    //leftָ������λ��rightָ���λ
    if(s[0]=='-'){
        printf("Fu");
        left++;
    }

    while(left+4<=right)
        right-=4; //right ָ���leftͬһ�ڵĸ�λ
    while(left<len){//һ�ֽڿ�������
        bool flag=false;//������
        bool isprint=false;//�˽��������������˽ڵ�λ
        while(left<=right){//ÿ�ֽڿ����
            if(left>0&&s[left]=='0'){//��λΪ��
                    flag=true;
            }
            else{//��λ��Ϊ��
                if(flag){
                    printf(" ling");
                    flag=false;
                }
                //����λ����ÿ���ַ����ǰ����һ���ո�
                if(left>0) printf(" ");
                printf("%s",num[s[left]-'0']);
                isprint=true;
                if(left!=right){//�Ǹ�λ������Ҫ���ʮ��ǧ
                    printf(" %s",ch[right-left]);
                }
            }
            left++;
        }
        if(isprint&&right!=len-1){//�Ǹ�λ
            printf(" %s",ch[(len-right-1)/4+3]);
            //right �� len��ֵ�ɵó���ǰ�ֽڶ�Ϊ��һ�ֽڡ�
        }
        right+=4;//right ����4λ
    }
    return 0;
}

//void change(char s[],int len){
//    for(int i=0;i<len/2;i++){
//        char temp;
//        temp=s[i];
//        s[i]=s[len-i-1];
//        s[len-i-1]=temp;
//    }
//}
