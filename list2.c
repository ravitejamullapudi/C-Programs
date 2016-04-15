/*
2. Given a sorted linked list as input (remember you have to create this in your program using the test stub and the above program)
and a value, write  
a. add the element to the linked list if it doesnt exist
b. delete the element from the linked list if it exists

*/
#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input[200];
	int add_ele;
	int del_ele;
	char output[200];

}testDB[3]={{"123,456,456",4,6,"4,123,456,456"},{"12,34,45,78",34,34,"12,45,78"},
{"1,2,3,4,5",2,6,"1,2,3,4,5"}};

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
	int num=0,i=0;
	if(ip==NULL)
		return NULL;
	while(ip[i]!='\0')
	{
		num=0;
		while(ip[i]!=','&&ip[i]!='\0')
		{
			num=num*10+ip[i]-'0';
			i++;
		}
		start=create_linked_list(start,num);
		i++;
	}
	return start;
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
struct node * insert_begin(struct node *start,int val)
{
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=start;
	start=temp;
	return start;
}

struct node * add_ele_in_list(struct node *start,int val)
{
	struct node *temp, *ptr1,*ptr2;
	ptr1=start;
	if(ptr1==NULL)return NULL;
	ptr2=ptr1->next;
	
	if(val==ptr1->val)
		return start;
	if(val<ptr1->val)
	{
		start=insert_begin(start,val);
		return start;
	}
	
	while(ptr2!=NULL)
	{
		if(ptr2->val==val)
			return start;
		if(ptr2->val>val)
			break;
		else
		{
			ptr1=ptr2;
			ptr2=ptr2->next;
		}

	}
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=ptr2;
	ptr1->next=temp;
	return start;
}
struct node * del_ele_in_list(struct node *start,int val)
{
	struct node *ptr1,*ptr2;
	ptr1=start;
	if(ptr1==NULL)return start;
	ptr2=ptr1->next;
	if(ptr1->val==val)
	{
		start=ptr2;
		free(ptr1);
		return start;
	}
	
	while(ptr2!=NULL)
	{
		if(ptr2->val==val)
		{
			ptr1->next=ptr2->next;
			free(ptr2);
			return start;
		}
		ptr1=ptr2;
		ptr2=ptr2->next;
	}
	return start;
}

void testcases()
{
	struct node *res,*output;
	char *ip,*op;
	int i,check;
	for(i=0;i<3;i++)
	{
		res=output=NULL;
		ip=op=NULL;
		ip=malloc_str(testDB[i].input);
		
		ip=valid_str(ip);
		if(ip!=NULL)
		{
			ip=rem_space(ip);
			res=create_list(ip);
			res=add_ele_in_list(res,testDB[i].add_ele);
			//printf("%d",res->val);
			res=del_ele_in_list(res,testDB[i].del_ele);
		}
		else
		{
			res=NULL;
		}

		op=malloc_str(testDB[i].output);
		output=create_list(op);	
		check=list_cmp(res,output);
		//display(res);
		//display(output);
		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(op);
		free(ip);
		free(res);
		free(output);

	}

}


main()
{
	testcases();
	getch();
}
