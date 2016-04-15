#include<stdio.h>
#include<stdlib.h>
int * findname(struct student *,int ,int,int *,char *);

struct student
{
	int marks;
	char name[100];

}*std;


void main()
{
	int n,i,mrk,marks1;
	char op[3];
	int *ptr,*st;


	scanf("%d",&n);

	st=(int *)malloc(sizeof(int )*n);
	std=(struct student *)malloc(sizeof(struct student)*n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d",&((std+i)->name),&mrk);
	
		(std+i)->marks=mrk;
	}
	scanf("%d%s",&marks1,op);
	ptr=findname(std,n,marks1,st,op);
	i=0;
	while(*(ptr+i)!=99999)
	{
		printf("%s=%d\n",(std+ *(ptr+i))->name,(std+ *(ptr+i))->marks);
		i++;
	
	}
	//printf("%s=%d",(std+ ptr)->name,(std+ ptr)->marks);

	getch();
}

int *  findname(struct student *std,int n,int marks1,int *ptr,char op[])
{
	int i,j=0;
	if(op[0]=='l'&&op[1]=='t')
	{
	
	for(i=0;i<n;i++)
	{
		if((std+i)->marks<marks1)
		{
		*(ptr+j)=i;
		//printf("%d",*(ptr+j));
		j++;
			
		}

	}

	*(ptr+j)=99999;
	return ptr;
	}
	else if(op[0]=='e'&&op[1]=='q')
	{

		for(i=0;i<n;i++)
	{
		if((std+i)->marks==marks1)
		{
		*(ptr+j)=i;
		//printf("%d",*(ptr+j));
		j++;
			
		}

	}
		*(ptr+j)=99999;
		return ptr;

	}

	else if(op[0]=='g'&&op[1]=='t')
	{
		for(i=0;i<n;i++)
	{
		if((std+i)->marks>marks1)
		{
		*(ptr+j)=i;
		//printf("%d",*(ptr+j));
		j++;
			
		}

	}
		*(ptr+j)=99999;
		return ptr;

	}

}

