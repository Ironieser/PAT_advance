
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<iostream>
#include<set>
using namespace std;
const int maxn=10050;

struct Node{
	int data;
	Node *lchild;
	Node *rchild;
};
int n,m,root,num=0;
int pre[maxn],in[maxn];
vector <Node*> patha,pathb;
vector<Node*>path,temp;


Node *create(int preL,int preR,int inL,int inR)
{
	if(preL > preR){
		return NULL;
	}
	Node *root=new Node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<inR;k++){
		if(in[k]==pre[preL]){
			break;
		}
	}
	int numLeft=k-inL;
	root->lchild=create(preL+1,preL+numLeft,inL,k-1);
	root->rchild=create(preL+numLeft+1,preR,k+1,inR);
	return root;
}

void findpath(Node* root,int v)
{
	if(root==NULL){
		return ;
	}
	temp.push_back(root);
	if(root->data==v){
		path=temp;
		return;
	}
	findpath(root->lchild,v);
	findpath(root->rchild,v);
	temp.pop_back();
}


int a,b;
void Judge()
{
	if(patha.size()==0&&pathb.size()==0){
		printf("ERROR: %d and %d are not found.\n",a,b);
	}else if(patha.size()==0){
		printf("ERROR: %d is not found.\n",a);
	}else if(pathb.size()==0){
		printf("ERROR: %d is not found.\n",b);
	}else{
		int x;
		int tag=0;
		for(x=0;x<patha.size()&&x<pathb.size();x++){
			if(patha[x]!=pathb[x]){
				x=x-1;
				tag=1;
				break;
			}
		}
		if(tag==1){
			printf("LCA of %d and %d is %d.\n",a,b,patha[x]->data);
		}else{
			if(patha[x-1]->data==a){
				printf("%d is an ancestor of %d.\n",a,b);
			}else{
				printf("%d is an ancestor of %d.\n",b,a);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	Node* root=create(0,n-1,0,n-1);
	while(m--){
		scanf("%d%d",&a,&b);
		if(n==0){
			printf("ERROR: %d and %d are not found.\n",a,b);
			continue;
		}
		patha.clear();
		pathb.clear();


		findpath(root,a);
		patha=path;
		temp.clear();
		path.clear();

		findpath(root,b);
		pathb=path;
		temp.clear();
		path.clear();

		Judge();
	}
	return 0;
}