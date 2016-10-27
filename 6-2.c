#include <stdio.h>
#include <stdlib.h>
//���������
typedef struct BiTNode{
	//����
	char data;
	//���Һ���ָ��
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void visit(BiTree T)
{
	if(T->data!='#')
		printf("%c",T->data);
}
//���������д���������
int CreateBiTree(BiTree *T){
	char data;
	//�������������������н���ֵ��һ���ַ�������#����ʾ����
	scanf("%c",&data);
	if(data == '#'){
		(*T) = NULL;
	}
	else{
		(*T)= (BiTree)malloc(sizeof(BiTNode));
		//���ɸ����
		(*T)->data = data;
		//����������
		CreateBiTree(&((*T)->lchild));
		//����������
		CreateBiTree(&((*T)->rchild));
	}
	return 0;
}
void  PreOrederBiTree(BiTree *T)//����ݹ����
{
	if((*T)!=NULL)
	{
		visit(*T);
		PreOrederBiTree(&((*T)->lchild));
		PreOrederBiTree(&((*T)->rchild));
	}

	

}
void  MiddleOrederBiTree(BiTree *T)//����ݹ����
{
	if((*T)!=NULL)
	{
	
		MiddleOrederBiTree(&((*T)->lchild));
		visit(*T);
		MiddleOrederBiTree(&((*T)->rchild));
	}

	

}
void  PostOrederBiTree(BiTree *T)//����ݹ����
{
	if((*T)!=NULL)
	{
	
		PostOrederBiTree(&((*T)->lchild));
		PostOrederBiTree(&((*T)->rchild));
		visit(*T);
	}

	

}
void main()
{
	BiTree T;
	CreateBiTree(&T);
	PreOrederBiTree(&T);
	printf("\n");
	MiddleOrederBiTree(&T);
	printf("\n");
	PostOrederBiTree(&T);
	printf("\n");


}