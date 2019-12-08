#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100050;
//struct Node{
//	double data;
//	vetcor <int> child;
//}node[maxn];
vector <int> child[maxn];
double p,r;
int n,maxDepth=0,num=0;
void DFS(int root,int depth)
{
	if(child[root].size()==0){
		if (depth>maxDepth){
			maxDepth=depth;
			num=1;
		}else if(depth==maxDepth){
			num++;
		}
		return ;
	}
	for(int i=0;i<child[root].size();i++){
		DFS(child[root][i],depth+1);
	}
}
int main()
{
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	int father,root;
	for(int i=0;i<n;i++){

		scanf("%d",&father);
		if(father!=-1)
			child[father].push_back(i);
		else root=i;
	}
	DFS(root,0);
	printf("%.2lf %d",p*pow((1+r),maxDepth),num);
	return 0;
}