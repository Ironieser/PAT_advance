#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=10100;
int father[maxn]={0};
int n;
vector <int> G[maxn];
void init()
{
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
}
int findfather(int a)
{
	if(father[a]==a) return a;
	else{
		int f=findfather(father[a]);
		father[a]=f;
		return f;
	}
}
void Union(int a,int b)
{
	int fa=findfather(a);
	int fb=findfather(b);
	if(fa!=fb){
		father[fa]=fb;
	}
}
bool isRoot[maxn]={false};
int calBlock()
{
	int block=0;
	for(int i=1;i<=n;i++){//
		isRoot[findfather(i)]=true;
	}
	for(int i=1;i<=n;i++){
		block+=isRoot[i];
	}
	return block;
}
int maxH=0;
vector<int > temp,ans;
void DFS(int v,int Height,int pre)
{
	if(Height>maxH){
		temp.clear();
		temp.push_back(v);
		maxH=Height;
	}else if(maxH==Height){
		temp.push_back(v);
	}
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]==pre) continue;//防止回头
		DFS(G[v][i],Height+1,v);
	}
}

int main()
{
	scanf("%d",&n);
	if(n==1){//如果只有一个节点
		printf("1\n");
		return 0;
	}
	init();
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);
	}
	int block=calBlock();
	if(block!=1){
		printf("Error: %d components\n",block);
		return 0;
	}
	DFS(1,1,-1);
	ans=temp;
	DFS(ans[0],1,-1);
	for(int i=0;i<temp.size();i++){
		ans.push_back(temp[i]);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans[0]);
	for(int i=1;i<ans.size();i++){
		if(ans[i]!=ans[i-1]){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}