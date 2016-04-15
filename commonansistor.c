#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#pragma warning(disable:4996)


struct node
{
	int value;
	struct node *left,*right;

};

struct test
{
	char input[30];
	int n1;
	int n2;
	int res;
}testDB[3]={{"1,2,3,4,5",2,3,2},{"3,2,1,4,5",2,4,3},{"2,1,3,4,5",1,3,2}};
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
struct node * search(struct node *root,int val)
{
	if(root->value==val)
		return root;
	else if(root->value>val)
	{
		if(root->left==NULL)
			return root;
	return search(root->left,val);
	}
	else 
	{
		if(root->right==NULL)
			return root;

			return search(root->right,val);
	}
}

struct node * create_tree(struct node *root,int val)
{ 
	struct node *temp,*ptr=root;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->value=val;
	temp->right=NULL;
	temp->left=NULL;

	if(ptr==NULL)
	{
		root=temp;
		//printf("%d inserted\n",root->value);
	}
	else
	{
		ptr=search(ptr,val);
		if(ptr->value>val)
			ptr->left=temp;
		else
			ptr->right=temp;
		//printf("%d insertd\n",root->value);
	}

	return root;
}
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}

int commonansi(struct node *root,int n1,int n2)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return root->value;
	if(n1>n2)
		swap(&n1,&n2);
	if(root->value>=n1&&root->value<=n2)
		return root->value;
	if(n2<root->value)
		return commonansi(root->left,n1,n2);
	else
		return commonansi(root->right,n1,n2);
}
 
struct node * createtree(char *ip)
{
	struct node *start=NULL;
	int num=0,i=0,temp;
	if(ip==NULL)
		return NULL;
	while(ip[i]!='\0')
	{
```````````		num=0;
		while(ip[i]!=','&&ip[i]!='\0')
		{
			temp=ip[i]-'0';
			num=num*10+temp;
			i++;
		}
		start=create_tree(start,num);
		i++;
	}
	return start;
}
void display(struct node *root)
{
	if(root==NULL)
		return;
	display(root->left);
	printf("%d->",root->value);
	display(root->right);
	
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
			res=createtree(ip);
			//display(res);
			//printf("\n");
			check=commonansi(res,testDB[i].n1,testDB[i].n2);
			printf("%d\n",check);
		}
		else
		{
			res=NULL;
		}
		 
		
		
		 
		free(op);
		free(ip);
		free(res);
		free(output);

	}

}

int main()
{
	testcases();
	_getch();
	return 0;
}

