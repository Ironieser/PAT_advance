#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#include<iostream>
using namespace std;
const int maxn=2100;
map<int ,string>idToString;
map<string,int >stringToId;
map<string,int >Gang;// head's string  and member
int G[maxn][maxn]={0},weight[maxn]={0};
int n,k,numPerson=0;
bool vis[maxn]={false};
int change(string str)
{
	if(stringToId.find(str)!=stringToId.end()){
		return stringToId[str];
	}else{
		stringToId[str]=numPerson;
		idToString[numPerson]=str;
		return numPerson++;
	}
}
void DFS(int now,int &head,int &numMember,int &totalValue)
{
	numMember++;
	vis[now]=true;
	if(weight[now]>weight[head]){
		head=now;
	}
	for(int i=0;i<numPerson;i++){
		if(G[now][i]>0){
			totalValue+=G[now][i];
			G[now][i]=G[i][now]=0;
			if(!vis[i]){
				DFS(i,head,numMember,totalValue);
			}
		}
	}
}
void DFSTrave()
{
	for(int i=0;i<numPerson;i++){
		if(!vis[i]){
			int head=i,numMember=0,totalValue=0;
			DFS(i,head,numMember,totalValue);
			if(numMember>2&&totalValue>k){
				Gang[idToString[head]] = numMember;
			}
		}
	}

}
int main()
{
	scanf("%d%d",&n,&k);
	string str1,str2;
	for(int i=0;i<n;i++){
		int w;
		cin>>str1>>str2>>w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1]+=w;
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;
	}
	DFSTrave();
	cout<<Gang.size()<<endl;
	map<string,int>::iterator it;
	for(it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}