#include <stdio.h>
#include <stdlib.h>
#define listsize 100
int length1=10;
int Add(int *p,int e,int number)
{
	int *q=p+length1-e;
	int *m;
		if(length1>=listsize)
	{
			int *newbase=(int *)realloc(p,(listsize)*sizeof(int));
			m=newbase;

		}
	

	
	
	for(p=p+length1-1;p>=q;--p)
	{
		*(p+1)=*p;
		*q=e;
		++length1;
		
		return 1;
	}


}
int *q;
int Delte(int *p,int e)
{
	if((e<1)||(e>length1))
	{
		printf("Error ,please try again");
		return 0;
	}
       
        
		q=p+length1-1;                 //表尾元素的位置
		p=p+length1-e;//被删除元素的位置;
		for(++p;p<=q;++p)
		{
			*(p-1)=*p;
			
		}
		--length1;
return 1;

}
      
void main()
{
	int array[10]={1,5,4,3,2,1,2,2};
	

	
		if(Add(array,2,5))
		{
			int i;
			for(i=0;i<=length1;i++)
				printf("array[%d]=%d\n",i,array[i]);
		}
}