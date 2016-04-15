/* given a single(not sorted) linked list, and a value, 
delete the value from the linked list. the value may exist or may not exist in the list */

#include<stdio.h>
#include<stdlib.h>
struct node * create(struct node *);
struct node * insertatend(struct node *);
void display(struct node *);
struct node * deletevalue(struct node *,int);
struct node {
	int value;
	struct node *next;
};

main()
{
	struct node *root=NULL;
	int val;

	root=create(root);
	printf("enter a value to delete");
	scanf("%d",&val);
	root=deletevalue(root,val);
	display(root);
	getch();

}
struct node * deletevalue(struct node *root,int val)
{
	 struct node *ptr1,*ptr2;
	 ptr1=root;
	 while(ptr1->next!=NULL)
	 {
		 ptr2=ptr1->next;
		 if(ptr2->value==val)
		 {
			 
			 ptr1->next=ptr1->next->next;
			 free(ptr2);

		 }
		 else
			 ptr1=ptr1->next;
	 }

	 if(root->value==val)
	 {
		 ptr2=root;
		 root=root->next;
		 free(ptr2);
	 }

	 return root;
}

struct node * create(struct node *root)
{
	struct node *temp;
	int num,i=0;

	if(root==NULL)
	{
		printf("enter no of nodes to be created");
		scanf("%d",&num);
		while(i<num)
		{
			if(i==0)
			{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("enter the value");
		scanf("%d",&temp->value);
		temp->next=NULL;
		root=temp;
			}
			else 
			{
				root=insertatend(root);
			}
			i++;
		}
	}
	else
	{
		printf("list already created ");
		return;
	}
	return root;
}

struct node *  insertatend(struct node *root)
{
	struct node *temp,*ptr;
	if(root!=NULL)
	{
	ptr=root;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the value");
	scanf("%d",&temp->value);
	temp->next=NULL;
	ptr->next=temp;
	}
	else
		printf("there is no list ");
	return root;
}
 void display(struct node *root)
{
	struct node *ptr;
	if(root!=NULL)
	{
	ptr=root;
	while(ptr!=NULL)
	{
		printf("%d-->",ptr->value);
		ptr=ptr->next;
	}
	printf("end\n");
	}
	else
		printf("there is nothing to display");
}
