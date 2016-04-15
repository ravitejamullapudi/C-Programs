 /*
 given an array of size N, remove elements in the array from L to R(both inclusive).
 Elements to the right side of R shift left.
 example: input array 1,2,3,4,5,6,7 L=2 and R=4 output array is 1,2,6,7
 */

#include<stdio.h>
#include<stdlib.h>
void test(int *,int *,int ,int);
void rem(int *,int *,int ,int);
void display(int *,int );

int main()
{
	int l,r,i,*arr,n,val;
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		*(arr+i)=val;
	}
	scanf("%d%d",&l,&r);
	test(arr,&n,l,r);
	display(arr,n);
	return 0;
}
void dispaly(int *arr,int *n)
{
	int i;
	for(i=0;i<*n;i++)
	{
		printf("%3d",*(arr+i));
	}

}


void test(int *arr,int *n,int l, int r)
{
	if(l>r)
	{
		l=l+r;
		r=l-r;
		l=l-r;

	}


	if(l<0&&r<0)
		return;
	if(l>*n&&r>*n)
		return;
	if(l<=0&&r>=0&&r<*n)
	{
		rem(arr,n,0,r);
	return;
	}
	if(l>0&&r>=*n)
	{
		rem(arr,n,l,*n-1);
		return;
	}
	rem(arr,n,l,r);
	return;
}

void rem(int *arr,int *n,int l,int r)
{
	int i;
	for(i=r+1;i<*n;i++)
	{
		*(arr+l++)=*(arr+i);

	}
	*n=*n-r+l+1;
	

	arr=(int *)realloc(arr,*n*sizeof(int));
	return;
}
