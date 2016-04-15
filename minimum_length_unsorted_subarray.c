/*
Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] 
such that sorting this subarray makes the whole array sorted.

Examples:
1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], 
 your program should be able to find that the subarray lies between the indexes 3 and 8.

2) If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], 
 your program should be able to find that the subarray lies between the indexes 2 and 5.
*/

#include<stdio.h>
#include<stdlib.h>

int read()
{
	int val=0;
	char c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	{
		val=val*10+c-'0';
		c=getchar();
	}
	return val;
}
int *get_index_position(int *arr,int n)
{
	int i,s,e,max,min,*res;
	res=(int *)malloc(sizeof(int )*2);
	for(i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			s=i;
			break;

		}

	}
	for(i=n-1;i>0;i--)
	{
		if(arr[i]<arr[i-1])
		{
			e=i;
			break;
		}

	}
	min=max=arr[s];
	for(i=s;i<=e;i++)
	{
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	//printf("%d%d",min,max);
	for(i=0;i<s;i++)
	{
		if(arr[i]>min)
		{
			s=i;
			break;
		}
	}
	for(i=n-1;i>e;i--)
	{
		if(arr[i]<max)
		{
			e=i;
			break;
		}

	}
	//printf("%d%d",s,e);
	 res[0]=s;
	 res[1]=e;
	 return res;
}

void main()
{
	int n,*arr,i,*res;
	printf("enter the elements ");
	n=read();
	arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		*(arr+i)=read();
	res=get_index_position(arr,n);
	printf("%3d%3d",res[0],res[1]);
	getch();
}
