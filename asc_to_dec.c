//4. given an array of size N, allocate, read values in ascending order. 
//(given input array in ascending order). write a function to make the array into descending order

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void to_dec(int ,int *);
main()
{
	int len,i,*arr;
	printf("enter the length of the array");
	scanf("%d",&len);
	arr=(int *)malloc(len*sizeof(int));
	printf("enter the elements in ascending order");
	for(i=0;i<len;i++)
	{
		scanf("%d",arr+i);
	}
	to_dec(len,arr);
	printf("the array in decreasing order is ");
	for(i=0;i<len;i++)
	{
		printf("%d",*(arr+i));
	}
	getch();
}
void to_dec(int len,int *arr)
{
	int i,len2;
	len2=len;
	for(i=0;i<len2/2;i++)
	{
		*(arr+i)+=*(arr+len-1);
		*(arr+len-1)=*(arr+i)-*(arr+len-1);
		*(arr+i)=*(arr+i)-*(arr+len-1);
		len--;
	}
}
