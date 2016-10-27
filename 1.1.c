#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define MAXSIZE	6
#define INCREMENT 10
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int Status;
typedef int ElemType;
typedef struct {
     ElemType *elem;
	 int length;
	 int listsize;
}SqList;
Status InitList(SqList *L)
{
	(*L).elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!((*L).elem))
		exit(OVERFLOW);
	L->length=0;
	(*L).listsize=MAXSIZE;
	return OK;

}
Status InserList(SqList *L,int i,ElemType e)
{
	if(i<1||i>(*L).length+1)
		return ERROR;
	ElemType *p;
	int j;
	if((*L).length>=(*L).listsize)
	{
		p=(ElemType *)realloc((*L).elem,((*L).listsize+INCREMENT)*sizeof(ElemType));
		if(!p)
			exit (OVERFLOW);
		(*L).elem=p;
		(*L).listsize+=INCREMENT;
	}
	for(j=(*L).length-1;j>=i-1;--j)
		(*L).elem[j+1]=(*L).elem[j];
	(*L).elem[i-1]=e;
	(*L).length++;
	return OK;
}//InsertList
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d ",L.elem[i]);
	}
		printf("\n");
	
}
int SearchList(SqList L,ElemType e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		
	
		if(e==L.elem[i])
		return i;
	}
	
	return  -1;
}
int Del_List1(SqList *L,ElemType e)
{
	int i,j;
	for(i=0;i<(*L).length;i++)
	
		if((*L).elem[i]==e)
			break;
		if(i<(*L).length)
		{
			
		   for(j=i;j<(*L).length-1;j++)
				(*L).elem[j]=(*L).elem[j+1];
		   (*L).length--;
			return i;
		}
		return -1;
	}

Status Del_List2(SqList *L,int i,ElemType *e)
{
	if(i<1||i>(*L).length)
		return ERROR;
	int j;
	*e=(*L).elem[i-1];
	for(j=i;j<(*L).length;j++)
	{
		(*L).elem[j-1]=(*L).elem[j];
	}
		--(*L).length;
	    return OK;

}
void main()
{
	SqList LL;
	ElemType x;
	int r,i;
	printf("(1)��ʼ��˳���......\n");
	if(!InitList(&LL))
		return ;
	printf("��ʼ���ɹ���");
	printf("(2)˳���Ĳ������.....\n");
	while(1)
	{
		printf("�������Ԫ�ص�ֵ(0:����)=>");
		scanf("%d",&x);
		if(x==0)
			break;
		printf("��������λ��");
		scanf("%d",&r);
		InserList(&LL,r,x);
		printf("���Ա����");
		PrintList(LL);
	}
	printf("(3)˳����ϵĲ��Ҳ���....\n");
	while(1)
	{
		printf("������ҵ�Ԫ�ص�ֵ(0:����)=>");
		scanf("%d",&x);
		if(x==0)
			break;
		r=SearchList(LL,x);
		if(r<0)
			printf("û�ҵ�!\n");
		else
			printf("�з���������Ԫ�أ�λ��Ϊ:%d\n",r+1);
	}
        printf("(4)˳�����ָ��Ԫ��ֵ��ɾ������....\n");
		while(1)
		{
			printf("����ɾ��Ԫ�ص�ֵ(0:����)=>");
			scanf("%d",&x);
			if(x==0)
				break;
			r=Del_List1(&LL,x);
			if(r<0)
				printf("û�ҵ�\n");
			else
			{
				printf("ɾ���ɹ�����ɾ��Ԫ�ص�λ����:%d\n ���Ա����;",r+1);
				PrintList(LL);
			}
		
		}
		printf("(5)˳�����ָ��Ԫ��λ�õ�ɾ������....\n");
		while(1)
		{
			printf("����ɾ��Ԫ�ص�λ��(0:����)=>");
			scanf("%d",&r);
			if(r==0)
				break;
			if(!Del_List2(&LL,r,&i))
				printf("λ��Խ��!\n");
			else
			{
				printf("���Ա����: ");
				PrintList(LL);
			}
		}
    
		
	}

