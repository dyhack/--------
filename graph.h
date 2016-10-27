#define MAXV 30
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
typedef struct ArcNode
{
	int adjvex;
	int weight;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode
{
	VertexType data;
	ArcNode *firstarc;
	
}VNode;
typedef VNode AdjList[MAXV];
typedef struct 
{
	VNode vertices[MAXV];
	int vexnum,arcnum;
}LGraph;