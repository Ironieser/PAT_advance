#include<cstdio>
#include<iostream>
#include<map>
#include<string>
using namespace std;
string unitDigit[13]={"tret","jan", "feb", "mar", "apr",
 "may","jun","jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13]={"tret","tam","hel", "maa", "huh", "tou", "kes", "hei",
"elo", "syy", "lok", "mer", "jou"};
string numtostr[170];
map< string , int > strtonum;
void init()//先进行打表
{
    for(int i=0;i<13;i++){
    //13对应得火星文为 tam，而非 tam tret， 故需要
    //   进行特殊情况打表
        //百位，十位数为0
        numtostr[i]=unitDigit[i];
        strtonum[unitDigit[i]]=i;
        //个位为0， 百位为0
        numtostr[i*13]=tenDigit[i];
        strtonum[tenDigit[i]]=i*13;
    }
    for(int i=1;i<13;i++){//十位
        for(int j=1;j<13;j++){//个位
            string str=tenDigit[i]+" "+unitDigit[j];
            numtostr[13*i+j]=str;
            strtonum[str]=13*i+j;
        }
    }
}
int main()
{
    init();
    int n;
    scanf("%d%*c",&n);//除去行尾换行符
//    getchar();
    while(n--){
        string str;
        getline(cin,str);//向string中录入一行字符串，遇到换行符停止；
        if(str[0]>='0'&&str[0]<='9'){
            int t=0;
            for(int i=0;i<str.size();i++){
                t=t*10+str[i]-'0';
            }
            cout<<numtostr[t]<<endl;
        }else{
            cout<<strtonum[str]<<endl;
        }
    }
    return 0;
}
