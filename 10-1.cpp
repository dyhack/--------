#define MAXNUM 100
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int KeyType;
typedef struct 
{
	KeyType key;
	int other;

}ElemType;
typedef struct 
{
	ElemType r[MAXNUM+1];
	int length;
}SqList;
void CreatList(SqList &L)
{
	int i;
	do
	{
		printf(" �����������(1-%d)==>",MAXNUM-1);
		scanf("%d",&L.length);

	}while(L.length<1||L.length>MAXNUM-1);
	srand((unsigned)time(NULL));
	for(i=1;i<=L.length;i++)
	{
		L.r[i].key=1+rand()%(MAXNUM-1);
	}
}
void InsertSort(SqList &L,int &cp,int &mv)
{
	int i,j;
	for(i=2;i<=L.length;i++)
	{
		cp++;
	if(L.r[i].key<L.r[i-1].key)//�������ı�ǰ�����С�Ļ�
	{
		L.r[0]=L.r[i];mv++;//�Ѻ�������洢��L.r[0]�С�Ȼ������������ƶ�
	    for(j=i-1;L.r[0].key<L.r[j].key;j--)//�������С����һֱ�ƶ�
		{
			L.r[j+1]=L.r[j];//����ƶ�
			cp++;
			mv++;

		}
		cp++;
		L.r[j+1]=L.r[0];
		mv++;
	}
	}

}
void BinSort(SqList &L,int &cp,int &mv)
{
	int i,j,low,high,mid;
	for(i=2;i<=L.length;i++)
	{
		L.r[0]=L.r[i];
		mv++;
		low=1;
		high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			cp++;
			if(L.r[0].key<L.r[mid].key)
				high=mid-1;
			else
				low=mid+1;

		}
		for(j=i-1;j>=high+1;j--)
		{
			L.r[j+1]=L.r[j];
			mv++;
		}
		L.r[high+1]=L.r[0];
		mv++;
	}
}
void ShellInsert(SqList &L,int dk,int &cp,int &mv)
{
	int i,j;
	for(i=dk+1;i<=L.length;i++)
	{
		cp++;
		if(L.r[i].key<L.r[i-dk].key)//���ϣ�����������ߵ�ֵ��Ƚ�
		{
			mv++;
			L.r[0]=L.r[i];
			for(j=i-dk;j>0&&L.r[0].key<L.r[j].key;j-=dk)
			{
				L.r[j+dk]=L.r[j];
				cp++;
				mv++;
			}
			cp++;
			mv++;
			L.r[j+dk]=L.r[0];
		}
	}
}
void ShellSort(SqList &L,int &cp,int &mv)
{
	ShellInsert(L,5,cp,mv);
	ShellInsert(L,3,cp,mv);
	ShellInsert(L,1,cp,mv);
}
void BubbleSort(SqList &L,int &cp,int &mv)
{
	int i,j,change;
	for(i=1,change=TRUE;i<L.length&&change;i++)
	{
		change=FALSE;//ÿ�ο�ʼ����chang����Ϊδ����
		for(j=1;j<L.length-i+1;++j)//�ͺ����J=1��J=L.length-i+1�����Ƚϴ�С,�����
		{
			cp++;//��ѭ���˶��ٴ�
			if(L.r[j].key>L.r[j+1].key)//������������ǰ���С�Ļ����ͽ�������2�� 
			{
				L.r[0]=L.r[j];
				L.r[j]=L.r[j+1];
				L.r[j+1]=L.r[0];
				change=TRUE;
				mv+=3;//�ǽ����Ĵ���+3
			}
		}
	}
}
int Partition(SqList  &L,int low,int high,int &cp,int &mv)//����������ʦ���ĵڶ��ֿ������򷨣�����Ҫ�����н�洢��ֻ��Ҫ����������н����ֵ�������һ���Ͷ��ˣ�
{
	int i,j;
	KeyType pivotkey;
	L.r[0]=L.r[low];//���ȴ�0��ʼ��pivotkey��Ϊ�������н�
	mv++;
	pivotkey=L.r[0].key;
	i=low;
	j=high;
	while(i<j)
	{
		while(i<j&&L.r[j].key>=pivotkey)//���L.r[j].key��ֵ��L.r[0].key�Ĵ󣬾�Ҫ��j��ǰ�ƶ�һλ
		{
			j--;
			cp++;

		}
		if(i<j)
		 cp++;
		L.r[i]=L.r[j];//��j���ֵ����i
		mv++;
		while(i<j&&L.r[i].key<=pivotkey)
		{
			i++;
			cp++;

		}
		if(i<j)
			cp++;
		L.r[j]=L.r[i];
		mv++;

	}
   L.r[i]=L.r[0];
   mv++;
   return i;
}
void QSort(SqList &L,int low,int high,int &cp,int &mv)//��Ԫ�ؽ��п�������
{
	int pivotloc;
	if(low<high)
	{
		pivotloc=Partition(L,low,high,cp,mv);
		QSort(L,low,pivotloc-1,cp,mv);
		QSort(L,pivotloc+1,high,cp,mv);
	}
}
void SelectSort(SqList &L,int &cp,int &mv)
{
	int i,j,k;
	for(i=1;i<L.length;i++)//Ӧ��Ҫ����L.length-1��
	{
		for(k=i+1,j=i;k<=L.length;k++)//k��i��һ�ĵط���ʼ��һֱ������Ľ�����
		{
			cp++;
			if(L.r[k].key<L.r[j].key)//������ڱ�L.r[i].key�е�ֵ��С��ֵ,�ͽ�������
				j=k;
		}
		if(j!=i)//0��Ϊ�н飬��i��j����
		{
			L.r[0]=L.r[i];
			L.r[i]=L.r[j];
			L.r[j]=L.r[0];
			mv+=3;
		}
	}

}
void HeapAdjust(SqList &H,int s,int m,int &cp,int &mv)
{
	int j;
	H.r[0]=H.r[s];
	mv++;
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m&&H.r[j].key<H.r[j+1].key)
			++j;
		if(j<m)
			cp++;
		cp++;
		if(H.r[0].key>=H.r[j].key)
			break;
		H.r[s]=H.r[j];
		mv++;
		s=j;

	}
	H.r[s]=H.r[0];
	mv++;
}
void HeapSort(SqList &H,int &cp,int &mv)
{
	int i;
	for(i=H.length/2;i>0;--i)
		HeapAdjust(H,i,H.length,cp,mv);
	for(i=H.length;i>1;--i)
	{
		H.r[0]=H.r[1];
		H.r[1]=H.r[i];
		H.r[i]=H.r[0];
		mv+=3;
		HeapAdjust(H,1,i-1,cp,mv);
	}

}
void Merge(SqList &L,SqList &temp,int i,int m,int n,int &cp,int &mv)//��·�鲢����
{
	int b=i,j,k;
	for(j=m+1,k=1;i<=m&&j<=n;++k)
	{
		if(L.r[i].key<L.r[j].key)
			temp.r[k]=L.r[i++];
		else
			temp.r[k]=L.r[j++];
		cp++;
		mv++;
	}
	for(;i<=m;)
	{
		temp.r[k++]=L.r[i++];
		mv++;
	}
	for(;j<=n;)
	{
		temp.r[k++]=L.r[j++];
		mv++;
	}
	for(i=b,k=1;i<=n;)
	{
		L.r[i++]=temp.r[k++];
		mv++;

	}


}
void MergeSort(SqList &L,SqList &temp,int s,int t,int &cp,int &mv)
{
	int m;
	if(s<t)
	{
		m=(s+t)/2;
		MergeSort(L,temp,s,m,cp,mv);
		MergeSort(L,temp,m+1,t,cp,mv);
		Merge(L,temp,s,m,t,cp,mv);
	}

}
void OutputList(SqList L)
{
	int i;
	for(i=1;i<=L.length;i++)
		printf("%3d",L.r[i].key);
	printf("\n");
}
void main()
{
	SqList LL,L;
	SqList temp;
	int cp,mv;
	printf("(1)��������������....\n");
	CreatList(LL);
	printf("  ��������: ");
	OutputList(LL);
	getchar();

	printf("(2)ֱ�Ӳ�������....\n");
	L=LL;
	cp=mv=0;
	InsertSort(L,cp,mv);
	printf(" ������: ");
	OutputList(L);
	printf(" ����Ч�ʣ��Ƚϴ���%d, �ƶ�����%d. \n",cp,mv);
	getchar();

	printf("(3)�۰��������....\n");
	L=LL;
	cp=mv=0;
	BinSort(L,cp,mv);
	printf(" ������: ");
	OutputList(L);
	printf(" ����Ч�ʣ��Ƚϴ���%d, �ƶ�����%d. \n",cp,mv);
	getchar();
     
	printf("(4)ϣ������....\n");
	L=LL;
	cp=mv=0;
	ShellSort(L,cp,mv);
	printf(" ������: ");
	OutputList(L);
	printf(" ����Ч�ʣ��Ƚϴ���%d, �ƶ�����%d. \n",cp,mv);
	getchar();
    
	printf("(5)ð������....\n");
	L=LL;
	cp=mv=0;
	BubbleSort(L,cp,mv);
	printf(" ������: ");
	OutputList(L);
	printf(" ����Ч�ʣ��Ƚϴ���%d, �ƶ�����%d. \n",cp,mv);
	getchar();

	printf("(6)��������....\n");
	L=LL;
	cp=mv=0;
	QSort(L,1,L.length,cp,mv);
	printf(" ������: ");
	OutputList(L);
	printf(" ����Ч�ʣ��Ƚϴ���%d, �ƶ�����%d. \n",cp,mv);
	getchar();

	printf("(7)��ѡ������....\n");
	L=LL;
	cp=mv=0;
	SelectSort(L,cp,mv);
	printf(" ������: ");
	OutputList(L);
	printf(" ����Ч�ʣ��Ƚϴ���%d, �ƶ�����%d. \n",cp,mv);
	getchar();

	printf("(8)������....\n");
	L=LL;
	cp=mv=0;
	HeapSort(L,cp,mv);
	printf(" ������: ");
	OutputList(L);
	printf(" ����Ч�ʣ��Ƚϴ���%d, �ƶ�����%d. \n",cp,mv);
	getchar();

	printf("(9)��·�鲢����....\n");
	L=LL;
	cp=mv=0;
	MergeSort(L,temp,1,L.length,cp,mv);
	printf(" ������: ");
	OutputList(L);
	printf(" ����Ч�ʣ��Ƚϴ���%d, �ƶ�����%d. \n",cp,mv);


}