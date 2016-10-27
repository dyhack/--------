#include <stdio.h>
#include <stdlib.h>
#define Length 20
#define listsize 100 
#define OVERFLOW 0;

int i;
int  local;
void main()
{
	int *newbase=NULL;
	int *p;
    printf("请输入一些数");
	for(i=0;i<=20;i++)
	{
	scanf("%d",*(p+i));
	
	}

	if(local<1||local>Length+1)
		return 0;
	if(Length>=listsize)
	{
		newbase=(int *)realloc(p,(listsize+20)*sizeof(int));

	
	if(!newbase)
	{
		exit(0);
	
	}
	 p=newbase;

	}
  int *q=p-1+5;
  for(int p=p+length-1;p>=q;--p)
  {
	  *(p+1)=*p;
	  *q=5;
	  ++Length;

	  return 1;
  }
  



  


}