#define OK 1
#define ERROR 0
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
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
	if((*Q).front->next==NULL)
	{
	(*Q).front->next=p;//当队列是空的时候，将头指针指向p。否则直接通过尾指针向后添加。

	}
	
		
	
	(*Q).rear->next=p;
	(*Q).rear=p;
	
	
	return OK;
}
Status DeQueue(LinkQueue *Q)
{
	int e;
	QueuePtr p;

        p=(*Q).front->next;
        e=p->data;;
	(*Q).front->next=p->next;
	if((*Q).front==NULL)
    (*Q).front=(*Q).rear;
	   free(p);
	return e;

}
Status  QueueEmpty(LinkQueue S)
{
	if(S.front->next==NULL)
	return ERROR;
	else
	return OK;

}
void OutPutQueue(LinkQueue Q)
{
	QueuePtr p;
	p=Q.front->next;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
	return ;
}
void out_number(int n)
{
   LinkQueue S;
	int s1=0,s2=1;
	int i,j;
	printf("1\n");
    InitQueue(&S);
	EnQueue(&S,s1+s2);
	for(i=2;i<=n;i++)
	{

		s1=0;
		for(j=1;j<=i-1;j++)
		{
		s2=DeQueue(&S);
		printf("%d ",s2);
		EnQueue(&S,s1+s2);
		s1=s2;
		}
	printf("1\n");
	EnQueue(&S,(1+s2));	
	}

}
void main()
{
   out_number(5);
    
}


	
	







