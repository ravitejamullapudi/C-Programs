#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int lx,ly,rx,ry;
	struct node *next;
};
struct test 
{
	int build_no;
	int input[30];
	int output[30];
}testDB[3]={{2,{1,4,3,4,5,4,7,4},{1,4,3,4,3,0,5,0,5,4,7,4}},
{2,{1,4,3,4,2,6,4,6},{1,4,2,4,2,6,4,6}},
{3,{1,8,8,8,2,4,4,4,3,6,8,6},{1,8,8,8}}};

int * malloc_arr(int build_no,int ip[])
{
	int *arr;
	int i;
	arr=(int *)malloc(sizeof(int)*build_no*4);
	for(i=0;i<build_no*4;i++)
	{
		arr[i]=ip[i];
	}
	return arr;
}
int op_cmp(struct node *root,int op[])
{
	int i=0;
	struct node *ptr=root;
	while(ptr)
	{
		if(ptr->lx!=op[i++])
			return 1;
		if(ptr->ly!=op[i++])
			return 1;
		if(ptr->rx!=op[i++])
			return 1;
		if(ptr->ry!=op[i++])
			return 1;
		ptr=ptr->next;

	}
	return 0;
}
int * find_min(int *arr,int build_no,int *min)
{
	int i,j;
	if(*min!=777)
	{
		arr[*min]=777;
		*min=777;
	}
	for(i=0;i<build_no;i++)
	{
		if(arr[i*4]<*min)
		{
			*min=arr[i*4];
			j=i*4;

		}

	}
	*min=j;
	return arr;
}
struct node * getNode()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	return temp;
}

struct node * insert(int lx,int ly,int rx,int ry)
{
	struct node *ptr;
	ptr=getNode();
	ptr->lx=lx;
	ptr->ly=ly;
	ptr->rx=rx;
	ptr->ry=ry;
	
	return ptr;
}
struct node * search(struct node *root,int *res,int min)
{
	while(root)
	{
		if(root->lx==res[min])
			return root;
		if(root->next==NULL)
			return root;
		root=root->next;
	}

}

struct node * insert_list(struct node *root,int *res,int min,int build_no)
{
	struct node *ptr=root,*insert1,*insert2;
	if(ptr==NULL)
	{
		root=insert(res[min],res[min+1],res[min+2],res[min+3]);
		return root;
	}
	else
	{
		ptr=search(root,res,min);
		if(ptr->lx==res[min])
		{
			if(ptr->ly<res[min+1])
			{
				//ptr->ly=res[min+1];
				if(ptr->rx<=res[min+2])
				{
					ptr->ly=res[min+1];
					ptr->rx=res[min+2];
					ptr->ry=res[min+3];
					return root;
				}
				else
				{
					insert1=insert(res[min+2],ptr->ly,ptr->rx,ptr->ry);
					ptr->ly=res[min+1];
					ptr->ry=res[min+1];
					ptr->rx=res[min+2];

					ptr->next=insert1;
					return root;

				}


			}
		

		}
		else 
		{
			if(ptr->rx>res[min])
			{
				if(ptr->rx==res[min+2])
				{
					if(ptr->ly>=res[min+1])
					return root;
					else
					{
						insert1=insert(res[min],res[min+1],res[min+2],res[min+3]);
						ptr->rx=res[min];
						ptr->next=insert1;
						return root;
					}

				}
			
				else
				{
					if(ptr->ly>res[min+1])
					{
						insert1=insert(ptr->rx,ptr->ly,res[min+2],res[min+3]);
						ptr->next=insert1;
						return root;
					}
					else
					{
						if(ptr->rx>res[min+2])
						{
							insert1=insert(res[min],res[min+1],res[min+2],res[min+3]);
							insert2=insert(res[min+2],ptr->ly,ptr->rx,ptr->ry);
							insert1->next=insert2;
							ptr->rx=res[min];
							ptr->next=insert1;
							return root;
						}
						else
						{
							insert1=insert(res[min],res[min+1],res[min+2],res[min+3]);
							ptr->rx=res[min];
							ptr->next=insert1;
							return root;
						}

					}

				}

			}


		}



	}



}


struct node * sky_building(int *res,int build_no)
{
	int i,min=777;
	struct node *root=NULL;
	for(i=0;i<build_no;i++)
	{
	res=find_min(res,build_no,&min);
	root=insert_list(root,res,min,build_no);

	}
	return root;
}

void testcases()
{
	int i,*res,check;
	struct node *root=NULL;
	for(i=0;i<3;i++)
	{
		res=malloc_arr(testDB[i].build_no,testDB[i].input);
		root=sky_building(res,testDB[i].build_no);
		check=op_cmp(root,testDB[i].output);
		if(check==0)
			printf("passed\n");
		else 
			printf("failde\n");
	}

}

void main()
{
	testcases();
	getch();
}


