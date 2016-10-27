#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;
typedef struct 
{
	QElemType *base;
	int front;
	int rear;

}SqQueue;
Status InitQueue(SqQueue *Q)
{
	(*Q).base=(QElemType *)malloc(MAXSIZE*sizeof(QElemType));
	if(!(*Q).base)
		return ERROR;
	  (*Q).front=(*Q).rear=0;
	  return OK;
}
Status EnQueue(SqQueue *Q,QElemType e)
{
	if((*Q).rear==MAXSIZE)
		return ERROR;
	   (*Q).base[(*Q).rear]=e;
	   (*Q).rear=((*Q).rear+1)%MAXSIZE;
	   return OK;
}
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if((*Q).rear==(*Q).front)
		return ERROR;
	e=(*Q).base[(*Q).front];
	(*Q).front=((*Q).front+1)%MAXSIZE;
	return OK;
}
void OutputQueue(SqQueue Q)
{
	while(Q.front!=Q.rear)
	{
		printf("%d ",Q.base[Q.front]);
	  Q.front=(Q.front+1)%MAXSIZE;
    }
	printf("\n");
}
void main()
{
	SqQueue Q;
	InitQueue(&Q);
	int op,x;
	while(1)
	{
		printf("����ѡ�� 1.���� 2.����  0.�˳�==>");
		scanf("%d",&op);
		switch(op)
		{
		case 0:
			return ;
		case 1:
			printf("���������Ԫ��: ");
			scanf("%d",&x);
			if(!EnQueue(&Q,x))
				printf("��������\n");
			else
			{
				printf("���ӳɹ�������Ԫ��Ϊ��\n");
				OutputQueue(Q);

			}
			break;
		case 2:
			if(DeQueue(&Q,&x))
			{
				printf("����Ԫ��Ϊ: [%d],����Ԫ��Ϊ: \n",x);
				OutputQueue(Q);

			}
			else
				printf("�ӿ�! \n");
				break;

		} 

	}

}