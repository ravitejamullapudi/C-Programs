#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int * findname(struct student *,int ,char *,int *);

struct student
{
	int marks;
	char name[100];

}*std;


void main()
{
	int n,i,mrk,marks1;
	char op[100];
	int *ptr,*st;


	scanf("%d",&n);

	st=(int *)malloc(sizeof(int )*n);
	std=(struct student *)malloc(sizeof(struct student)*n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d",&((std+i)->name),&mrk);
	
		(std+i)->marks=mrk;
	}
	scanf("%s",op);
	ptr=findname(std,n,op,st);
	i=0;
	while(*(ptr+i)!=99999)
	{
		printf("%d\n",(std+ *(ptr+i))->marks);
		i++;
	
	}
	//printf("%s",(std+ ptr)->name,(std+ ptr)->marks);

	getch();
}

int *  findname(struct student *std,int n,char *op,int *ptr)
{
	int i,j=0;
	
	for(i=0;i<n;i++)
	{
	
		if(strcmp((std+i)->name,op)==0)
		{
		*(ptr+j)=i;
		//printf("%d",*(ptr+j));
		j++;
			
		}

	}

	*(ptr+j)=99999;
	return ptr;
}

