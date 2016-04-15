#include<stdio.h>
#include<stdlib.h>

struct bt
{
	int val;
	int flag,path;
	struct bt *left,*right;
};
struct bt * getNode()
{
	struct bt *temp;
	temp=(struct bt *)malloc(sizeof(struct bt));
	temp->left=NULL;
	temp->right=NULL;
	temp->flag=0;
	temp->path=0;
	return temp;
}
struct bt * insert_BT(struct bt *root,struct bt *node)
{
	struct bt *temp;
	if(root==NULL)
	{
		root=node;
	}
	else if(root->flag==0)
	{
		temp=insert_BT(root->left,node);
		root->left=temp;
		if(temp->flag==0)
		{
			if(temp->path==1)
			{
				root->path=1;
				root->flag=0;
			}
			else
			{
				root->path=1;
				root->flag=1;
			}
		}
		else 
		{
			root->flag=0;
			root->path=1;
		}
	}
	else
	{
		temp=insert_BT(root->right,node);
		root->right=temp;
		if(temp->flag==0 )
		{
			if(temp->path==0)
			{
			root->flag=0;
			root->path=0;
			}
			else
			{
				root->flag=1;
				root->path=1;
			}

		}
		else 
		{
			root->path=1;
			root->flag=1;
		}
	}
	return root;
}
void display(struct bt *root)
{
	if(root==NULL)
		return;
	else
	{
		display(root->left);
		printf("%3d-->",root->val);

		display(root->right);
	}

}

struct bt * insert_bt(struct bt *root,int val)
{
	struct bt *temp;
	temp=getNode();
	temp->val=val;
	return insert_BT(root,temp);
}
void level_order_traversal(struct bt *root)
{
	int front=0,rare=0,total=0;
	struct bt **queue;
	queue=(struct bt **)malloc(sizeof(struct bt *)*100);
	queue[rare]=root;
	if(root==NULL)
		return;
	total++;
	//queue[rare+1]=NULL;
	while(rare<total)
	{
		if(queue[rare]->left!=NULL)
		{
			queue[2*rare+1]=queue[rare]->left;
			total++;
		//	queue[2*rare+2]=NULL;
		}
		if(queue[rare]->right!=NULL)
		{
			queue[2*rare+2]=queue[rare]->right;
			total++;
			//queue[2*rare+3]=NULL;
		}
		rare++;
	}
	while(front<rare)
	{
		printf("%3d-->",queue[front]->val);
		front++;
	}
	printf("end\n");
}
void level_in_reverse_order(struct bt *root)
{
	int front=0,rare=0,total=0;
	struct bt **queue;
	queue=(struct bt **)malloc(sizeof(struct bt *)*100);
	queue[rare]=root;
	if(root==NULL)
		return;
	total++;
	//queue[rare+1]=NULL;
	while(rare<total)
	{
		if(queue[rare]->left!=NULL)
		{
			queue[2*rare+1]=queue[rare]->left;
			total++;
		//	queue[2*rare+2]=NULL;
		}
		if(queue[rare]->right!=NULL)
		{
			queue[2*rare+2]=queue[rare]->right;
			total++;
			//queue[2*rare+3]=NULL;
		}
		rare++;
	}

}

int size_of_bt(struct bt *root)
{
	if(root==NULL)
		return 0;
	return (size_of_bt(root->left)+1+size_of_bt(root->right));
}
int max_sum_level(struct bt *root)
{
	int front=0,rare=0,total=0,level=0,sum=INT_MIN,temp_sum=0,temp_total=1,temp_level=-1,level_start=0,level_end=1,i=0;
	struct bt **queue;
	queue=(struct bt **)malloc(sizeof(struct bt *)*100);
	queue[rare]=root;
	if(root==NULL)
		return 777;
	total++;
	//queue[rare+1]=NULL;
	while(rare<total)
	{
		if(queue[rare]->left!=NULL)
		{
			queue[2*rare+1]=queue[rare]->left;
			total++;
		//	queue[2*rare+2]=NULL;
		}
		if(queue[rare]->right!=NULL)
		{
			queue[2*rare+2]=queue[rare]->right;
			total++;
			//queue[2*rare+3]=NULL;
		}
		rare++;
	}
	while(front<total)
	{
		temp_level++;
		for(i=level_start;i<level_end;i++)
		{
			temp_sum=temp_sum+queue[i]->val;
		}
		if(temp_sum>sum)
		{
			sum=temp_sum;
			level=temp_level;
		}
		for(i=level_start;i<level_end;i++)
		{
			if(queue[i]->left!=NULL)
				temp_total++;
			if(queue[i]->right!=NULL)
				temp_total++;
		}
		front=level_end;
		level_start=level_end;
		level_end=temp_total;
		temp_sum=0;
	}
	return level;
}
void print_path(int path[],int path_len)
{
	int i=0;
	for(i=0;i<path_len;i++)
	{
		printf("%d-->",path[i]);
	}
	printf("end\n");
}

void print_path_bt(struct bt *root,int path[],int path_len)
{
	if(root==NULL)
	{
		
		return;
	}
	path[path_len]=root->val;
	path_len++;
	if(root->left==NULL&&root->right==NULL)
	{
		print_path(path,path_len);
	}
	else
	{
		print_path_bt(root->left,path,path_len);
		print_path_bt(root->right,path,path_len);
	}

}
int bt_is_bst(struct bt *root,int *val)
{
	int res;
	if(root==NULL)
		return 1;
	if(!root->left&&!root->right)
	{
		*val=root->val;
		return 1;
	}
	res=bt_is_bst(root->left,val);
	if(res==1)
	{
		if(*val<root->val)
			*val=root->val;
		else
			return 0;
	}
	else return 0;
	res=bt_is_bst(root->right,val);
	if(res==1)
	{
		if(*val<root->val)
			return 0;
	}
	else return 0;
	return 1;

}

main()
{
	struct bt *root=NULL;
	int val,choice,path[10],res;
	printf("MENU:\n1.insert\n2.display\n3.exit\n4.level order traversal\n5.size of bt\n6.level in reverse order\n7.max sum in level\n8.print path from root to leaf\n9.check if it is bst or not\n");
	while(1)
	{
		printf("enter ur choice\n");
		scanf("%d",&choice);
	switch(choice)
		{
		case 1:
			printf("enter value to insert\n");
			scanf("%d",&val);
			root=insert_bt(root,val);
			printf("the value is inserted in binary tree\n");
			break;
		case 2:
			display(root);
			break;
		case 3:
			exit(0);
		case 4:
			level_order_traversal(root);
			break;
		case 5:
			val=size_of_bt(root);
			printf("the size of binary tree is %d\n",val);
			break;
		case 6:
			level_in_reverse_order(root);
			break;
		case 7:
			val=max_sum_level(root);
			if(val==777)
				printf("no tree exists\n");
			else
				printf("the sum is max at %d level\n",val);
			break;
		case 8:
			print_path_bt(root,path,0);
			break;
		case 9:
			res=bt_is_bst(root,&val);
			if(res==1)
				printf("the given tree is bst\n");
			else 
				printf("the given tree is not bst\n");
			break;
		}

	}

}

