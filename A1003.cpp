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
const int maxn=550;
const int INF=1000000000;
int n,m,st,ed,G[maxn][maxn],weight[maxn];
int d[maxn],w[maxn],num[maxn];
bool vis[maxn]={false};
void Dijkstra(int st)
{
	fill(d,d+maxn,INF);
	fill(num,num+maxn,0);
	fill(w,w+maxn,0);
	d[st]=0;
	w[st]=weight[st];
	num[st]=1;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(!vis[j]&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1){
			return;
		}
		vis[u]=true;
		for(int i=0;i<n;i++){
			if(!vis[i]&&G[u][i]!=INF){
				if(d[u]+G[u][i]<d[i]){
					d[i]=d[u]+G[u][i];
					w[i]=w[u]+weight[i];
					num[i]=num[u];
				}else if(d[u]+G[u][i]==d[i]){
					num[i]+=num[u];
					if(w[u]+weight[i]>w[i]){
						w[i]=w[u]+weight[i];
					}
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	int u,v;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d%",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	Dijkstra(st);
	printf("%d %d\n",num[ed],w[ed]);
	return 0;
}