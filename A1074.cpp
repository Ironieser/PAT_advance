#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100050;
struct Node{
	int data;
	int next;
	int address,order;
}node[maxn];
bool cmp(Node a,Node b)
{
	return a.order<b.order;
};
int main()
{
	int head,n,k;
	scanf("%d%d%d",&head,&n,&k);
	for(int i=0;i<maxn;i++){
		node[i].order=maxn;
	}
	for(int i=0;i<n;i++){
		int ad,da,ne;
		scanf("%d%d%d",&ad,&da,&ne);
		node[ad].data=da;
		node[ad].next=ne;
		node[ad].address=ad;
	}
	int p=head;
	int count=0;
	while(p!=-1){
		node[p].order=count++;
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	n=count;
	for(int i=0;i<n/k;i++){
		for(int j=(i+1)*k-1;j>i*k;j--){
			printf("%05d %d %05d\n",node[j].address,
				node[j].data,node[j-1].address);		
		}
		printf("%05d %d ",node[i*k].address,node[i*k].data);
		if(i<n/k-1){
			printf("%05d\n",node[(i+2)*k-1].address);
		}else{
			if(n%k==0){
				printf("-1\n");
			}else{
				printf("%05d\n",node[(i+1)*k].address);
				for(int i=n/k*k;i<n;i++){
					printf("%05d %d ",node[i].address,node[i].data);
					if(i+1<n) printf("%05d\n",node[i+1].address);
					else printf("-1");
				}
			}
		}
	}
	return 0;
}