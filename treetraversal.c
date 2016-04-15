#include<stdio.h>
#include<stdlib.h>

void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node * create(struct node *);
struct node * createnode(int);
int sizeoftree(struct node *);
int maxdepth(struct node *);
struct node 
{
	int value;
	struct node *left;
	struct node *right;
};

main()
{
	struct node *root=NULL;
	int n,choice;

	printf("Menu \n 1.create\n 2.inorder\n3.preorder \n4.postorder");
	while(1)
	{
		printf("enter the choice ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			root=create(root);
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			inorder(root);
			break;
		case 4:
			postorder(root);
			break;
		case 5:
			n=sizeoftree(root);
			printf("the sizeof tree is %d",n);
			break;
		case 6:
			n=maxdepth(root);
			printf("the max depth is %d",n);
			break;
		}
	

	}

		getch();

}

struct node * create(struct node *root)
{
	root=createnode(1);
	root->left=createnode(2);
	root->right=createnode(3);
	root->left->left=createnode(4);
	root->left->right=createnode(5);

	root->left->left->left=createnode(6);
	return root;

}
struct node * createnode(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->value=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorder(struct node *root)
{
	if(root ==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d",root->value);
		inorder(root->right);
	
	}

}

void preorder(struct node *root)
{
	if(root ==NULL)
		return;
	else
	{
		printf("%d",root->value);
		preorder(root->left);
		
		preorder(root->right);
	
	}

}

void postorder(struct node *root)
{
	if(root ==NULL)
		return;
	else
	{
		
		postorder(root->left);
		
		postorder(root->right);
		printf("%d",root->value);
	
	}

}

int sizeoftree(struct node *root)
{
	int l,r;
	if(root==NULL)
		return 0;
	else
	{
		l=sizeoftree(root->left);
		r=sizeoftree(root->right);
		return l+r+1;
	}

}

int maxdepth(struct node *root)
{
	int l,r;
	if(root==NULL)
		return 0;
	else
	{
		l=maxdepth(root->left);
		r=maxdepth(root->right);
		if(l>r)
			return l+1;
		else 
			return r+1;
	}

}
