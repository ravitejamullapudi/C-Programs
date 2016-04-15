#include<stdio.h>
#include<stdlib.h>
int max_ele(int *arr,int n)
{
	int max=arr[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(max<arr[i])
			max=arr[i];
	}
	return max;
}
int * initialise(int *arr, int len, int val)
{
	int i;
	for(i=0;i<len;i++)
		arr[i]=val;
	return arr;
}
void display(int *arr,int len)
{
	int i=0;
	for(i=0;i<len;i++)
		printf("%3d",arr[i]);
	printf("\n");
}

int * counting_sort(int *arr,int n,int max)
{
	int i, *c,*b;
	c=(int *)malloc(sizeof(int)*(max+1));
	b=(int *)malloc(sizeof(int)*n);
	c=initialise(c,max+1,0);
	for(i=0;i<n;i++)
		c[arr[i]]=c[arr[i]]+1;
//	display(c,max+1);
	for(i=1;i<max+1;i++)
		c[i]=c[i]+c[i-1];
//	display(c,max+1);
	for(i=n-1;i>=0;i--)
	{
		b[c[arr[i]]-1]=arr[i];
		c[arr[i]]=c[arr[i]]-1;
	}
//	display(c,max+1);
//	display(b,n);
	return b;
	free(c);

}

main()
{
	int *arr, n,i,*res,max;
	printf("enter num of elements\n");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	max=max_ele(arr,n);
	res=counting_sort(arr,n,max);
	printf("the elements in sorted order are\n");
	for(i=0;i<n;i++)
		printf("%3d",res[i]);
	getch();
}