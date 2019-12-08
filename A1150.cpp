#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<iostream>
#include<set>
using namespace std;
const int maxn=210;
const int INF=1000000000;
int G[maxn][maxn];
int vis[maxn];
int n,m,k;
int minX=-1,minDis=INF;
void findPath(int i)
{
	fill(vis,vis+maxn,false);
	int numN;
	scanf("%d",&numN);
	int ans=0;
	vector<int >pathN(numN);
	for(int j=0;j<numN;j++){
		scanf("%d",&pathN[j]);
	}
	bool isCycle=true;
	for(int j=0;j<numN-1;j++){		
		if(G[pathN[j]][pathN[j+1]]!=INF){
			ans+=G[pathN[j]][pathN[j+1]];
			vis[pathN[j]]=true;

		}else{
			isCycle=false;
			break;
		}
	}
	if(!isCycle){
		printf("Path %d: NA (Not a TS cycle)\n",i);
		return;
	}
	bool isVis=true;
	for(int j=1;j<=n;j++){
		if(vis[j]==false){
			isVis=false;
			break;
		}
	}
	if(isVis&&pathN[0]==pathN[numN-1]){
		if(ans<minDis){
			minDis=ans;
			minX=i;
		}
		if(numN==n+1){
			printf("Path %d: %d (TS simple cycle)\n",i,ans);
		}else{
			printf("Path %d: %d (TS cycle)\n",i,ans);
		}
	}else{
		printf("Path %d: %d (Not a TS cycle)\n",i,ans);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=G[v][u]=w;
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		findPath(i);
	}
	printf("Shortest Dist(%d) = %d",minX,minDis);
	return 0;
}