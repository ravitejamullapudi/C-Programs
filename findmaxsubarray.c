#include<stdio.h>
#include<stdlib.h>

int * find_max_sub_arr(int *,int,int);
int * find_cross_sub_arr(int *,int,int,int);
main()
{
	int *res,*arr,n,low,high,i,j;
	printf("enter no of elements ");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	printf("enter the elements");
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	low=0;
	high=n-1;
	res=find_max_sub_arr(arr,low,high);
	for(i=*res;i<=*(res+1);i++)
		printf("%d\t",*(arr+i));

	getch();

}	

int * find_max_sub_arr(int *arr,int low,int high)
{
	int *res,*reslow,*reshigh,*rescross,mid;
	res=(int *)malloc(sizeof(int)*3);
	if(low==high)
	{
		*(res+0)=low;
		*(res+1)=high;
		*(res+2)=*(arr+low);
		return res;
	}

	else
	{
		mid=(low+high)/2;

		reslow=find_max_sub_arr(arr,low,mid);
		reshigh=find_max_sub_arr(arr,mid+1,high);
		rescross=find_cross_sub_arr(arr,low,mid,high);
		if(*(reslow+2)>=*(reshigh+2)&&*(reslow+2)>=*(rescross+2))
		{
			//*(reslow+0)=low;
			//*(reslow+1)=mid;

			return reslow;
		}
		else if(*(reshigh+2)>=*(reslow+2)&&*(reshigh+2)>=*(rescross+2))
		{
			//*(reshigh+0)=mid+1;
			//*(reshigh+1)=high;
			return reshigh;
		}
		else 
		{
			//*(rescross+0)=low;
			//*(rescross+1)=high;
				return rescross;
		}
			
	}
	
}
 int * find_cross_sub_arr(int *arr,int low,int mid,int high)
 {
	 int *rescross,sum=0,i;
	 int leftsum=-777,rightsum=-777;
	 rescross=(int *)malloc(sizeof(int)*3);
	 for(i=mid;i>=low;i--)
	 {
		 sum+=*(arr+i);
		 if(sum>leftsum)
		 {
			leftsum=sum;
			*(rescross+0)=i;
		 }

	 }
	 sum=0;
	 for(i=mid+1;i<=high;i++)
	 {
		sum+=*(arr+i);
		if(sum>rightsum)
		{
			rightsum=sum;
			*(rescross+1)=i;
		}

	 }

	 *(rescross+2)=leftsum+rightsum;
	 return rescross;
 }

