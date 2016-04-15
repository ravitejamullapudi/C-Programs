//2. allocate two interger arrays and pass to a function and add the values of the arrays. 
//sizes of both arrays are same. c[i] = a[i] + b[i];. a and b should be allocated by size.
//read and C computed in a function, not in main

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int * add_array(int,int*,int*);
main()
{
	int len,*arr1,*arr2,*add_arr,i;

	printf("enter the size of the 2 arrays");
	scanf("%d",&len);
	arr1=(int *)malloc(len*sizeof(int));
	arr2=(int *)malloc(len*sizeof(int));
	printf("enter 1st array elements");
	for(i=0;i<len;i++)
	{
		scanf("%d",arr1+i);
	}
	printf("enter 2nd array elements");
	for(i=0;i<len;i++)
	{
		scanf("%d",arr2+i);
	}

	add_arr=add_array(len,arr1,arr2);
	printf("the resultant array is ");
	for(i=0;i<len;i++)
	{
		printf("%3d",*(add_arr+i));
	}
	getch();

}
int * add_array(int len,int *arr1,int *arr2)
{
	int i,*res;
	res=(int *)malloc(len*sizeof(int));
	for(i=0;i<len;i++)
	{
		*(res+i)=*(arr1+i)+*(arr2+i);
	}
	return res;
}