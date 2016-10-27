#include <stdio.h>
#include <stdlib.h>
#define MAX 21
typedef struct 
{
	char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;
typedef struct 
{
	char cd[MAX];
	int start;
}HCode;
void CreatHT(HTNode *HT,int n)
{
	int i,k,l,r;
	int m1,m2;
	for(i=1;i<2*n;i++)
		HT[i].parent=HT[i].lchild=HT[i].rchild=0;
	for(i=n+1;i<2*n;i++)
	{
		int lnode,rnode;
			m1=m2=0x7fff;
		lnode=rnode=0;
		for(k=1;k<i;k++)
		{
			if(HT[k].parent==0)
			{
				if(HT[k].weight<m1)
				{
					m2=m1;
					rnode=lnode;
					m1=HT[k].weight;
					lnode=k;
				}
				else if(HT[k].weight<m2)
				{

					m2=HT[k].weight;
					rnode=k;
				}
			
			}

		}
		HT[lnode].parent=i;
		HT[rnode].parent=i;
		HT[i].weight=m1+m2;
		HT[i].lchild=lnode;
		HT[i].rchild=rnode;
	}

}
void CreatHCode(HTNode *HT,HCode *hcd,int n)
{
	int i,f,c;
	HCode hc;
	for(i=1;i<=n;i++)
	{
		hc.start=n;
		c=i;
		f=HT[i].parent;
		while(f!=0)
		{
			if(c==HT[f].lchild)
				hc.cd[--hc.start]='0';
			else
				hc.cd[--hc.start]='1';
			c=f;
			f=HT[f].parent;
		}
		hcd[i]=hc;
	}

}
void PrintHCode(HTNode *HT,HCode *hcd,int n)
{
	int i,k;
	for(i=1;i<=n;i++)
	{
		printf("  %c:  ",HT[i].data);
		for(k=hcd[i].start;k<n;k++)
			printf("%c",hcd[i].cd[k]);
		printf("\n");

	}
}
void HTjm(HTNode *HT,char b[],int n)
{
	
	int root=2*n-1,i=0;
	  while(b[i])
	{
		if(b[i]=='0')
			root=HT[root].lchild;
		else
			if(b[i]=='1')
				root=HT[root].rchild;
		if(HT[root].lchild==0&&HT[root].rchild==0)
			{
				printf("%c ",HT[root].data);
				root=(2*n-1);
			}
       i++;
	
	}
  
}
void main()
{
     //char b[7]={'1','0','0','1','0','0'};
	//int b[17]={'1','1','1','0','1','1','1','1','1','1','0','0','0','0','1','1','0'};
	//int b[]={1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,0};
	char b[]={"11101111110000110"};
	int i,n;
	HTNode HT[2*MAX-1];
	HCode hcd[MAX];
    printf("(1)创建Huffman树....\n");
	do{
		printf(" 请输入元素个数(1-%d);",MAX-1);
		scanf("%d",&n);
	}while(n<1||n>MAX-1);
	for(i=1;i<=n;i++)
	{
		fflush(stdin);
		printf(" 第%d个元素的结点值==>",i);
		scanf("%c",&HT[i].data);
		printf("\t权重==>");
		scanf("%d",&HT[i].weight);
	}
	CreatHT(HT,n);
	printf(" Huffman 树创建成功! \n");
	fflush(stdin);
	getchar();
	printf(" (2)创建Huffman编码.... \n");
	CreatHCode(HT,hcd,n);
	printf(" Huffman 编码创建成功! \n");
	getchar();
	printf("(3)输出Huffman编码:");
		PrintHCode(HT,hcd,n);
	printf("(4)输出Huffman解码:");
		HTjm(HT,b,n);
}