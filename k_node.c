#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int val;
	struct node *next;
	struct node *jump;
};

static int len=0,k=1,insert_end=0;
struct node *getNode(struct node *temp)
{
	temp=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->jump=NULL;
	return temp;
}
struct node *search_ele(struct node *root,int val)
{
	 if(root==NULL)
		 return ;
	if(root->val==val)
		return root;
	if(root->next==NULL)
		return root;
	if(root->next->val>val)
		return root;
	if(root->jump&&root->jump->val<=val)
		return search_ele(root->jump,val);
	else
		return search_ele(root->next,val);

}
struct node *delete_first_node(struct node *root)
{
	struct node *ptr1,*ptr2;
	ptr1=root;
	while(ptr1)
	{
		if(ptr1->val==-1)
		{
			ptr2=ptr1->next;
			free(ptr1);
			ptr1=ptr2;
			root=ptr1;
		}
		else
		{
			return root;
		}

	}

}
struct node *remove_other_nodes(struct node *root)
{
	struct node *ptr1,*ptr2;
	ptr1=root;
	if(root==NULL)
		return;
	ptr2=ptr1->next;
	while(ptr2)
	{
		if(ptr2->val==-1)
		{
			ptr1->next=ptr2->next;
			free(ptr2);
			ptr2=ptr1->next;
			len--;
		}
		else
		{
			ptr1=ptr2;
			ptr2=ptr2->next;
		}

	}
	return root;
}

struct node * suffle(struct node *root)
{
	struct node *ptr1,*ptr2,*kroot;
	int i=0,k_len=1;
	root=delete_first_node(root);
	root=remove_other_nodes(root);
	kroot=root;
	ptr1=root;
	if(ptr1)
		ptr2=ptr1->next;
	else
		return root;
	while(ptr2)
	{
		if(k==k_len)
		{
			k_len=1;
			kroot->jump=ptr2;
			
		}
		else
		{
			
			k_len++;
		}
		ptr2=ptr2->next;

	}

	return root;

}

struct  node * insert_ele(struct node *root,int val)
{
	struct node *temp=NULL,*ptr=NULL;

	if(root==NULL)
	{
		temp=getNode(temp);
		temp->val=val;
		root=temp;

	}
	else 
	{
		ptr=search_ele(root,val);
		if(ptr->next==NULL)
			insert_end++;
	    temp=getNode(temp);
		temp->val=val;
		temp->next=ptr->next;
		ptr->next=temp;
	}	
	len++;

	if((k+1)*(k+1)<=len)
	{
		k++;
		root=suffle(root);
	}


	return root;
}
struct node * delete_ele(struct node *root,int val)
{
	struct node *ptr1=NULL,*ptr2=NULL;
	if(root==NULL)
		return ;
	 ptr1=search_ele(root,val);
	 ptr1->val=-1;
	 len--;
	 if(k*k>=len)
		 root=suffle(root);
	 return root;
}

void display(struct node *root)
{
	struct node *ptr=root;
	while(ptr)
	{
		printf("%d-->",ptr->val);
		ptr=ptr->next;

	}
	printf("end");
}
void display1(struct node *root)
{
	struct node *ptr=root;
	while(ptr!=NULL)
	{
		printf("%d-->",ptr->val);
		ptr=ptr->jump;
	}

}

main()
{
	int i,choice,val;
	struct node *root=NULL;
	printf("Menu:\n1.insert\n2.delete\n3.exit\n4.display\n5.display k roots");
	while(1)
	{
		printf("enter ur choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("enter element");
			scanf("%d",&val);
			root=insert_ele(root,val);
			break;
		case 2:
			printf("enter value");
			scanf("%d",&val);
			root=delete_ele(root,val);
			break;
		case 3:
			exit(0);
		case 4:
			display(root);
			break;
		case 5:
			display1(root);
			break;
		}

	}

	
}
