#include <stdio.h>
#include <malloc.h>
#include "graph.h"
int visited[MAXV];
int queue[MAXV];
void CreatMG(MGraph *mg)
{
	int i,j;
	int A[7][7];
	mg->vexnum=7;
	mg->arcnum=7;
	for(i=0;i<mg->vexnum;i++)
	for(j=0;j<mg->vexnum;j++)
	{
		A[i][j]=0;
	}
	A[0][1]=A[0][2]=A[0][6]=1;
	A[1][3]=1;
	A[2][3]=A[2][5]=A[2][6]=1;
	A[3][4]=1;
	A[5][6]=1;
	for(i=1;i<mg->vexnum;i++)
		for(j=0;j<i;j++)
			A[i][j]=A[j][i];
	for(i=0;i<mg->vexnum;i++)
		for(j=0;j<mg->vexnum;j++)
			mg->arcs[i][j]=A[i][j];
}
void CreatLG(LGraph **lg,MGraph mg)
{
	int i,j;
	ArcNode *p;
     (*lg)=(LGraph *)malloc(sizeof(LGraph));
	for(i=0;i<mg.vexnum;i++)
		(*lg)->vertices[i].firstarc=NULL;
	for(i=0;i<mg.vexnum;i++)
	for(j=mg.vexnum-1;j>=0;j--)
	{
		if(mg.arcs[i][j]!=0)
		{
			p=(ArcNode *)malloc(sizeof(ArcNode));
			p->adjvex=j;
			p->weight=mg.arcs[i][j];
			p->nextarc=(*lg)->vertices[i].firstarc;
			(*lg)->vertices[i].firstarc=p;
		}
		(*lg)->vexnum=mg.vexnum;
		(*lg)->arcnum=mg.arcnum;
	}
	
}
void OutputMG(MGraph mg)
{
	int i,j;
	for(i=0;i<mg.vexnum;i++)
	{
		for(j=0;j<mg.vexnum;j++)
			printf("%3d",mg.arcs[i][j]);
		printf("\n");
	}
}

void OutputLG(LGraph *lg)
{
	int i;
	ArcNode *p;
	for(i=0;i<lg->vexnum;i++)
	{
		p=lg->vertices[i].firstarc;
		if(p)
			printf("%3d: ",i);
		while(p)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void LDFS(LGraph *lg,int i)
{
	ArcNode *p;
	printf("%3d",i);
	visited[i]=1;
	p=lg->vertices[i].firstarc;
	while(p)
	{
		if(!visited[p->adjvex])
			LDFS(lg,p->adjvex);
		p=p->nextarc;
	}
}
void MDFS(MGraph mg,int i)
{
	int j;
	printf("%3d",i);
	visited[i]=1;
	for(j=0;j<mg.vexnum;j++)
	{
		if(!visited[j]&&mg.arcs[i][j]!=0)
			MDFS(mg,j);
	}
}
void LBFS(LGraph *lg,int s)
{
	int i,v,w,front,rear;
	ArcNode *p;
	for(i=0;i<lg->vexnum;i++)
		visited[i]=0;
	front=rear=0;
	printf("%3d",s);
	visited[s]=1;
	queue[rear++]=s;
	while(front<rear)
	{
		v=queue[front++];
		for(p=lg->vertices[v].firstarc;p!=NULL;p=p->nextarc)
		{
			w=p->adjvex;
			if(visited[w]==0)
			{
				printf("%3d",w);
				visited[w]=1;
				queue[rear++]=w;
			}
		}
	}
}
void MBFS(MGraph mg,int s)
{
	int i,j,v,front,rear;
	for(i=0;i<mg.vexnum;i++)
		visited[i]=0;
	front=rear=0;
	printf("%3d",s);
	visited[s]=1;
	queue[rear++]=s;
	while(front<rear)
	{
		v=queue[front++];
		for(i=0;i<mg.vexnum;i++)
		for(j=0;j<mg.vexnum;j++)
		{
			if(mg.arcs[i][j]!=0&&visited[j]==0)
			{
				printf("%3d",j);
				visited[j]=1;
				queue[rear++]=j;
			}
		}
			
	}
}
void main()
{
	LGraph *lg;
	MGraph mg;
	int i;
	CreatMG(&mg);
	CreatLG(&lg,mg);
	printf("(1)��ǰͼ���ڽӾ����ǣ� \n");
	OutputMG(mg);
	printf("(1)��ǰͼ���ڽӱ��ǣ� \n");
	OutputLG(lg);
	for(i=0;i<mg.vexnum;i++)
		visited[i]=0;
	getchar();
	printf("(3)�ڽӱ��ʾ��ͼ��������ȱ��������ǣ� \n");
	LDFS(lg,0);
	getchar();
	for(i=0;i<mg.vexnum;i++)
		visited[i]=0;
	printf("(4)�ڽӾ����ʾ��ͼ��������ȱ��������ǣ� \n");
	MDFS(mg,0);
	getchar();
	printf("(5)�ڽӱ��ʾ��ͼ�Ĺ�����ȱ��������ǣ� \n");
	LBFS(lg,0);
	getchar();
	printf("(6)�ڽӾ����ʾ��ͼ�Ĺ�����ȱ��������ǣ� \n");
	MBFS(mg,0);
	printf("\n");
}
