#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

int partition(int *arr, int p, int r)
{
	int x=arr[r];
	int i,j;
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}

	}
	swap(&arr[i+1],&arr[r]);
	return i+1;
}

int * quicksort(int *arr, int p, int r)
{
	int q;
	if(p<r)
	{
		q=partition(arr,p,r);
		arr=quicksort(arr,p,q-1);
		arr=quicksort(arr,q+1,r);
		

	}
	else
		return arr;
}
int mod_partition(int *arr,int p,int r)
{
	int x,i,j;
	x=arr[p];
	i=p-1;
	j=r+1;
	while(1)
	{
		do
		{
			j=j-1;
		}while(arr[j]>arr[x]);
		do
		{
			i=i+1;
		}while(arr[i]<arr[x]);
		if(i<j)
			swap(&arr[i],&arr[j]);
		else
			return j;
	}

}

int * mod_quicksort(int *arr, int p,int r)
{
	int q;
	if(p<r)
	{
		q=mod_partition(arr, p,r);
		arr=mod_quicksort(arr,p,q-1);
		arr=mod_quicksort(arr,q+1,r);
	}
	else
		return arr;
}

main()
{
	int *arr, n,i=0;
	printf("enter size of array\n");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int));
	printf("enter array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	arr=quicksort(arr,0,n-1);
	printf("the resultant array is \n");
	for(i=0;i<n;i++)
		printf("%3d",arr[i]);
	arr=mod_quicksort(arr,0,n-1);
	printf("\nthe modified quicksort is \n ");
	for(i=0;i<n;i++)
		printf("%3d",arr[i]);
	getch();
}
