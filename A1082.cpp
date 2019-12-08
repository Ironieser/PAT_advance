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
    //left指向待输出位，right指向个位
    if(s[0]=='-'){
        printf("Fu");
        left++;
    }

    while(left+4<=right)
        right-=4; //right 指向和left同一节的个位
    while(left<len){//一字节块进行输出
        bool flag=false;//有零标记
        bool isprint=false;//此节有输出，则输出此节单位
        while(left<=right){//每字节块输出
            if(left>0&&s[left]=='0'){//此位为零
                    flag=true;
            }
            else{//此位不为零
                if(flag){
                    printf(" ling");
                    flag=false;
                }
                //非首位，则每个字符输出前均需一个空格
                if(left>0) printf(" ");
                printf("%s",num[s[left]-'0']);
                isprint=true;
                if(left!=right){//非个位，则需要输出十百千
                    printf(" %s",ch[right-left]);
                }
            }
            left++;
        }
        if(isprint&&right!=len-1){//非个位
            printf(" %s",ch[(len-right-1)/4+3]);
            //right 和 len差值可得出当前字节段为哪一字节。
        }
        right+=4;//right 右移4位
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
