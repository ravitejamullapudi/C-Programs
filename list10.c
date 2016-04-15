#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input[200];
	int k;
	char output[200];
}testDB[9]={{"123,456,456,345,545,6,7,8,9",2,"123,456,545,6,9"},{"123,34,456,7893,321",3,"123,34,456"},
{"\0",3,"\0"},
{"1",1,"1"},
{"\"",2,"\0"},
{"5+2/7,1",3,"\0"},
{"       12 , ,23",4,"\0"},
{"@w34e",5,"\0"},
{"1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0",3,"1,2,3,7,8,9,3,4,5,9,0"}};

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
struct node * keepk_remk(struct node *root, int k)
{
	struct node *ptr1,*ptr2,*ptr3;
	int i=1,j=1;
	ptr1=root;
	if(ptr1==NULL)
		return;
	ptr2=ptr1->next;
	if(ptr2==NULL)
		return root;
	if(k==0)
		return root;
	ptr3=ptr2->next;
	while(ptr2!=NULL)
	{
		if(i<k)
		{
			ptr1=ptr2;
			ptr2=ptr3;
			if(ptr2!=NULL)
				ptr3=ptr3->next;
			i++;
		}
		else
		{
			ptr1->next=ptr3;
			free(ptr2);
			ptr2=ptr3;
			if(ptr2!=NULL)
				ptr3=ptr3->next;
			
			if(i==j)
			{
				i=0;
				j=1;
			}
			else
			j++;
		}

	}
	return root;
}

void testcases()
{
	struct node *res,*output;
	char *ip,*op;
	int i,check;
	for(i=0;i<9;i++)
	{
		res=output=NULL;
		ip=op=NULL;
		ip=malloc_str(testDB[i].input);
		
		ip=valid_str(ip);
		//if(ip==NULL)
			//printf("hai\n");
		if(ip!=NULL)
		{
			ip=rem_space(ip);
			res=create_list(ip);
			res=keepk_remk(res,testDB[i].k);
		}
		else
		{
			res=NULL;
		}
		op=malloc_str(testDB[i].output);
		output=create_list(op);
		//if(res==NULL)
			
		check=list_cmp(res,output);
		display(res);
		display(output);
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