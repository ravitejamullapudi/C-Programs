#include<stdio.h>
#include<stdlib.h>

struct node * create(struct node *);
struct node * insert(struct node *);
struct node * find(struct node *,int);
void display(struct node *);
struct node 
{
	int value,choice;
	struct node *left,*right;

};

main()
{
	struct node *root=NULL,*ptr;
	int choice,n;

	printf("Menu\n1.create\n2.insert\n3.find\n4.display\n");
	while(1)
	{
		printf("enter ur choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			root=create(root);
			break;
		case 2:
			root=insert(root);
			break;
		case 3:
			printf("enter the value");
			scanf("%d",&n);
			ptr=find(root,n);
			break;
		case 4:
			display(root);
			break;
		}

	}
	getch();
}
struct node * create(struct node *root)
{
	int n,i;
	struct node *temp;
	printf("enter the no of nodes ");
	scanf("%d",&n);
	if(root==NULL)
	{
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				temp=(struct node *)malloc(sizeof(struct node));
				printf("enter the value");
				scanf("%d",&(temp->value));
				temp->right=NULL;
				temp->left=NULL;
				root=temp;

			}
			else
				root=insert(root);
		}

	}
	else 
	{
		printf("there is no tree ");
		return;
	}

	return root;
}


void display(struct node *root)
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		return;
	else
	{
		display(root->left);
		printf("%d-->",root->value);
		display(root->right);

	}

}

struct node * insert(struct node * root)
{
	struct node *ptr;
}
struct node * find(struct node *root,int n)
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		return ;
	else 
	{
		if(ptr->value==n)
		{
			printf("value exists");
			return;

		}
		else 
		{
			
		}

	}



}
