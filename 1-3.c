#define MAXSIZE 100   //空间初始分配变量
#define LISTINCREMENT 20  //空间分配增量
#define ERROR -1
#define OK 1
typedef int Status;
typedef int ElemType;
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	ElemType *elem;
	int length;
	int listsize;


}SqList;
void PrintList(SqList L);
int CreatList(SqList *L)
{
	int i;
	do
	{
		printf("请输入元素个数: ");
		scanf("%d",&((*L).length));

	}while((*L).length<0);
	(*L).elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!(*L).elem)
		return ERROR;
	for(i=0;i<(*L).length;i++)
	{
		printf("请输入第%d个元素值=>",i+1);
		scanf("%d",&((*L).elem[i]));
	}
	return OK;


}
Status MergeSort(SqList A,SqList B,SqList *C)
{
	(*C).elem=(ElemType *)malloc((A.listsize+B.listsize)*sizeof(ElemType));
	if(!(*C).elem)
		return ERROR;
	(*C).listsize=A.listsize+B.listsize;
	int ia,ib,ic;
	ia=ib=ic=0;
	int j;
	while(ia<A.length&&ib<B.length)
	{
		if(A.elem[ia]<B.elem[ib])
			(*C).elem[ic++]=A.elem[ia++];
		else
			if(A.elem[ia]>B.elem[ib])
				(*C).elem[ic++]=B.elem[ib++];
			else
			{
				(*C).elem[ic++]=A.elem[ia++];
			ib++;
			}
	}
	for(j=ia;j<A.length;j++)
		(*C).elem[ic++]=A.elem[j];
	for(j=ib;j<B.length;j++)
	    (*C).elem[ic++]=B.elem[j];
	(*C).length=ic;
	return OK;
}
void main()
{
	SqList A,B,C;
	CreatList(&A);
	CreatList(&B);
    MergeSort(A,B,&C);
    PrintList(C);

}
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	printf("%d-->",L.elem[i]);
	printf("\n");
	

}

