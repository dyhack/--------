#define TRUE 1
#define FLASE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType data;
    struct LNode *next;


}LNode,*LinkList;
Status CreatLinkL1(LinkList *L,int n,ElemType *E)
{
	int i;
	LinkList p;
	*L=(LinkList *)malloc(sizeof(LNode));
	if(!(*L))
		return ERROR;
	(*L)->next=NULL;
	for(i=n-1;i>=0;--i)
	{
		if(!(p=(LinkList)malloc(sizeof(LNode))))
		return ERROR;
		p->data=*(E+i);
		p->next=(*L)->next;
		(*L)->next=p;
	}
	return OK;

}
Status CreatLinkL2(LinkList *L,int n,ElemType *E)
{
	int i;
	LinkList p,r;
	*L=(LinkList *)malloc(sizeof(LNode)); 
	if(!(*L))
		return ERROR;
	r=*L;
	for(i=0;i<n;i++)
	{
		if(!(p=(LinkList)malloc(sizeof(LNode))))
		return ERROR;
		p->data=*(E+i);
		r->next=p;
		r=p;
	}

	r->next=NULL;
	return OK;
}
Status InsertLinkL(LinkList *L,int i,ElemType e)
{
	LinkList s,p=*L;
	int k=0;
	while(p->next!=NULL&&k<i-1)
	{
		p=p->next;
		++k;

	}
	if(!p->next||k>i-1)
		return ERROR;
	if(!(s=(LinkList)malloc(sizeof(LNode))))
		return OVERFLOW;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
Status Del_LinkL1(LinkList L,int i,ElemType *e)
{
	int k=0;
	LinkList q,p=L;
	while(p->next!=NULL&&k<i-1)
	{
		p=p->next;
	    ++k;
	}
	if(!p->next||k>i-1)
		return ERROR;
	q=p->next;
	p->next=q->next;
	*e=q->data;
	free(q);
	return OK;
}
Status Del_LinkL2(LinkList L,ElemType e)
{
	LinkList p,q;
	p=L;
	q=L->next;
	while(q->data!=e)
	{
		p=q;
	    q=q->next;
	}
	if(q==NULL)
		return ERROR;
	p->next=q->next;
	free(q);
    return OK;
}
Status Del_LinkL3(LinkList L,ElemType e)
{
	LinkList p,q;
	int tag=FLASE;
	p=L;
	q=L->next;
	while(q!=NULL)
	{
		if(q->data==e)
		{
			p->next=q->next;
			free(q);
			tag=TRUE;
		}
		else
			p=q;
		    q=p->next;
	}
	return tag;
}
void PrintLinkL(LinkList L)
{
	LinkList p=(L)->next;
	while(p)
	{
		printf("%d->",(p)->data);
		(p)=(p)->next;
	}
	printf("∧\n");
}
void FreeLinkL(LinkList *L)
{
	LinkList p,q;
	p=*L;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*L=NULL;
}
void main()
{
	ElemType E[]={34,12,45,64,28,36,45,56};\
	int i,n=8;
	LinkList head;
	ElemType rc;
	printf("(1)表头插入法创建单链表……\n");
	if(!CreatLinkL1(&head,n,E))
	{
		printf("内存空间不够，创建失败！\n");
		return ;
	}
	else
	{
		printf("创建完成。链表输出: ");
		PrintLinkL(head);
	}
	printf("(2)表尾插入法创建单链表……\n");
	if(!CreatLinkL2(&head,n,E))
	{
		printf("内存空间不够，创建失败！\n");
		return ;
	}
	else
	{
		printf("创建完成。链表输出: ");
		PrintLinkL(head);
	}
	printf("(3)指定位置插入……\n");
    printf("输入插入位置和新元素值==>");
	scanf("%d%d",&i,&rc);
	if(!InsertLinkL(&head,i,rc))
		printf("参数错误或内存空间不够，插入失败! \n");
	else
    {
		printf("插入成功！链表输出");
		PrintLinkL(head);
	}
	printf("(4)删除指定位置结点……\n");
	printf("输入被删结点位置==>");
	scanf("%d",&i);
	if(!Del_LinkL1(head,i,&rc))
		printf("参数错误，删除失败! \n");
	else
	{
		printf("删除成功!被删除的结点是: %d\n 链表输出 :",rc);
		PrintLinkL(head);
	}
	printf("(5)删除指定值结点……\n");
	printf("输入被删结点的值==>");
	scanf("%d",&rc);
	if(!Del_LinkL2(head,rc))
		printf("输入的键值不存在！\n");
	 else
	 {
	    printf("删除成功！ 链表输出: ");
	    PrintLinkL(head);
	 }
	printf("(6)删除指定所有结点……\n");
	printf("输入被删结点的键值==>");
	scanf("%d",&rc);
	if(!Del_LinkL3(head,rc))
		printf("输入的键值不存在！\n");
	 else
	 {
	    printf("删除成功！ 链表输出: ");
	    PrintLinkL(head);
	 }
	 printf("(7)清空链表……\n");
	 FreeLinkL(&head);
	 if(!head)
		 printf("链表已清空\n");
	 else
		 printf("清空链表失败!");


}

