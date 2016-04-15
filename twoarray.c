/*
2. Given two arrays of size N each, write a function to create a two dimenasional array which
holds products of all elements of A1 and A2. example: A1: 1,2,3, A2: 1,2,3
output array is 3x3 array with values
1,2,3,
2,4,6,
3,6,9
*/
#include<stdio.h>
#include<stdlib.h>
int* twoarr(int *,int *,int *);
void display(int *,int *);

main()
{
	int n,*arr1,*arr2,i,*res;
	scanf("%d", &n);
	arr1=(int *)malloc(sizeof(int)*(n));
	arr2=(int *)malloc(sizeof(int)*(n));

	for(i=0;i<n;i++)
		scanf("%d",arr1+i);
	for(i=0;i<n;i++)
		scanf("%d",arr2+i);
	res=twoarr(&n,arr1,arr2);
	display(res,&n);
	getch();

}

int* twoarr(int *n,int *arr1,int *arr2)
{
	int i,j,*res;
	res=(int *)malloc((*n*(*n))*sizeof(int));
	for(i=0;i<*n;i++)
	{
		for(j=0;j<*n;j++)
		{
			*(res+i*(*n)+j)=*(arr1+i)*(*(arr2+j));
		}

	}


	return res;
}
void display(int *res,int *n)
{
	int i,j;
	for(i=0;i<*n;i++)
	{
		for(j=0;j<*n;j++)
		{
			printf("%d",*(res+i*(*n)+j));

		}
		printf("\n");
	}

}
