#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int v1,v2;
	char s1[30],s2[30];
	struct node *next;
};
struct node *getNode()
{ 
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	
	return temp;
}
void  insert_str(char *str1,char *str2)
{
	int i=0;
	while(str2[i]!=NULL)
	{
		str1[i]=str2[i];
		i++;
	}
	str1[i]=NULL;
}

struct  node * insert_ele(struct node *root)
{
	struct node *temp=NULL,*ptr=NULL;
	int v1,v2;
	char s1[30],s2[30];
	printf("enter v1,v2 values");
	scanf("%d%d",&v1,&v2);
	printf("enter strings s1,s2");
	scanf("%s%s",s1,s2);
		temp=getNode();
		temp->v1=v1;
		temp->v2=v2;
		insert_str(temp->s1,s1);
		insert_str(temp->s2,s2);
	if(root==NULL)
	{
		root=temp;
	}
	else 
	{
		 temp->next=root;
		 root=temp;
	}	
	return root;
}
struct node * merge(struct node *ptr1,struct node *ptr2,int *pr1,int *pr2)
{
	struct node *res,*temp;
	int flag=0;
	if(ptr1==NULL)
		return ptr2;
	if(ptr2==NULL)
		return ptr1;
	if(ptr1->v1<ptr2->v1)
	{
		res=ptr1;
		flag=0;
	}
	
	else
	{
		flag=1;
		res=ptr2;
	}
	//printf("%d%d",ptr1->val,ptr2->val);
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->v1<=ptr2->v1)
		{
			
  			if(ptr1->next!=NULL&&ptr1->next->v1<=ptr2->v1)
			{
				if(flag==0)
				ptr1=ptr1->next;
				else
				{
					temp=ptr2->next;
					ptr2->next=ptr1;
					ptr2=temp;
					flag=0;
				}
			}
			else
			{
				 
			
				if(flag==0)
				{
				temp=ptr1->next;
				ptr1->next=ptr2;
				ptr1=temp;
				flag=1;
				}
				else
				{
					temp=ptr2->next;
					ptr2->next=ptr1;
					ptr2=temp;
					flag=0;
				}

				}
			

		}
		else
		{
			if(ptr2->next!=NULL&&ptr2->next->v1<=ptr1->v1)
			{
				if(flag==1)
				ptr2=ptr2->next;
				else
				{
					temp=ptr1->next;
					ptr1->next=ptr2;
					ptr1=temp;
					flag=2;
				}
			}
			else
			{
			 
				if(flag==1)
				{
				temp=ptr2->next;
				ptr2->next=ptr1;
				ptr2=temp;
				flag=0;
				}
				else
				{
					temp=ptr1->next;
					ptr1->next=ptr2;
					ptr1=temp;
					flag=1;
				}
			}

		}

	}
	 
	 
	
	return res;

}
struct node * mergesort(struct node *in1,int *pr1,int *pr2)
{
	struct node *half,*in2,*ptr=in1;
	half=in1;
	if(in1==NULL)
		return;
	if(in1->next==NULL)
		return in1;
	while(in1->next!=NULL)
	{
		in1=in1->next;
		if(in1->next!=NULL)
		{
			in1=in1->next;
			half=half->next;
		}

	}
	in2=half->next;
	half->next=NULL;
	ptr=mergesort(ptr,pr1,pr2);
	in2=mergesort(in2,pr1,pr2);
	in1=merge(ptr,in2,pr1,pr2);
	return in1;
}

void display(struct node *root)
{
	struct node *ptr=root;
	while(ptr)
	{
		printf("%d,%d,%s,%s-->",ptr->v1,ptr->v2,ptr->s1,ptr->s2);
		ptr=ptr->next;

	}
	printf("end");
}

main()
{
	int i,choice,pr1,pr2;
	struct node *root=NULL;
	printf("Menu:\n1.insert\n2.sort\n3.exit\n4.display\n ");
	while(1)
	{
		printf("enter ur choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			 
			root=insert_ele(root);
			break;
		case 2:
			printf("enter priorities v1=1,v2=2,s1=3,s2=4");
			scanf("%d%d",&pr1,&pr2);
			root=mergesort(root,&pr1,&pr2);
			break;
		case 3:
			exit(0);
		case 4:
			display(root);
			break;
		}
	}
}

