#define OK 1
#define ERROR 0
#include <stdio.h>
#include <malloc.h>
typedef int Status;
typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;



}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;

}LinkQueue;
Status InitQueue(LinkQueue *Q)
{
	(*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		return ERROR;
	(*Q).front->next=NULL;
	return OK;

}
Status EnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
		return ERROR;
	p->data=e;
	p->next=NULL;
	(*Q).rear->next=p;
	(*Q).rear=p;
	return OK;
}
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if((*Q).rear==(*Q).front)
		return ERROR;
	p=(*Q).front->next;
	*e=p->data;
	(*Q).front->next=p->next;
	if((*Q).rear==p)
		return ERROR;
	free(p);
	return OK;

}
void OutPutQueue(LinkQueue Q)
{
	QueuePtr p;
	p=Q.front->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
		}
	printf("\n");
	return ;
}
void main()
{
	LinkQueue Q;
	InitQueue(&Q);
	
	while(1)
	{
		int op;
	int x;
		printf("请选择操作: 1.进队 2.出队 0.退出==>");
		scanf("%d",&op);
		switch(op)
		{
		case 0:
			return ;
		case 1:
			printf("请输入进队元素: ");
			scanf("%d",&x);
			EnQueue(&Q,x);
			printf("队内元素为: \n");
			OutPutQueue(Q);
			break;
		case 2:
			if(DeQueue(&Q,&x))
			{
				printf("出队元素为：[%d],队内元素为:\n",x);
				OutPutQueue(Q);
			}
			else
				printf("队空!\n");
			break;
		}
	}


}

