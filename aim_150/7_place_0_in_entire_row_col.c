#include<stdio.h>
#include<stdlib.h>
int ** place_zero(int **a,int n,int i,int j)
{
	int k=0;
	a[i][j]=0;
	for(k=0;k<n;k++)
	{
		if(a[k][j]!=777)
			a[k][j]=0;
	}
	for(k=0;k<n;k++)
	{
		if(a[i][k]!=777)
			a[i][k]=0;
	}
	return a;
}

int ** place_zero_row_col(int **arr,int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]==0)
				arr[i][j]=777;
		}

	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]==777)
				arr=place_zero(arr,n,i,j);
		}

	}

	return arr;
}

main()
{
	int n,i,j;
	int **arr;
	printf("enter the size of the n*n matrix\n");
	scanf("%d",&n);
	arr=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		arr[i]=(int *)malloc(sizeof(int)*n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}

	}
	arr=place_zero_row_col(arr,n);
	printf("the elements are \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
	getch();
}