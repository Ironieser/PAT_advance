#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct Node{
	int x,y,z;
}node;
int N,M,L,T;
int pixel[1300][150][70]={0};
bool inq[1300][150][70]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int x,int y, int z)
{
	if(x<0||y<0||z<0||x>=N||y>=M||z>=L) return false;
	if(pixel[x][y][z]==1&&!inq[x][y][z])
		return true;
	else
		return false;
}
int BFS(int x,int y,int z){
	int num1=0;
	queue<Node>Q;
	node.x=x,node.y=y,node.z=z;
	Q.push(node);
	inq[x][y][z]=true;
	while(!Q.empty()){
		Node top=Q.front();
		Q.pop();
		num1++;//队列每出一个1  num1++;
		for(int i=0;i<6;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			int newZ=top.z+Z[i];
			if(judge(newX,newY,newZ)){
				node.x=newX;
				node.y=newY;
				node.z=newZ;
				Q.push(node);
				inq[newX][newY][newZ]=true;
			}
		}
	}
	if(num1>=T) return num1;
	else return 0;
}
int main()
{
	scanf("%d%d%d%d",&N,&M,&L,&T);
	for(int z=0;z<L;z++){
		for(int x=0;x<N;x++){
			for(int y=0;y<M;y++){
				scanf("%d",&pixel[x][y][z]);
			}
		}
	}
	int ans=0;
	for(int z=0;z<L;z++){
		for(int x=0;x<N;x++){
			for(int y=0;y<M;y++){
				if(pixel[x][y][z]==1&&inq[x][y][z]==false){
					ans+=BFS(x,y,z);
				}
			}
		}
	}
	printf("%d",ans);
}