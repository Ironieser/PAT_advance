#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=15;
struct Node{
	int data;
	int lchild;
	int rchild;
}node[15];
int n;
bool notroot[maxn]={false};
int strToNum(char c)
{
	if(c=='-') return -1;
	else {
		notroot[c-'0']=true;
		return c-'0';
	}
}
int findroot()
{
	for(int i=0;i<n;i++){
		if(!notroot[i])
			return i;
	}
}
int post[maxn],in[maxn];
int numpost=0;
void postorder(int root)//后序遍历加反转二叉树
{
	if(root==-1)
		return;
	postorder(node[root].lchild);
	postorder(node[root].rchild);
	swap(node[root].lchild,node[root].rchild);
	//printf("%d",root);
	//numpost++;
	//if(numpost<n) printf(" ");
	//else printf("\n")
}
int numin=0;
void inorder(int root)
{
	if(root==-1)
		return;
	inorder(node[root].lchild);
	printf("%d",root);
	numin++;
	if(numin<n) printf(" ");
	else printf("\n");
	inorder(node[root].rchild);
}
int numBFS=0;
void BFS(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top=q.front();
		printf("%d",top);
		numBFS++;
		if(numBFS<n)
			printf(" ");
		else{
			printf("\n");
		}
		q.pop();
		if(node[top].lchild!=-1){
			q.push(node[top].lchild);
		}
		if(node[top].rchild!=-1){
			q.push(node[top].rchild);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char a,b;
		scanf("%*c%c %c",&a,&b);
		node[i].lchild=strToNum(a);
		node[i].rchild=strToNum(b);
	}
	int root=findroot();
	postorder(root);//后序遍历 并反转二叉树
	BFS(root);
	inorder(root);
	return 0;
}