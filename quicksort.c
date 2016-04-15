#include<stdio.h>
#include<stdlib.h>

int partition(int *arr, int p, int r)
{
	int i=p-1,j,temp;
	int x=arr[r];
	for(j=p;j<r;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			
		}

	}
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	//printf("%d",arr[i+1]);
	return i+1;

}

void quicksort(int *arr, int p, int r)
{
	int q;
	if(p<r)
	{
		q=partition(arr,p,r);
		//if(q==r)
		//	q=(p+r)/2;
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);

	}
	//return ;
}

main()
{
	int *arr,i,len;
	printf("enter the length of the array");
	scanf("%d",&len);
	arr=(int *)malloc(sizeof(int)*len);
	for(i=0;i<len;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,len-1);
	for(i=0;i<len;i++)
		printf("%d",arr[i]);
	getch();
}
