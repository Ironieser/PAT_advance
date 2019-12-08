#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100050;
vector <int > node[maxn];
int n,num;
double p,r,minDepth=maxn+1;
void DFS(int index,int depth)
{
	if(node[index].size()==0){
		if(depth<minDepth){
			minDepth=depth;
			num=1;
		}else if(depth==minDepth){
			num++;
		}
		return ;
	}
	for(int i=0;i<node[index].size();i++){
		DFS(node[index][i],depth+1);
	}
}
int main()
{
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	for(int i=0;i<n;i++){
		int k,child;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[i].push_back(child);
		}
	}
	DFS(0,0);
	printf("%.4lf %d",p*pow(1+r,minDepth),num);
	return 0;
}