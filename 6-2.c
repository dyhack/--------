#include <stdio.h>
#include <stdlib.h>
//二叉树结点
typedef struct BiTNode{
	//数据
	char data;
	//左右孩子指针
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void visit(BiTree T)
{
	if(T->data!='#')
		printf("%c",T->data);
}
//按先序序列创建二叉树
int CreateBiTree(BiTree *T){
	char data;
	//按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树
	scanf("%c",&data);
	if(data == '#'){
		(*T) = NULL;
	}
	else{
		(*T)= (BiTree)malloc(sizeof(BiTNode));
		//生成根结点
		(*T)->data = data;
		//构造左子树
		CreateBiTree(&((*T)->lchild));
		//构造右子树
		CreateBiTree(&((*T)->rchild));
	}
	return 0;
}
void  PreOrederBiTree(BiTree *T)//先序递归遍历
{
	if((*T)!=NULL)
	{
		visit(*T);
		PreOrederBiTree(&((*T)->lchild));
		PreOrederBiTree(&((*T)->rchild));
	}

	

}
void  MiddleOrederBiTree(BiTree *T)//中序递归遍历
{
	if((*T)!=NULL)
	{
	
		MiddleOrederBiTree(&((*T)->lchild));
		visit(*T);
		MiddleOrederBiTree(&((*T)->rchild));
	}

	

}
void  PostOrederBiTree(BiTree *T)//后序递归遍历
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