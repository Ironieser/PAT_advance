#include<cstdio>
#include<queue>
using namespace std;
const int maxnp=1050;
struct mice
{
	int rank;
	int weight;
}mouse[maxnp];
int main()
{
	int np,ng;
//	int wei[maxnp],ra[maxnp];
	scanf("%d %d",&np,&ng);
	for(int i=0;i<np;i++){
		scanf("%d",&mouse[i].weight);
	}
	queue < int > qu ;
	for(int i=0;i<np;i++){
		int order;
		scanf("%d",&order);
		qu.push(order);
	}
	int group,temp=np;
	while(qu.size()!=1){
		if(temp%ng!=0) group=temp/ng+1;
		else group=temp/ng;
		for(int i=0;i<group;i++){
			int k=qu.front();
			for(int j=0;j<ng;j++){
				if(i*ng+j>=temp) break;//最后一组不够时，退出
				int front = qu.front();
				if(mouse[front].weight>mouse[k].weight){
					k=front;
				}
				mouse[front].rank=group+1;
				qu.pop();
			}
			qu.push(k);
		}
		temp=group;
	}
	mouse[qu.front()].rank=1;
	for(int i=0;i<np;i++){
		if(i!=0) printf(" ");
		printf("%d",mouse[i].rank);
	}
	return 0;
}