#include<cstdio>
#include<string>
#include<map>
#include<set>
#include<iostream>
using namespace std;
map < string , set<string > >   mpTitle ,mpAuthor,mpKey,
                                                mpPub,mpyear;
void query(map<string ,set<string> > &mp,string& str)
{
    if(mp.find(str)==mp.end()) printf("Not Found\n");
    else{//mp[str]相当于一个set<int>
        for(set<string>::iterator it = mp[str].begin();it!=mp[str].end();it++){
            cout<<*it<<endl;//注意输出格式，编号不够七位用零补充
        }
    }
}
int main()
{
    int n,m,type;
    string id;
    string title,author,key,pub,year;
    scanf("%d",&n);
    getchar();//回收换行符
    for(int i=0;i<n;i++){//读入
        cin>>id;
        getchar();
        getline(cin,title);
        mpTitle[title].insert(id);
        getline(cin,author);
        mpAuthor[author].insert(id);
        while(cin>>key){
            mpKey[key].insert(id);
            char c=getchar();
            if(c=='\n') break;
        }
        getline(cin,pub);
        mpPub[pub].insert(id);
        getline(cin,year);
        mpyear[year].insert(id);
    }
    scanf("%d",&m);//查询次数
    for(int i=0;i<m;i++){
        scanf("%d: ",&type);
        string temp;
        getline(cin,temp);
        cout<<type<<": "<<temp<<endl;
        switch(type){
            case 1:query(mpTitle,temp);break;
            case 2:query(mpAuthor,temp);break;
            case 3:query(mpKey,temp);break;
            case 4:query(mpPub,temp);break;
            case 5:query(mpyear,temp);break;
            default:break;
        }
    }
    return 0;
}
