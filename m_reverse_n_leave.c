#include<stdio.h>
#include<stdlib.h>

struct node * create(struct node *);
struct node * insertatbegin(struct node *);
struct node * insertatend(struct node *);
void insertatpos(struct node *);
void indexelement(struct node *);
void display(struct node *);
struct node * deleteatbeg(struct node *);
struct node *deleteatend(struct node *);
struct node * deleteatpos(struct node *);
struct node * mreversenleave(struct node *,int ,int);
//void sortbubble();


struct node {
	int value;
	struct node *next;

};


main()
{
	struct node *root=NULL;
	int choice,val,m,n;
	printf("Menu\n1.create\n2.insertatbegin\n3.insertatend\n4.insertatposition\n5.indexelement\n6.display\n7.exit\n");
	printf("8.deleteatbegin\n9.deleteatend\n10.deleteatpos\n11.m reverse n leave\n");
	while(1)
	{
		printf("\nenter ur choice\n");
		scanf("%d",&choice);
		if(choice<1)
		{
			printf("are u mad ??? enter the correct input ... if u repeat this , I will kick u off");
			
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
			insertatpos(root);
			break;
		case 5:
			indexelement(root);
			break;
		case 6:
			display(root);
			break;
		case 7:
			exit(1);
		case 8:
			root=deleteatbeg(root);
			break;
		case 9:
			root=deleteatend(root);
			break;
		case 10:
			root=deleteatpos(root);
			break;
		case 11:
			printf("enter no of nodes to be reverse");
			scanf("%d",&m);
			printf("enter no of nodes to be leave ");
			scanf("%d",&n);
			root=mreversenleave(root,m,n);
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

void insertatpos(struct node *root)
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

void indexelement(struct node *root)
{
	int index,i=0;
	struct node *ptr;
	if(root!=NULL)
	{
	ptr=root;
	printf("enter the index value");
	scanf("%d",&index);
	while(i<index)
	{
		ptr=ptr->next;
		i++;
	}
	if(ptr!=NULL)
	printf("%d",ptr->value);
	else 
		printf("the postion doesnt exist");
	}
	else
		printf("there is no list");
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
	ptr=root;
	root=root->next;
	free(ptr);
	return root;
}
struct node * deleteatend(struct node *root)
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
	return root;
}
struct node * deleteatpos(struct node *root)
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
	return root;
}

 

struct node * mreversenleave(struct node *root,int k,int n)
{
	// reverse k elements, leave n elements
	 struct node *ptr1,*ptr2,*ptr3,*assign,*assign1;
	 int i=1,x=0,m=1;
	if(k<1)
	{
		return;
	}

	 if(root->next==NULL)
		 return;
	 
	 ptr1=root;
	 ptr2=ptr1->next;
	 ptr3=ptr2->next;
	 assign=ptr1;
	 assign1=ptr1;
	 while(ptr2->next!=NULL)
	 {

		 if(x==1)
		 {
			
			 if(m==n)
			 {
				 assign=ptr1;
				 assign1=ptr2;
				 ptr1=ptr2;
				 ptr2=ptr3;
				 ptr3=ptr3->next;
				 x=0;
				 m=1;
			 }
			 else
			 {
				  ptr1=ptr2;
			 ptr2=ptr3;
			 ptr3=ptr3->next;

			 m++;
			 }

		 }

		 else
		 {
		 if(i<=k)
		 {
			 root=ptr3;
			
		 }
		 if(i==k)
		 {
			 assign->next=ptr2;
			  //assign1=ptr2;
			  root=ptr1;
			  x=1;
		 }
		 

		 if(i%k==0&&i!=k)
		 {
			 assign->next=ptr1;
			 
			 assign1->next=ptr2;
			 x=1;
			 
		 }
		 if(i%k!=0)
		  ptr2->next=ptr1;
			 
			 
		 
		 ptr1=ptr2;
			 ptr2=ptr3;
			 ptr3=ptr3->next;
		 i++;
		 }

	 }
	 if(x==0)
	 {
	 if((i)%k==0)
	 {
		 
		 assign->next=ptr1;
		 assign1->next=ptr2;
	 }
	 else
	 {
		ptr2->next=ptr1;
		assign->next=ptr2;
		assign1->next=NULL;
	 }
	 }

	 return root;
}
