#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
bool isCh(char &c)
{
    if(c>='a'&&c<='z'){
        return true;
    }else if(c>='A'&&c<='Z'){//如果为大写字母，转换为小写字幕
        c=c-'A'+'a';
        return true;
    }else if(c>='0'&&c<='9'){
        return true;
    }else return false;
}
map <string ,int > word;
int main()
{
    string sen;
    getline(cin,sen);
    string  maxstr="0";
    word[maxstr]=0;
    int len=(int)sen.size();
    for(int i=0;i<len;i++){
        string str;
        while(!isCh(sen[i])&&i<len){
            i++;
        }
        while(isCh(sen[i])&&i<len){
            str+=sen[i];
            i++;
        }
        if(word.find(str)!=word.end()) word[str]++;
        else word[str]=1;

        if(word[str]>word[maxstr]){//判断是否为数量最多的单词
            maxstr=str;
        }
    }
    cout<<maxstr<<" "<<word[maxstr];
    return 0;
}
