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
void init()//�Ƚ��д��
{
    for(int i=0;i<13;i++){
    //13��Ӧ�û�����Ϊ tam������ tam tret�� ����Ҫ
    //   ��������������
        //��λ��ʮλ��Ϊ0
        numtostr[i]=unitDigit[i];
        strtonum[unitDigit[i]]=i;
        //��λΪ0�� ��λΪ0
        numtostr[i*13]=tenDigit[i];
        strtonum[tenDigit[i]]=i*13;
    }
    for(int i=1;i<13;i++){//ʮλ
        for(int j=1;j<13;j++){//��λ
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
    scanf("%d%*c",&n);//��ȥ��β���з�
//    getchar();
    while(n--){
        string str;
        getline(cin,str);//��string��¼��һ���ַ������������з�ֹͣ��
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
