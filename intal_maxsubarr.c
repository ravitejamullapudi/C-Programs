#include<stdio.h>
#include<stdlib.h>

int maxpro(int *,int);
main()
{
	int *arr,n,i,pro;
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	pro=maxpro(arr,n);
	printf("%d",pro);
	getch();
}

 int maxpro(int *arr,int n)
 {
	 int temp,i,j;
	 for(i=0;i<n-1;i++)
	 {
		*(arr+i)=*(arr+i+1)-*(arr+i);
	 }
	 temp=*(arr+0);
	 for(i=0;i<n-2;i++)
	 {
		 for(j=i+1;j<n-1;j++)
		 {
			if(temp<temp
		 }

	 }

 }
