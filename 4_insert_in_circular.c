/*3. given a single, sorted linked list convert that into a single, sorted, circular linked list.
for example 1->2->3->NULL should be 1->2->3->1 */

#include<stdio.h>
#include<stdlib.h>
struct node * create(struct node *);
struct node * insertatend(struct node *);
struct node * converttocircular(struct node *);
struct node * insert_in_circular(struct node *,int);
void display(struct node *);
struct node {
	int value;
	struct node *next;

};

main()
{
	struct node *root=NULL;
	int val;

	root=create(root);
	root=converttocircular(root);
	printf("the circular linked list is \n");
	display(root);
	printf("\nenter a value to insert in the circular list\n");
	scanf("%d",&val);
	root=insert_in_circular(root,val);
	display(root);
	getch();

}
struct node * insert_in_circular(struct node *root,int val)
{
	struct node *ptr,*temp;
	ptr=root;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->value=val;
	temp->next=NULL;
	while(ptr->next!=root)
	{
		if(ptr->value<=val&&ptr->next->value>=val)
		{
			temp->next=ptr->next;
			ptr->next=temp;
			return root;
		}
		ptr=ptr->next;

	}
	if(ptr->value<val)
	{
		temp->next=ptr->next;
		ptr->next=temp;
	}
	else
	{
		temp->next=ptr->next;
		ptr->next=temp;
		root=temp;
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

struct node * converttocircular(struct node *root)
{
	struct node *ptr=root;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=root;
	return root;
}
void display(struct node *root)
{
	struct node *ptr;
	ptr=root;
	printf("%d-->",ptr->value);
	while(ptr->next!=root)
	{
		ptr=ptr->next;
		printf("%d-->",ptr->value);
		
	}
	printf("%d-->end",ptr->next->value);

}
