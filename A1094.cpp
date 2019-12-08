#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=120;
vector<int >child[maxn];
int n,m,maxGen=0,maxNum=0;
bool notRoot[maxn]={false};
int findRoot()
{
	for(int i=0;i<n;i++){
		if(!notRoot[i])
			return i;
	}
}
int hashGen[maxn]={0};
void DFS(int index,int depth)
{
	hashGen[depth]++;
	for(int i=0;i<child[index].size();i++){
		DFS(child[index][i],depth+1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int k=0,father,ch;
		scanf("%d%d",&father,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&ch);
			notRoot[ch]=true;
			child[father].push_back(ch);
		}
	}
	int root=findRoot();
	DFS(1,1);
	for(int i=1;i<maxn;i++){
		if(hashGen[i]>maxNum){
			maxNum=hashGen[i];
			maxGen=i;
		}
	}
	printf("%d %d",maxNum,maxGen);
	return 0;
}