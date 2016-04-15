#include<stdio.h>
#include<stdlib.h>

struct list 
{ 
	int val;
	struct list *next;
};
struct list * getNode()
{
	struct list *temp;
	temp=(struct list *)malloc(sizeof(struct list));
	if(!temp)
	{
		printf("memory error\n");
		return NULL;
	}
	temp->next=NULL;
	return temp;
}

struct list * insert_at_begin(struct list *root,int val)
{
	struct list *temp;
	temp=getNode();
	temp->val=val;
	temp->next=root;
	root=temp;
	return root;
}
struct list * insert_at_end(struct list *root,int val)
{
	struct list *temp,*ptr;
	temp=getNode();
	temp->val=val;
	if(root==NULL)
		root=temp;
	else
	{
		ptr=root;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
		return root;
	}

}
struct list * insert_at_pos(struct list *root, int val,int pos)
{
	struct list *temp,*ptr;
	int count=1;
	ptr=root;
	if(pos<0)
	{
		printf("no such position\n");
		return root;
	}

	if(pos==0)
	{
		root=insert_at_begin(root,val);
		printf("inserted at given position\n");
		return root;
	}
	if(root==NULL)
	{
		printf("no such position\n");
		return root;
	}

	while(count<pos)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("no such position\n");
			return root;

		}
		
		count++;
	}
	temp=getNode();
	temp->val=val;
	temp->next=ptr->next;
	ptr->next=temp;
	printf("inserted at given position\n");
	return root;
}
struct list * delete_at_begin(struct list *root)
{
	struct list *temp;
	temp=root;
	root=root->next;
	free(temp);
	return root;
}
struct list * delete_at_end(struct list *root)
{
	struct list *ptr,*temp;
	ptr=root;
	if(ptr==NULL)
	return root;
	if(ptr->next==NULL)
	{
		root=NULL;
		free(ptr);
		return root;
	}

	while(ptr->next->next!=NULL)
		ptr=ptr->next;
	temp=ptr->next;
	ptr->next=NULL;
	free(temp);
	return root;
}
struct list * delete_at_pos(struct list *root, int pos)
{
	struct list *ptr, *temp;
	int count=1;
	ptr=root;
	if(pos<0)
	{
		printf("no such posion\n");
		return root;
	}
	if(pos==0)
	{
		root=delete_at_begin(root);
		printf("deleted at given pos\n");
		return root;
	}
	while(count<pos)
	{
		if(ptr==NULL)
		{
			printf("no such position\n");
			return root;
		}
		ptr=ptr->next;
		count++;
	}
	temp=ptr->next;
	ptr->next=ptr->next->next;
	free(temp);
	return root;
}
void display(struct list *root)
{
	struct list *ptr;
	ptr=root;
	if(root==NULL)
		printf("nothing to display\n");
	else
	{
	while(ptr)
	{
		printf("%d-->",ptr->val);
		ptr=ptr->next;
	}
	printf("end\n");
	}
}

main()
{
	struct list *root=NULL;
	int choice,pos,val;
	printf("MENU : \n1.create\n2.insert at begin\n3.insert at end\n4.insert at pos\n5.delete at begin\n6.delete at end\n7.delete at pos\n8.display\n9.exit\n");
	while(1)
	{
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			if(root!=NULL)
			printf("list is already created\n");
			else
			{
				printf("enter value\n");
				scanf("%d",&val);
				root=insert_at_end(root,val);
				printf("list is created\n");
			}
			break;
		case 2:
			printf("enter value\n");
			scanf("%d",&val);
			root=insert_at_begin(root,val);
			printf("value is inserted at begin\n");
			break;
		case 3:
			printf("enter the value\n");
			scanf("%d",&val);
			root=insert_at_end(root,val);
			printf("val is inserted at end\n");
			break;
		case 4:
			printf("enter val\n");
			scanf("%d",&val);
			printf("enter pos\n");
			scanf("%d",&pos);
			root=insert_at_pos(root,val,pos);
			break;
		case 5:
			if(root==NULL)
				printf("nothing to delete\n");
			else
			{
				root=delete_at_begin(root);
				printf("node is deleted at begin\n");
			}
				break;
		case 6:
			if(root==NULL)
				printf("nothing to delete\n");
			else
			{
				root=delete_at_end(root);
				printf("node is deleted at end\n");
				
			}
			break;
		case 7:
			printf("enter pos\n");
			scanf("%d",&pos);
			root=delete_at_pos(root,pos);
			break;
		case 8:
			display(root);
			break;
		case 9:
			exit(0);

		}

	}

}

