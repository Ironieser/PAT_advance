#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=150;
struct Node{
	int data;
	vector<int> child;
}node[maxn];
int n,m,s;
vector<int> path;
void DFS(int index,int sum)
{
	if(sum>s) return ;
	if(sum==s){
		if(node[index].child.size()!=0)
			return;
		else{
			for(int i=0;i<path.size();i++){
				printf("%d",node[path[i]].data);
				if(i<path.size()-1) printf(" ");
			}
			printf("\n");
			return ;
		}
	}
	if(node[index].child.size()==0){
		return;
	}
	for(int i=0;i<node[index].child.size();i++){
		path.push_back(node[index].child[i]);
		DFS(node[index].child[i],sum+node[node[index].child[i]].data);
		path.pop_back();
	}

}
bool cmp(int  a,int b)
{
	return node[a].data>node[b].data;
}
int main()
{
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&node[i].data);
	}
	for(int i=0;i<m;i++){
		int father,k;
		scanf("%d%d",&father,&k);
		for(int j=0;j<k;j++){
			int child;
			scanf("%d",&child);
			node[father].child.push_back(child);
		}
		sort(node[father].child.begin(),node[father].child.end(), cmp);
	}
	path.push_back(0);
	DFS(0,node[0].data);
	return 0;
}