//merge sort
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void merge_sort(int *,int,int);
void merge(int *,int,int,int);
void main()
{
	int len,*str,i;
	printf("enter length of an array:");
	scanf("%d",&len);
	str=(int *)malloc(sizeof(int)*len);
	printf("enter elements of an arrray:");
	for(i=0;i<len;i++)
		scanf("%d",(str+i));
	merge_sort(str,0,len-1,len);
	printf("list after sorted is:\n");
	for(i=0;i<len;i++)
		printf("%d ",*(str+i));
	getch();
}

void merge_sort(int *str,int i,int j,int len)
{
	int mid;
	if(i>=j) return;
	mid=(i+j)/2;
	merge_sort(str,i,mid,len);
	merge_sort(str,mid+1,j,len);
	merge(str,i,j,len);
}

void merge(int *arr,int i,int j,int len)
{
	int mid,start,*copy_arr,k,m;
	copy_arr=(int *)malloc(sizeof(int)*len);
	start=i;
	mid=(i+j)/2;
	k=mid+1;
	m=i;
	while(i<=mid&&k<=j)
		if(*(arr+i)<=*(arr+k))
			*(copy_arr+m++)=*(arr+i++);
		else
			*(copy_arr+m++)=*(arr+k++);
	if(i>mid)
		for(;k<=j;)  *(copy_arr+m++)=*(arr+k++);
	else if(k>j)
		for(;i<=mid;)  *(copy_arr+m++)=*(arr+i++);
	for(i=start;i<=j;i++)
		*(arr+i)=*(copy_arr+i);
}
	

