#include<stdio.h>
#include<stdlib.h>

struct node * create(struct node *);
void insertatbegin(struct node *);
void insertatend(struct node *);
void insertatpos(struct node *);
void indexelement(struct node *);
void display(struct node *);
void deleteatbeg(struct node *);
void deleteatend(struct node *);
void deleteatpos(struct node *);
struct node * reversebyk(struct node *);
//void sortbubble();


struct node {
	int value;
	struct node *next;

};


main()
{
	struct node *root=NULL;
	int choice;
	printf("Menu\n1.create\n2.insertatbegin\n3.insertatend\n4.insertatposition\n5.indexelement\n6.display\n7.exit\n");
	printf("8.deleteatbegin\n9.deleteatend\n10.deleteatpos\n11.reversebyk\n");
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
			insertatbegin(root);
			break;
		case 3:
			insertatend(root);
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
		case 8:deleteatbeg(root);
			break;
		case 9:
			deleteatend(root);
			break;
		case 10:
			deleteatpos(root);
			break;
		case 11:
			root=reversebyk(root);
			break;
		}
		}
	}

	getch();

}

struct node * create(struct node *root)
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
void insertatbegin(struct node *root)
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

void insertatend(struct node *root)
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

void deleteatbeg(struct node *root)
{
	struct node *ptr;
	ptr=root;
	root=root->next;
	free(ptr);
}
void deleteatend(struct node *root)
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
void deleteatpos(struct node *root)
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

struct node * reversebyk(struct node *root)
{
	 struct node *ptr1,*ptr2,*ptr3,*assign,*assign1;
	 int i=1,k;
	 printf("enter the key value");
	 scanf("%d",&k);
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
		 if(i<=k)
		 {
			 root=ptr3;
			
		 }
		 if(i==k)
		 {
			  assign1=ptr2;
			  root=ptr1;
		 }
		 if(i%k==0&&i!=k)
		 {
			 assign->next=ptr1;
			 assign=assign1;
			 assign1=ptr2;
			 
		 }
		 else
		 {
			 ptr2->next=ptr1;
			 
			 
		 }
		 ptr1=ptr2;
			 ptr2=ptr3;
			 ptr3=ptr3->next;
		 i++;

	 }
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

	 return root;
}
