/*
4. given two sorted linked lists, write a function to merge the two linked lists to one sorted linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input1[200];
	char input2[200];
	char output[200];
}testDB[10]={{"123,456,456","123,456,456","123,123,456,456,456,456"},{"123,34,456,7893,321","2,5,7,11,333,8976","2,5,7,11,34,123,321,333,456,7893,8976"},
{"\0","1,2,6,3,5,7,8","1,2,3,5,6,7,8"},
{"1","1","1,1"},
{"\"","\0","\0"},
{"5+2/7,1","1,2,3","1,2,3"},
{"       12 , ,23","1,2,3","1,2,3"},
{"@w34e","\0","\0"},
{"4*2,8","\0","\0"},
{"4,3,2,1,4,5,4,6,7","5,6,123,43,5","1,2,3,4,4,4,5,5,5,6,6,7,43,123"}};

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

int list_cmp(struct node *list1,struct node *list2)
{
	while(list1!=NULL&&list2!=NULL)
	{
		if(list1->val==list2->val)
		{
			list1=list1->next;
			list2=list2->next;
		}
		else
			return 1;
	}
	if(list1==NULL&&list2==NULL)
	 return 0;
	else return 1;
}
struct node * merge(struct node *ptr1,struct node *ptr2)
{
	struct node *res,*temp;
	int flag=0;
	if(ptr1==NULL)
		return ptr2;
	if(ptr2==NULL)
		return ptr1;
	if(ptr1->val<=ptr2->val)
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
		if(ptr1->val<=ptr2->val)
		{
			
  			if(ptr1->next!=NULL&&ptr1->next->val<=ptr2->val)
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
			if(ptr2->next!=NULL&&ptr2->next->val<=ptr1->val)
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
struct node * mergesort(struct node *in1)
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
	ptr=mergesort(ptr);
	in2=mergesort(in2);
	in1=merge(ptr,in2);
	return in1;
}

void testcases()
{
	struct node *res1,*res2,*output,*res;
	char *ip1,*ip2,*op;
	int i,check;
	for(i=0;i<10;i++)
	{
		res1=res2=output=NULL;
		ip1=ip2=op=NULL;
		ip1=malloc_str(testDB[i].input1);
		ip2=malloc_str(testDB[i].input2);
		
		ip1=valid_str(ip1);
		ip2=valid_str(ip2);
		if(ip1!=NULL&&ip2!=NULL)
		{
			ip1=rem_space(ip1);
			res1=create_list(ip1);
			res1=mergesort(res1);
			res2=create_list(ip2);
			res2=mergesort(res2);
			
		}
		else
		{
			 
			if(ip1==NULL&&ip2!=NULL)
			{
				res1=NULL;
				res2=create_list(ip2);
				res2=mergesort(res2);
			}
			else if(ip1!=NULL&&ip2==NULL)
			{
				res2=NULL;
				res1=create_list(ip1);
				res1=mergesort(res1);
			}
			else
			{
				res1=NULL;
				res2=NULL;
			}

		}
		op=malloc_str(testDB[i].output);
		output=create_list(op);
		res=merge(res1,res2);
		check=list_cmp(res,output);
		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(op);
		free(ip1);
		free(res1);
		free(output);

	}

}


main()
{
	testcases();
	getch();
}
