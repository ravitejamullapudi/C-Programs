/*given an array which has three values 0, 1, and 2, sort the array
	so that all 0's come first, followed by 1's and follwed by 2's.
	dont use general sorting algorithms...  */

#include<stdio.h>
#include<stdlib.h>
void bubble(int *,int );
void insert(int *,int);
void selection(int *,int);
int mergesort(int *,int,int);
void display(int *,int);

void main()
{
	int *arr,n,i;
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	{
	scanf("%d",arr+i);
	}
	bubble(arr,n);
	display(arr,n);
	insert(arr,n);
	display(arr,n);
	selection(arr,n);
	display(arr,n);
	mergesort(arr,0,n);
	display(arr,n);
	getch();

}
void display(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d",*(arr+i));

}

int mergesort(int *arr,int x,int n)
{
	int l;
	if(n==1)
		return *arr;
	else
	{
		l=(n+x)/2;
		mergesort(arr,x,l);
		mergesort(arr,l,n);
		merge(
	}


}

