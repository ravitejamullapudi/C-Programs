#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void create(void);
void display();
void insertend();
void insertbegin();
void insertpos();
void deletebegin();
void deleteend();
struct node
{
	int value;
	struct node *link;
}*start;

main()
{
	int choice;
	printf("Menu :\n1.create\n2.insertatbeginning\n3.insertatend\n4.insertpos\n5.deleteatbeginning\n6.deleteatend\n7.deleteatpos\n8.display\n9.exit");
	while(1)
	{
	printf("\nenter the choice");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		create();
		break;
	case 2: 
		insertbegin();
		break;

	case 3:
		insertend();
		break;
	case 4:
		insertpos();
		break;
	case 5:
		deletebegin();
		break;
	case 6:
		deleteend();
		break;
	case 8:
		display();
		break;
	case 9:
		exit(0);

	}
	}
	getch();
}


void create()
{
	int val,n,i;
	struct node *temp;
printf("enter no of nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	if(start==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("enter the value");
		scanf("%d",&val);
		temp->value=val;
		temp->link=NULL;
		start=temp;
	}
	else
	insertend();	
 }
}
void display()

{
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("%d-->",temp->value);
		temp=temp->link;

	}
	printf("end\n");
}

void insertend()
{
	int val;
	struct node *temp,*ptr=start;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	temp=(struct node *)malloc(sizeof(struct node ));
	printf("enter the value");
	scanf("%d",&val);
	temp->value=val;
	temp->link=NULL;
	ptr->link=temp;
}

	
void insertbegin()
{ 
	int val;
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the value");
	scanf("%d",&val);
	temp->link=start;
	temp->value=val;
		start=temp;
}
void insertpos()
{
	struct node *temp,*ptr;
	int val,i,n;
	printf("enter the position");
	scanf("%d",&n);
	if(n==1)
		insertbegin();
	else
	{
		ptr=start;
		for(i=1;i<n-1;i++)
		{
			ptr=ptr->link;
		}
		if(ptr==NULL)
		{
			printf("the position is not there ");
			return;
		}
		else
		{
			temp=(struct node *)malloc(sizeof(struct node));
			printf("enter the value");
			scanf("%d",&val);
			temp->value=val;
				temp->link=ptr->link;
				ptr->link=temp;
		}
	}
}

void deletebegin()
{
	struct node *ptr;
	ptr=start;
	start=start->link;
	free(ptr);
}
void deleteend()
{
	struct node *ptr,*ptr1;
	ptr=start;
	if(ptr->link==NULL)
		deletebegin();
	else
	{
	while(ptr->link->link!=NULL)
		ptr=ptr->link;
	ptr1=ptr->link;
	ptr->link=NULL;
	free(ptr1);
	}
}