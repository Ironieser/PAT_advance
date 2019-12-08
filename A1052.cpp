#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100500;
struct Node{
	int key;
	int address;
	int next;
	int flag;
}node[maxn];
bool cmp(Node a,Node b){
	if(a.flag==0||b.flag==0) return a.flag>b.flag;
	else return a.key<b.key;
}
int main()
{
	int n,begin;
	scanf("%d%d",&n,&begin);
	for(int i=0;i<n;i++){
		int ad;
		scanf("%d",&ad);
		node[ad].address=ad;
		scanf("%d%d",&node[ad].key,&node[ad].next);
	}
	int p=begin;
	int count =0;
	for(int i=0;i<maxn;i++){
		node[i].flag=0;
	}
	while(p!=-1){
		node[p].flag=1;
		count++;
		p=node[p].next;
	}
	if(count ==0) {
		printf("0 -1");
		return 0;
	}
	sort(node,node+maxn,cmp);
	printf("%d %05d\n",count,node[0].address);
	for(int i=0;i<count-1;i++){
		printf("%05d %d %05d\n",node[i].address,
			node[i].key,node[i+1].address);
	}
	printf("%05d %d -1",node[count-1].address,node[count-1].key);
	return 0;
}