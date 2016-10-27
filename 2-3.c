#define OK 1
#define ERROR 0
#include <stdio.h>
#include <stdlib.h>
typedef int Status;
typedef struct LNode
{
	int no;
	int pass;
	struct LNode *next;

}LNode,*LinkList;
Status CreatJosephus(LinkList *Tail,int n,int M[])
{
	int i;
	LinkList p,head;
	for(i=1;i<=n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		if(p==NULL)
			return ERROR;
		p->no=i;
		p->pass=M[i-1];
		if(i==1)
			head=p;
		else
		 (*Tail)->next=p;
		(*Tail)=p;
	}
	(*Tail)->next=head;
	return OK;
}
Status Josephus(LinkList *Tail,int m)
{
	LinkList q,p=(*Tail)->next,pre=*Tail;
	int k;
	if(m<1)
	{
		return ERROR;
	}
	while(p=NULL)
	{
		for(k=1;k<m;k++)
		{
			pre=p;
			p=p->next;
		}
		printf("%4d",p->no);
		q=p;
		m=q->pass;
		p=p->next;
		pre->next=pre->next->next;
		if(p==q)
			p=NULL;
		free(q);

	}
	printf("\n");
	return OK;
}
void OutputJosephus(LinkList Tail)
{
	LinkList p=Tail;
	do{

		p=p->next;
		printf("%d(%d) ",p->no,p->pass);

	}while(p!=Tail);
		printf("\n");
}
void main()
{
	int M[]={4,7,14,3,22,1,5,9,11,6,8,2};
	int n=12;
	int m=0;
	LinkList tail=NULL;
	printf("(1)创建Josephus环为： ");
	if(CreatJosephus(&tail,n,M))
	{
		printf("(2)当前Josephus环为： ");
		OutputJosephus(tail);
		printf("请输入初始密码： ");
        while(m<=0)
			scanf("%d",&m);
		printf("(3)当前Josephus环求解结果为： ");
		Josephus(&tail,m);
		

	}
	else
		printf("创建Josephus失败!\n");
}
