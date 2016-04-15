#include<stdio.h>
#include<stdlib.h>
void quicksort(int *,int ,int);
int partition(int *,int,int);

main()
{
	int *arr,i,n,*res;
	printf("enter no of elements ");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	quicksort(arr,0,n-1);
	printf("the result is ");
	for(i=0;i<n;i++)
	{
		printf("%3d",*(arr+i));
	}
	getch();
}
int partition(int *arr,int p,int r)
{
	int pivot,i,j,x,t;
	x=*(arr+r);
	i=p-1;
	for(j=p;j<r-1;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
		}

	}
	t=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=t;
	return i+1;
}
void quicksort(int *arr,int p,int r)
{
	int pivot;
	if(p<r)
	{
		pivot=partition(arr,p,r);
		quicksort(arr,p,pivot-1);
		quicksort(arr,pivot+1,r);
	}
	
}
