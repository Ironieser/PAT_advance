#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#include<iostream>
using namespace std;
const int maxn=1100;
struct Node{
	int id;
	int layer;
};
vector<Node> adj[maxn];
bool inq[maxn];
int n,L;//nÈËÊý£¬l²ãÊý
int BFS(int v)
{
	int numForward=0;
	queue<Node> q;
	Node start;
	start.id=v;
	start.layer=0;
	q.push(start);
	inq[start.id]=true;
	while(!q.empty()){
		Node top=q.front();
		q.pop();
		int u=top.id;
		for(int i=0;i<adj[u].size();i++){
			Node next=adj[u][i];
			next.layer=top.layer+1;
			if(!inq[next.id]&&next.layer<=L){
				q.push(next);
				inq[next.id]=true;
				numForward++;
			}
		}
	}
	return numForward;
}
int main()
{
	Node user;
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++){
		user.id=i;
		int num,id;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&id);
			adj[id].push_back(user);
		}
	}
	int k,s;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		fill(inq,inq+maxn,false);
		scanf("%d",&s);
		int numForward=BFS(s);
		printf("%d\n",numForward);
	}
	return 0;
}