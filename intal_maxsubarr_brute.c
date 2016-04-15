#include<stdio.h>
#include<stdlib.h>

int bru_maxpro(int *,int);
main()
{
	int *arr,n,i,pro;
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	pro=bru_maxpro(arr,n);
	printf("%d",pro);
	getch();
}

int bru_maxpro(int *arr,int n)
{
	int i,j,temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((*(arr+j)-*(arr+i))>temp)
				temp=*(arr+j)-*(arr+i);
		}

	}
	return temp;

}
