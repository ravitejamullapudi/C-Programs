/*
3. given an unsorted linked list as input, sort the linked list. dont use values to move, use pointers to make it sorted
*/

#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input[200];
	float value;
}testDB[10]={{"123,456,456",456.0000},{"123,34,456,7893,321",321.0000},
{"\0",0.0000},
{"1",1.0000},
{"\"",0.0000},
{"5+2/7,1",0.0000},
{"       12 , ,23",0.0000},
{"@w34e",0.0000},
{"4*2,8",0.0000},
{"1,2,3,4",2.5000}};

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
/*void display(struct node *start)
{
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d-->",ptr->val);
		ptr=ptr->next;
	}
	printf("end\n");
}*/
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
int val_cmp(float val1,float val2)
{
	if(val1==val2)return 0;
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
float get_median(struct node * root)
{
	struct node *ptr,*half;
	int flag=0;
	ptr=half=root;
	if(root==NULL)
		return 0;
	if(root->next==NULL)
		return root->val;
	while(ptr->next!=NULL)
	{
		flag=0;
		ptr=ptr->next;
		if(ptr->next!=NULL)
		{
			half=half->next;
			ptr=ptr->next;
			flag=1;
		}

	}
	if(flag==1)
		return half->val;
	else 
		return (float)(half->val+half->next->val)/2;
}

void testcases()
{
	struct node *res;
	char *ip;
	int i,check;
	float res1;
	for(i=0;i<10;i++)
	{
		res=NULL;
		ip=NULL;
		ip=malloc_str(testDB[i].input);
		
		ip=valid_str(ip);
		if(ip!=NULL)
		{
			ip=rem_space(ip);
			res=create_list(ip);
			res=mergesort(res);
			res1=get_median(res);
		}
		else
		{
			res1=0;
		}
			
		check=val_cmp(res1,testDB[i].value);
		//printf("%f\t%f\n",res1,testDB[i].value);
		
		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		
		free(ip);
		free(res);
		

	}

}


main()
{
	testcases();
	getch();
}
