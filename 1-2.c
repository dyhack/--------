#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define OVERFLOW -1
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
Status CreatList(SqList *L)
{
	int i;
	do
	{
		printf("������Ԫ�صĸ���;");
		scanf("%d",&((*L).length));

    }while(i>=1&&i<=(*L).length);//while((*L).length<=(*L).listsize)
	(*L).elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!(*L).elem)
		return ERROR;
	for(i=0;i<(*L).length;i++)
	{
		printf("�������%d��Ԫ��ֵ=>",i+1);
		scanf("%d",&((*L).elem[i]));
	}
	return OK;



	

}
Status InsertList(SqList *L,int i,int m,ElemType *E)
{
	if(i<1||i>(*L).length+1)
		return ERROR;
	ElemType *p;
	int j;
	if(m>(*L).listsize)
	{
		p=(ElemType *)realloc((*L).elem,((*L).length+m)*sizeof(ElemType));
		if(!p)
			exit(OVERFLOW);
		(*L).elem=p;
		(*L).listsize=(*L).length+m;

	}
	for(j=(*L).length;j>=i-1;--j)
		(*L).elem[j+m]=(*L).elem[j];
	for(j=0;j<m;j++)
		(*L).elem[i+j-1]=*(E+j);
	(*L).length=m+(*L).length;
	return OK;

}
Status DeleteList(SqList *L,int x,int y)
{
	if(x>y)
		return ERROR;
	    int i,j;
		for(i=j=0;i<(*L).length;i++)
		{
			if((*L).elem[i]>=x&&(*L).elem[i]<=y)
				j++;
			else
				(*L).elem[i-j]=(*L).elem[i];
		}
 			(*L).length-=j;
            return OK;
}
void PrintList(SqList L)
{
	int i;
	printf("˳�������%d��Ԫ��:\n",L.length);
	for(i=0;i<L.length;i++)
		printf("%4d",L.elem[i]);
	printf("\n");
}
void main()
{
	SqList L;
	int i,m=3;
	ElemType E[]={23,24,25};
    ElemType x,y;
	printf("(1)������n��Ԫ�ص�˳���....\n");
	if(!CreatList(&L))
	{
		printf("����˳���ʧ��!\n");
		return ;
	}
	printf("��ǰ˳�������\n");
	PrintList(L);
	printf("(2)��˳����i��λ�ò���m����Ԫ��....\n");
	printf("����������λ��i:" );
	scanf("%d",&i);
	if(!InsertList(&L,i,m,E))
		printf("����ʧ��!\n");
	else
	{
		printf("����ɹ���������˳�������: \n");
		PrintList(L);
	}
    printf("(3)��˳���ɾ����ֵ����x��y֮�������Ԫ��....\n");
	printf("�����뱻ɾԪ������ֵx: ");
	scanf("%d",&x);
	printf("�����뱻ɾԪ������ֵy: ");
	scanf("%d",&y);
	if(!DeleteList(&L,x,y))
		printf("��������,ɾ��ʧ��! ");
	   else
	   {
		   printf("ɾ�����˳�������: \n");
		   PrintList(L);
	   }



}