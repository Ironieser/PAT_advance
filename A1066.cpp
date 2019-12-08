#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=104;
struct Node{
	int data,height;
	Node* lchild,*rchild;
};
Node* newNode(int data)
{
	Node *root=new Node;
	root->data=data;
	root->height=1;
	root->lchild=root->rchild=NULL;
	return root;
}
int getHeight(Node *root)
{
	if(root==NULL) return 0;
	else return root->height;
}
int  getFac(Node* root)
{
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void updateHeight(Node * root)
{
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
void L(Node * &root)
{
	Node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void R(Node* &root)
{
	Node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void insert(Node * &root,int data)
{
	if(root==NULL){
		root=newNode(data);
		return;
	}
	if(data<root->data){
		insert(root->lchild,data);
		updateHeight(root);
		if(getFac(root)==2){//LÐÍ
			if(getFac(root->lchild)==1){//LL
				R(root);
			}else if(getFac(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}else{ 
		insert(root->rchild,data);
		updateHeight(root);
		if(getFac(root)==-2){//RÐÍ
			if(getFac(root->rchild)==-1){//RR
				L(root);
			}else if(getFac(root->rchild)==1){//RL
				R(root->rchild);
				L(root);
			}
		}
	}
}
int main()
{
	int n,v;
	Node *root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d",root->data);
	return 0;
}