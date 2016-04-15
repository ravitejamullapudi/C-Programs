#include<stdio.h>
#include<stdlib.h>

void create();
void insert();
void display1(struct node *);
struct node 
{
	int value;
	struct node *left,*right;
}*root;

void main()
{
	int choice;
printf("1.create\n2.insert\n3.display\n4.exit\n");

while(1)
{
	printf("enter ur choice");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		create();
		break;
	case 2:
		insert();
		break;
	case 3:
		display1(root);
		break;
	case 4:
		exit(1);
	}

}
}
void create()
{
	int val;
	struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   printf("enter the value");
   scanf("%d",&val);
   temp->value=val;
   temp->left=NULL;
   temp->right=NULL;
   root=temp;
}


void insert()
{
	int val;
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	printf("enter the value");
	scanf("%d",&val);
	temp->value=val;
	ptr=root;
	while(ptr!=NULL)
	{
		if(temp->value<ptr->value)
		{
			ptr=ptr->left;
		}
		else 
			ptr=ptr->right;


	}
	ptr=temp;

}

void display1(struct node *ptr)
{
	if(ptr->left==NULL&&ptr->right==NULL)
	{
		printf("%d",ptr->value);
	}
	else
	{
		display1(ptr->left);
		printf("%d",ptr->value);
		display1(ptr->right);
	}

}
