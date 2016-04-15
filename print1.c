#include<stdio.h>
#include<stdlib.h>
void print_lines(int);
void print_values(int *,int);
void display(int *,int);

main()
{
	int *arr,i,n;
	printf("enter no of elements");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("enter correct value");
		
	}
	else{
	arr=(int *)malloc(sizeof(int)*n);
	printf("enter elements");

	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
		
	}
	printf("\n");
	display(arr,n);
	}

	getch();
}
void display(int *arr,int n)
{
	int i;
	print_lines(n);
	print_values(arr,n);
	print_lines(n);

}
void print_lines(int n)
{
	int i;
	for(i=0;i<4*n+1;i++)
		printf("-");
	printf("\n");
}

void print_values(int *arr,int n)
{
	int i;
	printf("|");
	for(i=0;i<n;i++)
		printf(" %d |",*(arr+i));
	printf("\n");

}
