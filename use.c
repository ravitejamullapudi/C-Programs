#include<stdio.h>
#include<stdlib.h>
struct node
{
		int val;
		struct node *left,*right,*parent;
};
struct node *find_leaf(struct node *root,int parent)
{
	struct node *temp;
	if(root==NULL)
		return NULL;
	 if(root->val==parent)
		return root;
	 temp=find_leaf(root->left,parent);
	 if(temp!=NULL)
		 return temp;
	 temp=find_leaf(root->right,parent);
	 return temp;
}

struct node * create_bt(struct node *root,int parent, int child)
{
	struct node *temp,*temp1;
	temp=(struct node *)malloc(sizeof(struct node ));
	temp->val=child;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		temp1=(struct node *)malloc(sizeof(struct node ));
		temp1->val=parent;
		temp1->left=NULL;
		temp1->right=NULL;
		temp1->parent=NULL;
		temp->parent=root;
		root=temp1;
		root->left=temp;

	}
	else
	{
		temp1=find_leaf(root,parent);
		if(temp1->left==NULL)
		{
			temp1->left=temp;
			temp->parent=temp1;
		}
		else 
		{
			temp1->right=temp;
			temp->parent=temp1;
		}
	}
	return root;
}
void display(struct node *root)
{
	if(root==NULL)
		return ;
	display(root->left);
	printf("%d->",root->val);
	display(root->right);
}
int commonansi(struct node *root,struct node *n1,struct node *n2)
{

}

void random(struct node *root)
{
	struct node *root1,*root2;
	int res,flag1=0,flag2=0;
	if(root==NULL)
		return;
	root1=root;
	root2=root;

	while(root1==NULL||root2==NULL)
	{
		res=commonansi(root,root1,root2);
		printf("%d,%d=%d",root1->val,root2->val,res);
		if(flag2==0&&root2->left!=NULL)
		{
			root2=root2->left;
			continue;
		}
		if(
		

	}

}

int main()
{
	int child,parent;
	struct node *root=NULL;
	while(1)
	{
		printf(">");
		scanf("%d%d",&child,&parent);
		if(child==777&&parent==777)
			break;
		root=create_bt(root,parent,child);
		random(root);

	}
	display(root);
	
	getch();
	return 0;

}
