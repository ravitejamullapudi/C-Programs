#include<stdio.h>
#include<stdlib.h>

struct node * create(struct node *);
struct node * insertatbegin(struct node *);
struct node * insertatend(struct node *);
struct node * insertatpos(struct node *);
void display(struct node *);
struct node * deleteatbeg(struct node *);
struct node *deleteatend(struct node *);
struct node * deleteatpos(struct node *);
struct node * reverse(struct node *);


struct node {
	int value;
	struct node *next;

};
main()
{
	struct node *root=NULL;
	int choice,val;
	printf("Menu\n1.create\n2.insertatbegin\n3.insertatend\n4.insertatposition\n5.display\n6.exit\n");
	printf("7.deleteatbegin\n8.deleteatend\n9.deleteatpos\n10.reverse the listwithout recursion\n\n");
	while(1)
	{
		printf("\nenter ur choice\n");
		scanf("%d",&choice);
		if(choice<1)
		{
			printf(" enter the correct input ... ");
			
		}
		else {

		switch (choice)
		{
		case 1:
			root=create(root);
			break;
		case 2:
			root=insertatbegin(root);
			break;
		case 3:
			root=insertatend(root);
			break;
		case 4:
			root=insertatpos(root);
			break;
		 
		case 5:
			display(root);
			break;
		case 6:
			exit(1);
		case 7:
			root=deleteatbeg(root);
			break;
		case 8:
			root=deleteatend(root);
			break;
		case 9:
			root=deleteatpos(root);
			break;
		case 10:
			 root=reverse(root);
			 break;
		}
		}
	}

	getch();

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
struct node * insertatbegin(struct node *root)
{
	struct node *temp;
	if(root!=NULL)
	{
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the value");
		scanf("%d",&temp->value);
		temp->next=root;
		root=temp;
	}
	else
		printf("there is no list");
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

struct node * insertatpos(struct node *root)
{
	struct node *temp,*ptr;
	int pos,i=1;
	if(root==NULL)
	{
		printf("enter the list first");
		root=NULL;
		return;
	}

	if(root!=NULL)
	{
	ptr=root;
	printf("enter the position");
	scanf("%d",&pos);
	while(i<pos)
	{
		ptr=ptr->next;
		i++;
		if(ptr==NULL)
			{
				printf("the position doesnotexists");
				return;
			}

	}
	
		temp=(struct node *)malloc(sizeof(struct node));
		printf("enter the value");
		scanf("%d",&temp->value);
		temp->next=ptr->next;
		ptr->next=temp;

	
	
	
	}
	
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

struct node * deleteatbeg(struct node *root)
{
	
	struct node *ptr;
	if(root==NULL)
	{
		printf("there is nothing to delete");
		root=NULL;
		return;
	}

	ptr=root;
	root=root->next;
	free(ptr);
	return root;
}
struct node * deleteatend(struct node *root)
{
	struct node *ptr,*ptr1;
	if(root==NULL)
	{
		printf("there is nothing to delete");
		root=NULL;
		return;
	}

	if(root!=NULL)
	{
	ptr=root;
	if(ptr->next!=NULL)
	{
	while(ptr->next->next!=NULL)
	{
		ptr=ptr->next;

	}
	ptr1=ptr->next;
	ptr->next=NULL;
	free(ptr1);
	}
	else 
	{
		free(ptr);
		root=NULL;
	}
	}
	else 
		printf("list is not yet created");
	return root;
}
struct node * deleteatpos(struct node *root)
{
	struct node *ptr,*ptr1;
	int pos,i=1;
	if(root==NULL)
	{
		printf("there is nothing to delete");
		root=NULL;
		return;
	}

	ptr=root;
	printf("enter the index to delete ");
	scanf("%d",&pos);
	while(i<pos)
	{
		ptr=ptr->next;
		i++;
	}
	if(ptr!=NULL)
	{
	ptr1=ptr->next;
	ptr->next=ptr->next->next;
	free(ptr1);
	}
	else 
		printf("there is such index");
	return root;
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

 