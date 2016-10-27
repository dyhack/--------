#define OK  1
#define ERROR 0
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int status;
typedef int ElemType;
typedef struct LNode{
        ElemType data;
		struct LNode *next;


}LNode,*LinkList;
void CreateList(LinkList *L,int n)
{
	int i;
	LNode *p,*q,*s;
	(*L)=(LinkList)malloc(sizeof(LNode));
	 (*L)->next=NULL;
	for(i=0;i<n;i++)
	{
		s=(LinkList)malloc(sizeof(LNode));
		printf("�������%d�����ֵ��",i+1);
		scanf("%d",&s->data);
		p=(*L);
		q=(*L)->next;
		while(q!=NULL&&q->data<=s->data)
		{
			p=q;
			q=q->next;

		}
		s->next=p->next;
		p->next=s;
	}
}
void Mergesort(LinkList *A,LinkList *B,LinkList *C)
{
	LNode *pa,*pb,*pc;
	pa=(*A)->next;
	pb=(*B)->next;
	*C=pc=*A;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		
		
	}
      pc->next=pa?pa:pb;
	  free(*B);

}
void OutputList(LinkList L)
{
	LinkList p=L->next;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;

	}
	printf("��\n");


}
void main()
{
	LinkList La,Lb,Lc;
	int na=5,nb=4;
	printf("(1)������������A����\n");
	CreateList(&La,na);
	printf("A��������� ");
	OutputList(La);
	printf("(2)������������B����\n");
	CreateList(&Lb,nb);
	printf("B�������:  ");
	OutputList(Lb);
    printf("(3)�鲢A,B��C,C���������򡭡�\n");
	Mergesort(&La,&Lb,&Lc);
    printf("C�������:  ");
	OutputList(Lc);

}