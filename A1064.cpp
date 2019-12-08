//�Թ�����
//������
//5 5
//.....
//.*.*.
//.*S*.
//.***.
//...T*
//2 2 4 3
////////////////////
//. . . . .
//. * . * .
//. * S * .
//. * * * .
//. . . T *
//2 2 4 3
//////////////////
#include<queue>
#include<cstdio>
using namespace std;

const int maxn =100;
struct Node{//λ��x��y
    int x;//��
    int y;//��
    int step;
}s,t,node;//sΪ��㣬tΪ�յ�

int n,m;
int maze[maxn][maxn];
bool inqu[maxn][maxn]={false};//bool���飬��¼λ�ã�x,y)�Ƿ����
int X[4]={0,0,1,-1};//��������
int Y[4]={-1,1,0,0};

bool judge(int x,int y)
{
    if(x>=n||x<0||y>=m||y<0)
        return false;
    if(maze[x][y]=='*'||inqu[x][y])//�����ǽ��
        return false;
    return true;
}
int  BFS()
{
    queue<Node>Q;//�������Q
    Q.push(s);
    while(!Q.empty()){
        Node  top=Q.front();//ȡ������Ԫ��
        Q.pop();
        if(top.x==t.x&&top.y==t.y){
            return top.step;//�ҵ����ڣ����ز���
        }
        for(int i=0;i<4;i++){
            int newx=top.x+X[i];
            int newy=top.y+Y[i];
            if(judge(newx,newy)){
                node.x=newx;
                node.y=newy;
                node.step=top.step+1;
                Q.push(node);//Ҫ�жϵ����������
                inqu[newx][newy]=true;
            }
        }
    }
    return -1;//�޷��ҵ�
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int x=0;x<n;x++){
        getchar();//��ȡ���з�
        for(int y=0;y<m;y++){
            maze[x][y]=getchar();
        }
        maze[x][m+1]='\0';
    }
    scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);//�����յ������
    s.step=0;
    printf("%d\n",BFS());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
    printf("%d %d %d %d",s.x,s.y,t.x,t.y);
    return 0;
}
