#define M 8
#define N 10
#define MAXS 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct{
	int x,y;
}PosType;
typedef char MazeType[M+2][N+2];
typedef struct {
	int i;
	int j;
	int di;
}SElemType;
typedef struct 
{
	SElemType st[MAXS];
	int top;
}Stack;
Status MazePath(MazeType maze,Stack *S,PosType start,PosType end)
{
	int i,j,di,flag;
	S->top++;
	S->st[S->top].i=start.x;
	S->st[S->top].j=start.y;
	S->st[S->top].di=-1;
	maze[start.x][start.y]=-1;
	while(S->top>-1)
	{
		i=S->st[S->top].i;
		j=S->st[S->top].j;
		di=S->st[S->top].di;
		if(i==end.x&&j==end.y)
			return OK;
		flag=0;
		while(di<4&&flag==0)
		{
			di++;
			switch(di)
			{
			case 0:
				i=S->st[S->top].i+1;
				j=S->st[S->top].j;
				break;
			case 1:
				i=S->st[S->top].i;
				j=S->st[S->top].j+1;
				break;
			case 2:
				i=S->st[S->top].i-1;
				j=S->st[S->top].j;
				break;
			case 3:
				i=S->st[S->top].i;
				j=S->st[S->top].j-1;
				break;
				
			}
			if(maze[i][j]==0)
				flag=1;
			
		}
		if(flag==1)
		{
			S->st[S->top].di=di;
			S->top++;
			S->st[S->top].i=i;
			S->st[S->top].j=j;
			S->st[S->top].di=-1;
			maze[i][j]=-1;
		}
		else
		{
			maze[S->st[S->top].i][S->st[S->top].j]=0;
			S->top--;
			
		}
	}
	return ERROR;
}
void main()
{
	MazeType maze;
	int i,j;
	PosType start={1,1},end={M,N};
	Stack S;
	S.top=-1;
	while(1)
	{
	srand((unsigned)time(NULL));
	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
		{
			maze[i][j]=rand()%2;//用随机数生成的迷宫
			
		}
		for(i=0;i<=M+1;i++)
			maze[i][0]=maze[i][N+1]='1';//初始化迷宫外围的最上和最下的2行
		for(i=1;i<=N;i++)
			maze[i][0]=maze[i][N+1]='1';//初始化迷宫左右除上下的另外部分
		maze[1][1]=maze[M][N]=0;
		for(i=1;i<=M;i++)
		{
			for(j=1;j<=N;j++)
				printf("%3d",maze[i][j]);
			printf("\n");
		}
		if(MazePath(maze,&S,start,end))
		{
			printf("迷宫路径如下：\n");
			for(i=0;i<=S.top;i++)
			{
				printf("(%d,%d)",S.st[i].i,S.st[i].j);
				if((i+1)%6==0)
					printf("\n");
			}
			printf("\n");
			break;
		}
		else
		{
			printf("无路径！\n");
		}
		
		
	}
		
		
}

