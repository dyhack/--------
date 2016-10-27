#define MAXN 20
#include <stdio.h>
void fun(int M[MAXN][MAXN],int n)
{
	int i,j,k=0;
	for(i=0;i<(n+1)/2;i++)
	{
		for(j=i;j<n-i;j++)
		{
		k++;
		M[j][i]=k;
		}
	
	for(j=i+1;j<n-i;j++)
	{
		k++;
		M[n-i-1][j]=k;
	}
	for(j=n-i-2;j>=i;j--)
	{
		k++;
		M[j][n-i-1]=k;
	}
	for(j=n-i-2;j>=i+1;j--)
	{
		k++;
		M[i][j]=k;

	}
	}

}
void main()
{
	int i,j,n;
	int M[MAXN][MAXN];
	while(1)
	{
		do{
			printf("\n ÊäÈë¾ØÕóµÄ½×(0-%d)(0;½áÊø!)==>",MAXN-1);
			scanf("%d",&n);
		}while(n<0||n>=MAXN);
	
	if(n==0)
		return;
	fun(M,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%4d",M[i][j]);
		printf("\n");
	}
	}

}