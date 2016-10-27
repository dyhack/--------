#include <stdlib.h> /*含ma l l o c ( ) 的头文件*/
#include <stdio.h>
struct node *creat(struct node *head);
void print(struct node *p);
int find(struct node *head,int number);
struct node *delte(struct node *head);
struct node *add(struct node *head);
struct node //①定义链表数据结构
{
	int num;
	struct node *next;
};
void main()
{
	struct node *p,*newp,*addp;
	int m;
    p=NULL;
	printf("创建链表\n");
    p=creat(p);
	newp=p;
	addp=p;
	print(p);
	
     while(1)
	{
	   printf("请输入一个数，找出它在链表中的位置(编号1) ,输入0结束\n");
	   scanf("%d",&m);
	   if(m==0)
	   {
		   printf("成功结束!\n");
	   
		   break;
	   }
	   else
	   {
		   find(p,m);
		   continue;
	   }
	   
		  

	}
       
	   print(delte(newp));
	   print(add(addp));

}
struct node *creat(struct node *head)//创建链表
{
	int n=0;
	struct node *p1,*p2;
	p2=(struct node*)malloc(sizeof(struct node));
	p1=p2;
    head=NULL;
    scanf("%d",&p1->num);
    while(p1->num!=0)
	{
		n++;
		if(n==1)
			head=p1;
		else
		{
		p2->next=p1;
		}
		p2=p1;
		p1=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&p1->num);
       

	}
	p2->next=NULL;
	return head;

}
void print(struct node *p)
{
	while(p!=NULL)
	{
		if(p->next==NULL)
			break;
		printf("%d-->",p->num);
		p=p->next;
		

   
	}
	
}
int find(struct node *head,int number) 
{
	struct node *temp=head;
	int position=1;
	while(temp!=NULL)
	{ 
		if(temp->num==number)
		{
			printf("The number's position=%d\n",position);
			return position;
			//break;
		}
		else
		{	temp=temp->next;
		  position++;
		}
	

	}
   return 0;

} 
 struct node *delte(struct node *head)
{
	int m;
	struct node *p=head;
	printf("请输入要删除的元素");
	scanf("%d",&m);
	if(find(head,m)==1)
	
		head=head->next;
	else
		while(p->next!=NULL)
		{    
			if(p->next->num==m)
			{
				p->next=p->next->next;
				
			}
			else
			{
				p=p->next;
				continue;
			}
		}
     
     return head;


}
 struct node *add(struct node *head)
 {
	int m,station,flag=1;
	struct node *p=head,*p1;
	printf("请输入要添加的元素和位置\n");
	scanf("%d %d",&m,&station);
	p1=(struct node*)malloc(sizeof(struct node));
	if(station==1)
	   {
		p1->next=head->next;
		head->next=p1;
		p1->num=m;
	}

	else
		while(1)
		{   
			if(flag==station)
			{
				if(p->next==NULL)
				{
					p->next=p1;
					p1->num=m;
					p1->next==NULL;
                      	break;
                   
				}
				else
				{
				p1->next=p->next;
				 p->next=p1;
				 p1->num=m;
				 break;
				}
			
			}
			else
			{
			flag++;
			p=p->next;
			}
			

		}
     
     return head;

 }

