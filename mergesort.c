#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int l,int mid,int h)
{
	int n1,n2,i,j,k,*arr1,*arr2;
	n1=mid-l+1;
	n2=h-mid;
	arr1=(int *)malloc(sizeof(int)*n1);
	arr2=(int *)malloc(sizeof(int)*n2);
	for(i=0;i<n1;i++)
		arr1[i]=arr[i+l];
	for(i=0;i<n2;i++)
		arr2[i]=arr[i+mid+1];
	i=0;j=0;k=l;
	while(i<n1&&j<n2)
	{
		if(arr1[i]<arr2[j])
		{
			arr[k]=arr1[i];
			i++;
		}
		else
		{
			arr[k]=arr2[j];
			j++;
		}
		k++;
	}
		while(j<n2)
		{
			arr[k]=arr2[j];
			j++;
			k++;
		}
		while(i<n1)
		{
			arr[k]=arr1[i];
			i++;
			k++;
		}

		//free(arr1);
		//free(arr2);
	
		
}
void mergesort(int *arr,int l,int h)
{
	int mid;

	if(l<h)
	{
		mid=(l+h)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,h);
		merge(arr,l,mid,h);
	}

}



main()
{
	int *arr,i,n;
	printf("enter n value ");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	printf("enter elements ");
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	mergesort(arr,0,n-1);
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
	getch();
}
