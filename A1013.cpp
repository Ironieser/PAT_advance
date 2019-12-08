#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=1100;
int n,m,k;
vector <int > G[maxn];
bool vis[maxn];
int del;
void DFS(int v)
{
	if(v==del) return;
	vis[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!vis[G[v][i]])
			DFS(G[v][i]);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&del);
		fill(vis,vis+maxn,false);
		int block=0;
		for(int j=1;j<=n;j++){
			if(j!=del&&!vis[j]){
				DFS(j);
				block++;
			}
		}
		printf("%d\n",block-1);
	}
	return 0;
}