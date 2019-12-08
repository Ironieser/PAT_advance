//迷宫问题
//测例：
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
struct Node{//位置x，y
    int x;//行
    int y;//列
    int step;
}s,t,node;//s为起点，t为终点

int n,m;
int maze[maxn][maxn];
bool inqu[maxn][maxn]={false};//bool数组，记录位置（x,y)是否入队
int X[4]={0,0,1,-1};//增量数组
int Y[4]={-1,1,0,0};

bool judge(int x,int y)
{
    if(x>=n||x<0||y>=m||y<0)
        return false;
    if(maze[x][y]=='*'||inqu[x][y])//如果是墙壁
        return false;
    return true;
}
int  BFS()
{
    queue<Node>Q;//定义队列Q
    Q.push(s);
    while(!Q.empty()){
        Node  top=Q.front();//取出队首元素
        Q.pop();
        if(top.x==t.x&&top.y==t.y){
            return top.step;//找到出口，返回步数
        }
        for(int i=0;i<4;i++){
            int newx=top.x+X[i];
            int newy=top.y+Y[i];
            if(judge(newx,newy)){
                node.x=newx;
                node.y=newy;
                node.step=top.step+1;
                Q.push(node);//要判断的坐标入队列
                inqu[newx][newy]=true;
            }
        }
    }
    return -1;//无法找到
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int x=0;x<n;x++){
        getchar();//读取换行符
        for(int y=0;y<m;y++){
            maze[x][y]=getchar();
        }
        maze[x][m+1]='\0';
    }
    scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);//起点和终点的坐标
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
