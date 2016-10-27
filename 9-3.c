#define P 13
#define OK 1
#define ERROR 0
#include <stdio.h>
#include <malloc.h>
typedef int Status;
typedef struct 
{
	int key;
	int otherinfo;

}HElemType;
typedef struct HNode
{
	HElemType data;
	struct HNode *next;
}HNode,*LinkHash;
typedef HNode *HashTable[P];
Status CreatHash(HashTable HT,int K[],int n)
{
	int i,hk;
	LinkHash q;
	for(i=0;i<P;i++)
		HT[i]=NULL;//把指针数组都首先置为空
	for(i=0;i<n;i++)
	{
      q=(LinkHash)malloc(sizeof(HNode));
	  if(!q)
		  return ERROR;
	  q->data.key=K[i];
	  hk=K[i]%P;
	  q->next=HT[hk];
	  HT[hk]=q;
	}
	return OK;

}
void PrintHash(HashTable HT)
{
	int i;
	LinkHash q;
	for(i=0;i<P;i++)
	{
		printf("   %d:",i);
	q=HT[i];
	while(q!=NULL)
	{
		printf("->%d",q->data.key);
		q=q->next;
	}
	printf("->∧\n");
}
}
Status InsertHash(HashTable HT,int xkey)
{
	int hk;
	LinkHash q;
	q=(LinkHash)malloc(sizeof(HNode));
	if(!q)
		return ERROR; 
	q->data.key=xkey;
	hk=xkey%P;
	q->next=HT[hk];
	HT[hk]=q;
	return OK;
}
LinkHash SearchHash(HashTable HT,int xkey)
{
	LinkHash q;
	int hk;
	hk=xkey%P;
	q=HT[hk];
	while(q!=NULL&&q->data.key!=xkey)
		q=q->next;
	return q;
}
Status DeleteHash(HashTable HT,int xkey)
{
	LinkHash q,pre=NULL;
	int hk;
	hk=xkey%P;
	q=HT[hk];
	while(q!=NULL&&q->data.key!=xkey)
	{
		pre=q;
		q=q->next;
	}
	if(q==NULL)
		return ERROR;
	if(pre==NULL)
		HT[hk]=q->next;
	else
		pre->next=q->next;
	free(q);
	return OK;

}
int LengthHash(HashTable HT)
{
	int i,c=0;
	LinkHash q;
	for(i=0;i<P;i++)
	{
		q=HT[i];
		while(q!=NULL)
		{
			c++;
			q=q->next;
		}
	
	}
	return c;
}
void main()
{
	int K[]={13,41,15,44,06,68,12,25,38,64,19,49};
	int n=12;
	HashTable HT;
	LinkHash q;
	int xkey;
	printf("=========   散列表的操作  =========\n");
	printf("(1)创建链地址法散列表....\n");
	if(!CreatHash(HT,K,n))
	{
		printf(" 散列表创建失败!\n");
		return ;
	}
	PrintHash(HT);
	printf("(2)散列表插入操作.... \n");
	while(1)
	{
		printf(" 输入插入元素的键值(-1:结束)==>");
		scanf("%d",&xkey);
		if(-1==xkey)
		break;
		if(!InsertHash(HT,xkey))
		{
			printf("  散列表插入操作失败!\n");
		}
		else
			PrintHash(HT);
	}
	printf("(3)散列表删除操作....\n");
	while(1)
	{
		printf(" 输入删除元素的键值(-1:结束)==>");
		scanf("%d",&xkey);
		if(-1==xkey)
			break;
		if(!DeleteHash(HT,xkey))
			printf(" 输入的键值不存在! \n");
		  else
			  PrintHash(HT);
	}
	printf("(4)散列表的查找操作....\n");
	while(1)
	{
		printf("  输入待查找元素的键值(-1:结束)==>");
		scanf("%d",&xkey);
		if(-1==xkey)
			break;
		q=SearchHash(HT,xkey);
		if(q==NULL)
			printf(" 输入的键值不存在，查找失败！ \n");
		else
			printf("  查找成功,散列表中元素的键值为: %d\n",q->data.key);

	}
	printf("(5)求散列表的长度操作....\n");
	printf(" 当前散列表的长度为: %d\n",LengthHash(HT));
}