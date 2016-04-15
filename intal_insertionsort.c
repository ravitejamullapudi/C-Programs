//program for insertion sort

#include<stdio.h>
#include<stdlib.h>

void insertion(int *,int);

void main()
{
	int *arr,n,i;
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	insertion(arr,n);
	for(i=0;i<n;i++)
		printf("%d",*(arr+i));
	getch();
}

void insertion(int *arr,int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=*(arr+i);
		j=i-1;
		while(j>=0&&key<*(arr+j))
		{
			*(arr+j+1)=*(arr+j);
			j--;

		}
		*(arr+j+1)=key;


	}

}
