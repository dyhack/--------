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
	printf("��\n");
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
	printf("(1)��ͷ���뷨������������\n");
	if(!CreatLinkL1(&head,n,E))
	{
		printf("�ڴ�ռ䲻��������ʧ�ܣ�\n");
		return ;
	}
	else
	{
		printf("������ɡ��������: ");
		PrintLinkL(head);
	}
	printf("(2)��β���뷨������������\n");
	if(!CreatLinkL2(&head,n,E))
	{
		printf("�ڴ�ռ䲻��������ʧ�ܣ�\n");
		return ;
	}
	else
	{
		printf("������ɡ��������: ");
		PrintLinkL(head);
	}
	printf("(3)ָ��λ�ò��롭��\n");
    printf("�������λ�ú���Ԫ��ֵ==>");
	scanf("%d%d",&i,&rc);
	if(!InsertLinkL(&head,i,rc))
		printf("����������ڴ�ռ䲻��������ʧ��! \n");
	else
    {
		printf("����ɹ����������");
		PrintLinkL(head);
	}
	printf("(4)ɾ��ָ��λ�ý�㡭��\n");
	printf("���뱻ɾ���λ��==>");
	scanf("%d",&i);
	if(!Del_LinkL1(head,i,&rc))
		printf("��������ɾ��ʧ��! \n");
	else
	{
		printf("ɾ���ɹ�!��ɾ���Ľ����: %d\n ������� :",rc);
		PrintLinkL(head);
	}
	printf("(5)ɾ��ָ��ֵ��㡭��\n");
	printf("���뱻ɾ����ֵ==>");
	scanf("%d",&rc);
	if(!Del_LinkL2(head,rc))
		printf("����ļ�ֵ�����ڣ�\n");
	 else
	 {
	    printf("ɾ���ɹ��� �������: ");
	    PrintLinkL(head);
	 }
	printf("(6)ɾ��ָ�����н�㡭��\n");
	printf("���뱻ɾ���ļ�ֵ==>");
	scanf("%d",&rc);
	if(!Del_LinkL3(head,rc))
		printf("����ļ�ֵ�����ڣ�\n");
	 else
	 {
	    printf("ɾ���ɹ��� �������: ");
	    PrintLinkL(head);
	 }
	 printf("(7)���������\n");
	 FreeLinkL(&head);
	 if(!head)
		 printf("���������\n");
	 else
		 printf("�������ʧ��!");


}

