#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
struct Node
{
	int data;
	Node *lchild;
	Node *rchild;
};
vector <int> origin,pre,post,preM,postM;
void insert(Node* &root,int data)
{
	if(root==NULL){
		root=new Node;
		root->data=data;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(data < root->data){
		insert(root->lchild,data);
	}else{
		insert(root->rchild,data);
	}
}
void preorder(Node* root)
{
	if(root==NULL) return;
	pre.push_back(root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void mirPreorder(Node* root)
{
	if(root==NULL)  return;
	preM.push_back(root->data);
	mirPreorder(root->rchild);
	mirPreorder(root->lchild);
}
void postorder(Node* root)
{
	if(root==NULL) return ;
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
void mirPostorder(Node* root)
{
	if(root==NULL) return ;
	mirPostorder(root->rchild);
	mirPostorder(root->lchild);
	postM.push_back(root->data);
}
void print(vector<int>vi)
{
	printf("YES\n");
	for(int i=0;i<vi.size();i++){
		if(i!=0) printf(" ");
		printf("%d",vi[i]);
	}
}
int main()
{
	int n,data;
	Node* root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(root,data);
		origin.push_back(data);
	}
	preorder(root);
	mirPreorder(root);
	postorder(root);
	mirPostorder(root);
	if(pre==origin){
		print(post);
	}else if(preM==origin){
		print(postM);
	}else{
		printf("NO");
	}
}