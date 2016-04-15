#include<stdio.h> 
#include<stdlib.h>
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

int find_ele(int *arr, int p,int r,int k)
{
	int x,i,j;
	x=arr[r];
	i=p-1;
	if(k>r)
		return 777;
	for(j=p;j<r;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			swap(&arr[i],&arr[j]);

		}

	}
	if(i+1==k-1)
		return i+1;
	else if(i+1>k-1)
		return find_ele(arr,p,i,k);
	else
		return find_ele(arr,i+2,r,k-i-2);

}

main()
{
	int n, i, *arr,res;
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the elements");
	arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	printf("enter i value");
	scanf("%d",&i);
	res=find_ele(arr,0,n-1,i);
	if(res==777)
		printf("element not found ");
	else
		printf("%d",res);
	getch();
}
