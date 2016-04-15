//middle value in a list.. choice 10 contains the function
#include<stdio.h>
#include<stdlib.h>

void create();
void insertatbegin();
void insertatend();
void insertatpos();
int middlevalueinlist();
void display();
void deleteatbeg();
void deleteatend();
void deleteatpos();



struct node {
	int value;
	struct node *next;

}*root;


main()
{
	int choice,val;
	printf("Menu\n1.create\n2.insertatbegin\n3.insertatend\n4.insertatposition\n5.display\n6.exit\n");
	printf("7.deleteatbegin\n8.deleteatend\n9.deleteatpos\n10.middle value in the list\n");
	while(1)
	{
		printf("\nenter ur choice\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			insertatbegin();
			break;
		case 3:
			insertatend();
			break;
		case 4:
			insertatpos();
			break;
		case 5:
			display();
			break;
		case 6:
			exit(1);
		case 7:deleteatbeg();
			break;
		case 8:
			deleteatend();
			break;
		case 9:
			deleteatpos();
			break;
		case 10:
			val=middlevalueinlist();
			printf("the middle element is %d",val);
			break;
		}
		
	}

	getch();

}
int middlevalueinlist()
{
	struct node *mov_one,*mov_two;
	mov_one=root;
	mov_two=root;
	while(mov_two->next!=NULL)
	{
		mov_two=mov_two->next;
		mov_one=mov_one->next;
		if(mov_two->next!=NULL)
			mov_two=mov_two->next;
	}
	return mov_one->value;
	


}


void create()
{
	struct node *temp;
	if(root==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("enter the value");
		scanf("%d",&temp->value);
		temp->next=NULL;
		root=temp;
	}
	else
	{
		printf("list already created ");
		return;
	}

}
void insertatbegin()
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
}

void insertatend()
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
}

void insertatpos()
{
	struct node *temp,*ptr;
	int pos,i=1;
	if(root!=NULL)
	{
	ptr=root;
	printf("enter the position");
	scanf("%d",&pos);
	while(i<pos)
	{
		ptr=ptr->next;
		i++;

	}
	if(ptr!=NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("enter the value");
		scanf("%d",&temp->value);
		temp->next=ptr->next;
		ptr->next=temp;

	}
	else
	{
		printf("the position doesnotexists");
		return;
	}
	}
	else 
		printf("list is not created");

}

 

void display()
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

void deleteatbeg()
{
	struct node *ptr;
	ptr=root;
	root=root->next;
	free(ptr);
}
void deleteatend()
{
	struct node *ptr,*ptr1;
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
}
void deleteatpos()
{
	struct node *ptr,*ptr1;
	int pos,i=1;
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
}
