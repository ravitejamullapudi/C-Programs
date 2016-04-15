#include<stdio.h>
#include<stdlib.h>
int * search_by_marks(struct student *,int,int,char []);
int strcmp1(char []);
struct student 
{
	int marks;
	char name[100];
};


main()
{
	int n,i,choice,marks1,*res; 
	char op[3];
	struct student *str;
	printf("enter no of students ");
	scanf("%d",&n);
	str=(struct student *)malloc(sizeof(struct student)*n);
	printf("enter student name and marks");
	for(i=0;i<n;i++)
	{
		scanf("%s%d",&(str->name),&(str->marks));
	}
	printf("Menu:\n 1.search by marks & operator \n2.search by name 3. search by star or end \n 4.search by marks or start or end \n 5.exit");
	while(1)
	{
		printf("enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("enter the marks");
			scanf("%d",&marks1);
			printf("enter the operator (eq,lt,gt)");
			scanf("%s",op);
			res=search_by_marks(str,n,marks1,op);
			break;
		case 2:
			;
		}

	}


	getch();

}

int * search(struct student *str,int n,int marks1,char op[])
{
	 
	int res,i,j=0,*count;
	count=(int *)malloc(20*sizeof( int *));
	res=strcmp1(op);
	if(res==0)
	{
		for(i=0;i<n;i++)
		{
			if((str->marks)==marks1)
			{
				*(count +j)=i;
				j++;
			}

		}
		*(count +j)=9999;
		return count;
	}
	else if(res==1)
	{

	}
	else if(res==2)
	{

	}
	else
	{
		printf("enter valid operator");
		return;
	}






}


int strcmp1(char op[])
{
	char op1[]="lt",op2[]="eq",op3[]="gt";
	int i=0;
	while(op[i]!='\0')
	{
	if(op[i]!=op1[i])
		i++;
	else 
		break;
	}
	if(i==2)
	{
		return 0;
	}
	i=0;
	while(op[i]!='\0')
	{
	if(op[i]!=op2[i])
		i++;
	else 
		break;
	}
	if(i==2)
	{
		return 1;
	}
	i=0;
	while(op[i]!='\0')
	{
	if(op[i]!=op2[i])
		i++;
	else 
		break;
	}
	if(i==2)
	{
		return 2;
	}
	return 4;
}
