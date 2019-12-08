#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=50;
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};
int pre[maxn],in[maxn],post[maxn];
int n;

Node * create(int postL,int postR,int inL,int inR)
{
	if(postL>postR) return NULL;
	Node *root=new Node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==root->data)
			break;
	}
	int numleft=k-inL;
	root->lchild=create(postL,postL+numleft-1,inL,k-1);
	root->rchild=create(postL+numleft,postR-1,k+1,inR);
	return root;
}
int num;
void BFS(Node *root)
{
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node *now=q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n) printf(" ");
		if(now->lchild!=NULL) q.push(now->lchild);
		if(now->rchild!=NULL) q.push(now->rchild);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	Node *root=create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}