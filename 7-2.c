#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct BiTNode
{
	char data;
	struct  BiTNode *lchild;
	struct  BiTNode *rchild;

}BiTNode,*BiTree;
void CreateBiTree(BiTree *T)
{
	char ch;
	scanf("\n%c",&ch);
	if(ch=='#')
		(*T)=NULL;
	else
	{
		(*T)=(BiTree )malloc(sizeof(BiTNode));
		if(!(*T))
			exit(-1);
		(*T)->data=ch;
		printf("\n������%c�������ӽ��(#����);",(*T)->data);
		CreateBiTree(&(*T)->lchild);
		printf("\n������%c�������ӽ��(#����)",(*T)->data);
		CreateBiTree(&(*T)->rchild);
	}
}
int LeafNodeCount(BiTree T)
{
	if(T==NULL)
		return 0;
	else if(T->lchild==NULL&&NULL==T->rchild)
		return 1;
	else
		return LeafNodeCount(T->lchild)+LeafNodeCount(T->rchild);

}
void ChangeLR(BiTree T)
{
	BiTree p;
	if(T==NULL||(T->lchild&&T->rchild==NULL))
		return;
	else
	{
		p=T->lchild;
		T->lchild=T->rchild;
		T->rchild=p;
	}
	ChangeLR(T->lchild);
	ChangeLR(T->rchild);
}
int D1_Nodes(BiTree T)
{
	int num1,num2;
	if(T==NULL||(!T->rchild&&!T->lchild))
		return 0;
	num1=D1_Nodes(T->lchild);
	num2=D1_Nodes(T->rchild);
	if(T->lchild&&!T->rchild)
		return num1+1;
	else
		if(!T->lchild&&T->rchild)
			return num2+1;
		else
			return num1+num2;

}
int Nodes(BiTree T)
{
	int num1,num2;
	if(NULL==T)
		return 0;
	else
	{
		num1=Nodes(T->lchild);
		num2=Nodes(T->rchild);
		return (num1)+(num2)+1;
	}
}
int BiTreeDepth(BiTree T)
{
	int leftdep,rightdep;
	if(NULL==T)
		return 0;
	else
	{
		leftdep=BiTreeDepth(T->lchild);
		rightdep=BiTreeDepth(T->rchild);
		return (leftdep>rightdep)?(leftdep+1):(rightdep+1);

	}

}
void OutputBiTree(BiTree T)
{
	if(NULL!=T)
	{
		printf("%c",T->data);
	if(T->lchild!=NULL||NULL!=T->rchild)
	{
		printf("(");
		OutputBiTree(T->lchild);
		if(NULL!=T->rchild)
			printf(",");
		OutputBiTree(T->rchild);
		printf(")");

	}
	}
}
void main()
{
	int n;
	BiTNode *proot;
	proot=NULL;
	printf("����������Ԫ��(#����)");
	CreateBiTree(&proot);
	printf("\n(1)�����������ɹ�! �����ű�ʾ��ʽ���: \n\t");
	OutputBiTree(proot);
	printf("\n");
	n=Nodes(proot);
	printf("(2)���������������: %d\n",n);
	n=LeafNodeCount(proot);
	printf("(3)���������Ҷ�ӽ����Ϊ: %d\n",n);
	n=BiTreeDepth(proot);
	printf("(4)�������������: %d\n",n);
	n=D1_Nodes(proot);
	printf("(5)�������ж�Ϊ1�Ľ������: %d\n",n);
	ChangeLR(proot);
	printf("(6)�������н������Һ��Ӻ���������ű�ʾ�����: \n\t");
	OutputBiTree(proot);
	printf("\n");
}