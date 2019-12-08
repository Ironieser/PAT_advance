#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100050;
struct Node{
	double data;
	vector <int> child;
}node[maxn];
int n;
double p,r,sum=0;
void DFS(int index , int depth)
{
	if(node[index].child.size()==0){
		sum+=p*pow(1+r,depth)*node[index].data;
		return ;
	}
	for(int i=0;i<node[index].child.size();i++){
		DFS(node[index].child[i],depth+1);
	}
}
int main()
{
	int k,child;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&child);
				node[i].child.push_back(child);
			}
		}else{
			scanf("%lf",&node[i].data);
		}
	}
	DFS(0,0);
	printf("%.1lf",sum);
	return 0;

}