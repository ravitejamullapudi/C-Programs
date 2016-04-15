#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input1[200];
	 char input2[200];
}testDB[2]={{"1,2,3,4,5,6","1,2,3,4,5,6"},{"3,4,5,2,3","1,2,3,5,6,2,3,4"}};

struct node 
{
	int val;
	struct node *next;
};
int str_len(char ip[])
{
	int i=0;
	while(ip[i++]!=NULL);
	return i;
}

char * malloc_str(char ip[])
{
	char *input=NULL;
	int i=0,len;
	len=str_len(ip);
	input=(char *)malloc(sizeof(char )*(len+1));
	for(i=0;i<len;i++)
		input[i]=ip[i];
	input[i]='\0';
	return input;

}
void display(struct node *start)
{
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d-->",ptr->val);
		ptr=ptr->next;
	}
	printf("end\n");
}
char * valid_str(char *ip)
{
	int i=0,j=-1,flag=0;
	while(ip[i]!='\0')
	{
		if(ip[i]==' ')
		{
			if(j==-1);
			else
			{
				if(ip[j]==',');
				if(ip[j]>='0'&&ip[j]<='9')
				{
					flag=1;
				}
			}
		}
		else if(ip[i]>='0'&&ip[i]<='9')
		{
			if(flag==0)
				j=i;
			if(flag==1)
				return NULL;
		}
		else if(ip[i]==',')
		{
			if(j==-1)
				return NULL;
			if(ip[j]==',')
				return NULL;
			if(ip[j]>='0'&&ip[j]<='9')
			{
				j=i;
				flag=0;
			}
			

		}
		else
			return NULL;
	
		i++;
	}
	if(ip[j]==',')
		return NULL;
	return ip;
}
char * rem_space(char *ip)
{
	int i=0,j=0;
	while(ip[i]!='\0')
	{
		if(ip[i]!=' ')
		{
			if(i==j)
				j++;
			else 
			{
				ip[j]=ip[i];
				j++;
			}


		}
		i++;
	}
	ip[j]='\0';
	return ip;
}
struct node * create_linked_list(struct node *start,int num)
{
	struct node *temp,*ptr;
	int i;
	if(start==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->val=num;
		temp->next=NULL;
		start=temp;
		return start;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		temp=(struct node *)malloc(sizeof(struct node));
		temp->val=num;
		temp->next=NULL;
		ptr->next=temp;
		return start;
	}

}

struct node * create_list(char *ip)
{
	struct node *start=NULL;
	int num=0,i=0,temp;
	if(ip==NULL)
		return NULL;
	while(ip[i]!='\0')
	{
		num=0;
		while(ip[i]!=','&&ip[i]!='\0')
		{
			temp=ip[i]-'0';
			num=num*10+temp;
			i++;
		}
		start=create_linked_list(start,num);
		i++;
	}
	return start;
}
struct node * reverse(struct node *root)
{
	struct node *ptr1,*ptr2,*ptr3;
	if(root==NULL)
	{
		printf("enter the list first");
		return;

	}

	if(root->next==NULL)
		return ;
	ptr1=root;
	ptr2=ptr1->next;
	ptr3=ptr2->next;
	while(ptr2->next!=NULL)
	{
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
		ptr3=ptr3->next;
	}
	ptr2->next=ptr1;
	root->next=NULL;
	root=ptr2;
	return root;
}

struct node * addlists(struct node *list1,struct node *list2)
{
	struct node *reslist=NULL,*temp;
	int carry=0,sum=0;
	list1=reverse(list1);
	list2=reverse(list2);
	while(list1&&list2)
	{
		sum=carry+list1->val+list2->val;
		if(sum>9)
		{
			sum-=10;
			carry=1;
		}
		else
			carry=0;
		reslist=create_linked_list(reslist,sum);
		list1=list1->next;
		list2=list2->next;
	}
	while(list1)
	{
		reslist=create_linked_list(reslist,list1->val+carry);
		carry=0;
		list1=list1->next;
	}
	while(list2)
	{
		reslist=create_linked_list(reslist,list2->val+carry);
		carry=0;
		list2=list2->next;

	}
	if(carry==1)
		reslist=create_linked_list(reslist,carry);

	return reslist;
}

void testcases()
{
	struct node *res1,*res2,*output,*res;
	char *ip1,*ip2,*op;
	int i,check;
	for(i=0;i<2;i++)
	{
		res1=NULL;
		res2=NULL;
		output=NULL;
		ip1=NULL;
		op=NULL;
		ip2=NULL;
		ip1=malloc_str(testDB[i].input1);
		ip2=malloc_str(testDB[i].input2);
		ip1=valid_str(ip1);
		ip2=valid_str(ip2);
		//if(ip==NULL)
			//printf("hai\n");
		if(ip1!=NULL&&ip2!=NULL)
		{
			ip1=rem_space(ip1);
			ip2=rem_space(ip2);
			res1=create_list(ip1);
			res2=create_list(ip2);
			res=addlists(res1,res2);
			res=reverse(res);

			
		}
		
		
		//check=list_cmp(res,output);
		display(res);
		 
		free(op);
		free(ip1);
		free(res);
		free(output);

	}

}


main()
{
	testcases();
	getch();
}
