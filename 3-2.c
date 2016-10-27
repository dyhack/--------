#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1	
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXN 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int status;
typedef char SelemType;
typedef struct {
	SelemType *base;
	SelemType *top;
	int stacksize;

}SqStack;
status InitStack(SqStack *S)
{
	(*S).base=(SelemType *)malloc(STACK_INIT_SIZE*sizeof(SelemType));
	if(!(*S).base)
		exit(OVERFLOW);
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE;
	return  OK;
}
status Push(SqStack *S,SelemType e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base=(SelemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SelemType));
		if(!(*S).base)
			exit(OVERFLOW);
		(*S).top=(*S).base+(*S).stacksize;
		(*S).stacksize+=STACKINCREMENT;
	}
		*(++S->top)=e;//��ջ������Topָ�������ƶ�������������
		return OK;
	

}
status Pop(SqStack *S,SelemType *e)
{
	if((*S).top==(*S).base)
		return ERROR;
	*e=*(S->top--);//��ջ���ȶ�ȡ������ʹָ�������ƶ�
	return OK;

}
status StackEmpty(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}
int correct(char *exp,int max)//max���ʽ�ĳ��ȣ��ַ��ĸ�����,expָ��exp[]�ַ����顣
{
	int i,flag=1;
	SqStack S;
	char e,x;
	InitStack(&S);
	for(i=0;exp[i]!=0;i++)
	{
		x=exp[i];
		if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
			Push(&S,x);
		if(x==')'||x==']'||x=='}')
		{
			if(!Pop(&S,&e))
				flag=0;
			else
				if((x==')'&&e!='(')||(x==']'&&e!='[')||(x=='}'&&e!='{'))
					flag=0;
		
		}
	
	}
	if(!StackEmpty(S))
		flag=0;
	return flag;

}
void main()
{
	char exp[MAXN];
	while(1)
	{
		printf("��������ʽ,����0�˳� �� ");
		gets(exp);
		if(strcmp(exp,"0")==0)
			break;
		if(correct(exp,strlen(exp))==0)
			printf("���ʽ����Ϊ: \n%s\n���ʽ���Ų�ƥ��\n",exp);
			else
			printf("���ʽ����ƥ��\n");
	}
}
