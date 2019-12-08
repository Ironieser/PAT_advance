#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100500;
struct Node{
	char data;
	int next;
	int flag;
}node[maxn];
int main()
{
	int ahead,bhead,n;
	for(int i=0;i<maxn;i++){
		node[i].flag=0;
	}
	scanf("%d%d%d",&ahead,&bhead,&n);
	for(int i=0;i<n;i++){
		int ad;
		scanf("%d",&ad);
		scanf(" %c %d",&node[ad].data,&node[ad].next);
	}
	int p=ahead;
	while(p!=-1){
		node[p].flag=1;
		p=node[p].next;
	}
	p=bhead;
	while(node[p].flag!=1&&p!=-1){
		p=node[p].next;
	}
	if(p!=-1)
		printf("%05d",p);
	else printf("-1");
	return 0;
}
