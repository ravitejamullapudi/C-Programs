/*1. given a number create a single linked list where each node has one digit in it. 
your code need to have linked list created (not print 1->2->3  on the console). f
or example if I give 1234 as input in the memory linked list should be created with
a node 1 pointing to node 2 pointing to node 3 pointing to node4
*/
#include<stdio.h>
#include<stdlib.h>
struct node * divideoneeach(struct node *,int);
struct node * creatlist(struct node *,int);
void display(struct node * );
struct node 
{
	int val;
	struct node *next;
};

main()
{
	int value,flag=0;
	struct node *root=NULL;

	printf("enter the value ");
	scanf("%d",&value);
	 
	if(value<0)
	{
		value=-value;
		flag=1;
	}
	 root=divideoneeach(root,value);
	if(flag==1)
	{
		root->val=-root->val;
	}
	
	 display(root);
	 getch();

}

struct node * divideoneeach(struct node *root,int value)
{
	int res;
	while(value>0)
	{
		res=value%10;
		root=creatlist(root,res);
		value=value/10;

	}
	return root;
}
struct node * creatlist(struct node *root,int res)
{
	struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->val=res;
		temp->next=NULL;
	if(root==NULL)
	{
		
		root=temp;
	}
	else
	{
		temp->next=root;
		root=temp;

	}
	return root;
}
void display(struct node *root)
{
	struct node *ptr;
	ptr=root;
	while(ptr!=NULL)
	{
		printf("%d-->",ptr->val);
		ptr=ptr->next;
	}
	printf("end");

}
