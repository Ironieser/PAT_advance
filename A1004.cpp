#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=150;
vector<int > node[maxn];
int n,m;
int leaf[maxn]={0};
int maxH=-1;
void DFS(int index,int depth)
{
	maxH=max(maxH,depth);
	if(node[index].size()==0){
		leaf[depth]++;
		return ;
	}
	for(int i=0;i<node[index].size();i++){
		DFS(node[index][i],depth+1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int father,child,k;
		scanf("%d%d",&father,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[father].push_back(child);
		}
	}
	DFS(1,1);
	for(int i=1;i<=maxH;i++){
		printf("%d",leaf[i]);
		if(i<maxH)
			printf(" ");
	}
	return 0;
}