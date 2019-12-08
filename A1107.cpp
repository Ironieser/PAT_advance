#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=10010;
int father[maxn];;
int isRoot[maxn]={0};
int course[maxn]={0};
int findFather(int x)
{
	if(x==father[x]) return x;
	else{//´øÑ¹ËõÂ·¾¶
		int F= findFather(father[x]);
		father[x]=F;
		return F;
	}
}
void init()
{
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
}
void Union(int a,int b)
{
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB){
		father[faA]=faB;
	//	faA=faB;
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		int k,h;
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&h);
			if(course[h]==0){
				course[h]=i;
			}
			Union(i,findFather(course[h]));
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0){
			ans++;
		}
	}
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i=1;i<=ans;i++){
		printf("%d",isRoot[i]);
		if(i<ans) printf(" ");
	}
	return 0;
}