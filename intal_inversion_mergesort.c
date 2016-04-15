#include<stdio.h>
#include<stdlib.h>

void mergesort(int *,int,int);
int* merge(int *,int,int,int);
void main()
{
	int n,i;
	int *str;
	scanf("%d",&n);
	str=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",str+i);
	}
	mergesort(str,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",*(str+i));

	}
	getch();

	
}

void mergesort(int *str,int low,int high)
{
	int mid,*res;
	if(low>=high)
		return;

		
	else
	{
		mid=(low+high)/2;
		mergesort(str,low,mid);
		mergesort(str,mid+1,high);
		res=merge(str,low,mid,high);
	}
	
}
