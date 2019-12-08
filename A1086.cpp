#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
const int maxn=40;
struct Node{
	int data;
	Node *lchild;
	Node *rchild;
};
int n;
int pre[maxn],in[maxn],post[maxn];
Node* create (int preL,int preR,int inL,int inR)
{
	if(preL>preR) return NULL;
	Node* root=new Node;
	root->data=pre[preL];
	int k=inL;
	while(in[k]!=root->data){
		k++;
	}
	int numleft=k-inL;
	root->lchild=create(preL+1,preL+numleft,inL,k-1);
	root->rchild=create(preL+numleft+1,preR,k+1,inR);
	return root;
}
int num=0;
void postorder(Node* root)
{
	if(root==NULL) return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d",root->data);
	num++;
	if(num<n){
		printf(" ");
	}
}
stack <int > st;
int main()
{
	scanf("%d",&n);
	int preIndex=0,inIndex=0;
	for(int i=0;i<2*n;i++){
		char s[10];
		int x;
		scanf("%s",s);
		if(strcmp(s,"Push")==0){
			scanf("%d",&x);
			pre[preIndex++]=x;
			st.push(x);
		}else{
			in[inIndex++]=st.top();
			st.pop();
		}
	}
	Node* root=create(0,n-1,0,n-1);
	postorder(root);
	return 0;
}
