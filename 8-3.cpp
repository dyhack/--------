#include <stdio.h>
#define INF 32767
#define MAXV 30
#define OK   1
#define ERROR 0
typedef int Status;
typedef int InfoType;
typedef struct 
{
	int no;
	InfoType info;
}VertexType;
typedef struct 
{
	VertexType vexs[MAXV];
	int arcs[MAXV][MAXV];
	int vexnum,arcnum;
}MGraph;
typedef struct 
{
	int st[MAXV];
	int top;
}Stack;
typedef struct 
{
	int queue[MAXV];
	int front,rear;

}Queue;
void CreatMG(MGraph *G)
{
	int i,j;
	int A[9][9];
	(*G).vexnum=9;
	G->arcnum=11;
	for(i=0;i<G->vexnum;i++)
	{
		for(j=0;j<G->vexnum;j++)
		{
			A[i][j]=INF;//��ʼ�������ֵΪINF���ޣ�
		}
	}
	A[0][1]=6;A[0][2]=4;A[0][3]=5;
    A[1][4]=1;
	A[2][4]=1;
	A[3][5]=2;
	A[4][6]=9;
	A[4][7]=7;
	A[5][7]=4;
	A[6][8]=2;
	A[7][8]=4;
	for(i=0;i<G->vexnum;i++)
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j]=A[i][j];
}
void OutputMG(MGraph G)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{	for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j]==INF)
			{
				printf("  ��");
			}
			else 
				printf("%4d",G.arcs[i][j]);
			
		}
	printf("\n");
	}
		
}
Status ToplogicalOrder(MGraph G,Stack *S,int *ve)
{
	int i,j,count=0;
	Queue Q;
	Q.front=Q.rear=0;
	int Indegree[MAXV];
	for(i=0;i<G.vexnum;i++)
		Indegree[i]=0;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			if(G.arcs[i][j]<INF)
			{
				Indegree[j]++;//�ӵ�j�����+1����ס����i��i�Ǽ������ĳ��ȣ�
			}
	for(i=0;i<G.vexnum;i++)
		ve[i]=0;
	for(i=0;i<G.vexnum;i++)
		if(Indegree[i]==0)
			Q.queue[Q.rear++]=i;
		while(Q.front!=Q.rear)
		{
			i=Q.queue[Q.front++];
			S->st[S->top++]=i;
			count++;
			for(j=0;j<G.vexnum;j++)
			{
				if(G.arcs[i][j]<INF)
				{
					Indegree[j]--;
					if(Indegree[j]==0)
						Q.queue[Q.rear++]=j;
					if(ve[i]+G.arcs[i][j]>ve[j])
						ve[j]=ve[i]+G.arcs[i][j];
				}
			}
		}
		if(count<G.vexnum)
			return ERROR;
		return OK;

}
int Criticalpath(MGraph G)
{
	int j,k,e,l;
	char tag;
	Stack S;
	int ve[MAXV],vl[MAXV];
	S.top=0;//��ʼ��ջ��ջ����0
	if(!ToplogicalOrder(G,&S,ve))
		return 0;
	for(j=0;j<G.vexnum;j++)
	{
		vl[j]=ve[G.vexnum-1];
	}
	while(S.top!=0)
	{
		j=S.st[--S.top];//�������K��ǰһ�����
		for(k=0;k<G.vexnum;k++)
			if(G.arcs[j][k]<INF)
				if(vl[k]-G.arcs[j][k]<vl[j])
					vl[j]=vl[k]-G.arcs[j][k];

	}
	printf(" (�)����ʱ��, ���翪ʼʱ��, ����ʼʱ��, �ؼ���־\n");
	for(j=0;j<G.vexnum;++j)
	{
		for(k=0;k<G.vexnum;k++)
		{
			if(G.arcs[j][k]<INF)
			{
				e=ve[j];
				l=vl[k]-G.arcs[j][k];
				tag=(e==l)?'*':' ';
				printf(" (%d,%d)%5d\t\t%d\t        %d\t\t%c\n",j,k,G.arcs[j][k],e,l,tag);
			}

		}

	}
	return 1;




}
void main()
{
	MGraph G;
	printf("��1������ͼ���ڽӾ���....\n");
	CreatMG(&G);
	printf("��2����ǰͼ���ڽӾ�������: \n");
	OutputMG(G);
	getchar();
	printf("��3��AOE���Ĺؼ�·�����������: \n");
	Criticalpath(G);
}