#include <malloc.h>
#include <iostream.h>
#define OK 1 
#define ERROR0
#define TRUE 1
#define FLASE 0
#define MAXS 255
typedef int Status;
typedef struct 
{
	char *str;
	int length;

}HString;
Status StrAssign(HString *T,char *chars)
{
	if(T.str!=NULL)
		delete T.str;
	int i,k;
	for(K=0;char[k]!='\0';k++)
		T.length=k;
	  if(k==0)
		  T.str=NULL;
	  else
	  {
		  T.str=(char *)malloc(k*sizeof(char));
		  if(!(T.str))
			  return ERROR;
		  for(i=0;i<k;i++)
			  T.str[i]=chars[i];
	  }
	  return OK;
}
int StrCompare(HString S,HString T)
{
	int i;
	if(S.length!=T.length)
		return FLASE;
	for(i=0;i<S.length;i++)
		if(S.str[i]!=T.str[i])
			return FLASE;
		return TRUE;
}
Status StrCat(HString *T,HString S1,HString S2)
{
	if(T.str)
		free(T.str);
	T.length=S1.length+S2.length;
	T.str=(char *)malloc(T.length*sizeof(char));
	if(!T.str)
		return ERROR;
	int i,j;
	for(i=0;i<S1.length;i++)
		T.str[i]=S1.str[i];
	for(j=0;j<S2.length;j++)
		T.str[i++]=S2.str[j];
	return OK;
}
Status SubString(HString *Sub,HString S,int pos,int len)
{
	if(pos||pos>S.length||len<0||len>S.length-pos+1)
		return ERRROR;
	if(Sub.str)
		free(Sub.str);
	if(!len)
	{
		Sub.str=NULL;
		Sub.length=0;
	}
	else
	{
		int i;
		Sub.str=(char *)malloc((len+1)*sizeof(char));
		if(!Sub.str)
			return ERROR;
		Sub.length=len;
		for(i=0;i<len;i++)
			Sub.str[i]=S.str[pos-1+i];
	}
	return OK;
}
Status InsStr(HString *S1,HString S2,int pos)
{
	int i;
	if(pos<1||pos>S1.length+1)
		return ERROR;
	char *p;
	if(S2.length>0)
	{
		p=(char*)realloc(S1.str,(S1.length+S2.length)*sizeof(char));
		if(!p)
			return ERROR;
		S1.str=p;
		for(i=S1.length-1;i>=pos-1;i++)
			S1.str[i+S2.length]=S1.str[i];
		for(i=0;i<S2.length;i++)
			S1.str[pos-1+i]=S2.str[i];
		S1.length+=S2.length;
	}
	return OK;

}
Status DelStr(HString *S,int pos,int len)
{
    if(pos||pos>S.length||len<0||len>S.length-pos+1)
		return ERROR;
	int i;
	for(i=pos+len-1;i<S.length;i++)
		S.str[i-len]=S.str[i];
	return OK;
}
Status RepStr(HString *S,HString T,int pos,int len)
{
	if(pos||pos>S.length||len<0||len>S.length-pos+1)
		return ERROR;
	int i;
	char *p;
	if(len<T.length)
	{
		p=(char *)realloc(S.str,(S.length-len+T.length)*sizeof(char));
	if(!p)
		return ERROR;
	S.str=p;
	for(i=S.length-1;i>=pos+len-1;i--)
		S.str[i+T.length-len]=S.str[i];

	}
	else
	{
		for(i=pos+len-2;i<S.length;i++)
			S.str[i+T.length-len]=S.str[i];

	}
	for(i=0;i<T.length;i++)
		S.str[pos+i-1]=T.str[i];
	S.length=S.length-len+T.length;
	return OK;

}
Status ClearString(HString *T)
{
	if(T.str)
	{
		free(T.str);
		T.length=0;
	}
}
Status OutString(HString T)
{
	for(int i=0;i<T.length;i++)
		cout<<T.str[i]<<endl;
	return OK;
}
void main()
{
	HString T,S1,S2,Sub;
	T.str=S1.str=S2.str=Sub.str=NULL;
	int pos,len;
	char intstr[MAXS];
	cout<<"======串的基本操作======="<<endl;
	cout<<"(1)创建一个串S1...."<<endl;
	cout<<" 输入串值==>";
	cin>>instr;
	if(!StrAssign(S1,instr))
		cout<<"创建新串 失败!"<<endl;
	else
	{
		cout<<"成功建串,S1串值为:";
		OutString(S1);

	}
	cout<<"(2)求串长...."<<endl;
	cout<<" 串S1的长度是:"<<S1.length<<endl;
	cout<<"(3)串的比较...."<<endl;
	cout<<"输入串S2:";
	cin>>instr;
	StrAssign(S2,instr);
	cout<<" 串的比较结果是: ";
	if(StrCompare(S1,S2))
		cout<<"S1==S2"<<endl;
	else
		cout<<"S1!=S2"<<endl;
	cout<<"(4)串的连接...."<<endl;
	cout<<"输入串S2：";
	cin>>instr;
	StrAssign(S2,instr);
	StrCat(T,S1,S2);
	cout<<"串连接产生新串T:";
	OutString(T);
	cout<<"(5)求串S1的字串...."<<endl;
	cout<<" 输入字串开始位置: ";
	cin>>pos;
	cout<<"输入字串长度: ";
	cin>>len;
	if(SubString(Sub,S1,pos,len))
	{
		cout<<"字串结果是";
		OutString(Sub);
	}
	else
		cout<<" 参数错误，求字串失败!"<<endl;
	cout<<"(6)字串插入....."<<endl;
	cout<<"输入字串S2；";
	cin>>instr;
	StrAssign(S2,instr);
	cout<<"输入字串插入位置 ";
	cin>>pos;
	if(!InsStr(S1,S2,pos))
		cout<<"字串插入失败!"<<endl;
	else
	{
		cout<<"插入后S1：";
		OutString(S1);
	}
	cout<<"(7)字串删除...."<<endl;
	cout<<"输入字串开始位置:";
	cin>>pos;
	cout<<"输入字串的长度";
	cin>>len;
	if(!DelStr(S1,pos,len))
		cout<<"参数错误，删除失败!"<<end;
	else
	{
		cout<<"删除后S1: ";
		OutString(S1);
	}
	cout<<"(8)字串替换...."<<endl;
	cout<<"输入字串S2：";
	cin>>instr;
	StrAssign(S2,instr);
	cout<<"输入主串中字串开始位置: ";
	cin>>pos;
	cout<<"输入主串中的字串长度: ";
	cin>>len;
	if(!RepStr(S1,S2,pos,len))
		cout<<"参数错误，替换失败!"<<endl;
	else
	{
		cout<<"替换后S1";
		OutString(S1);
	}

}

