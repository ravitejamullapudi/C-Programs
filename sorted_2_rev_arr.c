#include<stdio.h>
#include<stdlib.h>
struct test
{
	int input[30];
	int len;
	int output[30];
}testDB[15]={{{1,4,3,2,5,8,7,6,9},9,{1,2,3,4,5,6,7,8,9}},
{{1,2,6,4,5,3,7,8},8,{1,2,3,4,5,6,7,8}},
{{1,4,5,2,3,6,7,8},8,{1,2,3,4,5,6,7,8}},
{{1,2,6,3,4,5,7,8},8,{1,2,3,4,5,6,7,8}},
{{1,4,2,3,5,6,7,8},8,{1,2,3,4,5,6,7,8}},
{{1,2,4,6,5,3,7,8},8,{1,2,3,4,5,6,7,8}},
{{1,6,5,3,4,2,7,8},8,{1,2,3,4,5,6,7,8}},
	{{1,4,6,5,2,3,7,8},8,{1,2,3,4,5,6,7,8}},
{{1,6,5,3,4,2,7},7,{1,2,3,4,5,6,7}},
{{1,6,4,5,3,2,7},7,{1,2,3,4,5,6,7}},
	{{1,5,3,4,2,6,7},7,{1,2,3,4,5,6,7}},
{{1,2,5,4,3,6,9,8,7,10,11,12},12,{1,2,3,4,5,6,7,8,9,10,11,12}},
{{1,2},2,{1,2}},
{{1,2,5,4,3,6},6,{1,2,5,4,3,6}},
{{1,5,4,8,7,6,2,3,9,10,},10,{1,2,3,4,5,6,7,8,9,10}}};
int * swap(int *arr,int i,int j)
{
	int t;
	t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;
	return arr;
}

int * rev_arr(int *arr,int i,int j)
{
	int k=(i+j)/2,iter;
	for(iter=i;iter<=k;iter++)
	{
		arr=swap(arr,iter,j);
		j--;
	}

	return arr;
}
int find_first_index(int *arr,int index,int len)
{
	int i;
	for(i=index+1;i<len;i++)
	{
		if(arr[i-1]>arr[i])
		return i-1;
	}
	return -1;
}
int find_last_index(int *arr,int index,int len)
{
	int i;
	for(i=index+1;i<len;i++)
	{
		if(arr[i]>arr[i-1])
			return i-1;
	}
	return i;
}
void swap1(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}
int find_min(int *arr,int *index11,int *index12)
{
	int i,temp=777,j;
	for(i=*index11-1;i>=0;i--)
	{
		if(arr[i]<temp&&arr[i]<arr[*index11]&&arr[i]>=arr[*index12])
		{
		temp=arr[i];
		j=i;
		}
	}
	if(temp!=777)
		return j;
	return temp;
}
int find_max(int *arr,int *index11,int *index12,int n)
{
	int i,temp=-777,j;
	for(i=*index12+1;i<n;i++)
	{
		if(arr[i]>temp&&arr[i]<arr[*index11]&&arr[i]>=arr[*index12])
		{
			temp=arr[i];
			j=i;
		}
	}
	if(temp!=-777)
		return j;
	return temp;
}

void indexcheck(int *arr, int *index11,int *index12,int *index21,int *index22,int n)
{
	int min,max,t;
	if(arr[*index11]>arr[*index21])
	{
		swap1(index12,index22);
		swap1(index21,index22);
		t=*index11;
		*index11=*index21;
		*index21=t;
		t=*index12;
		*index12=*index22;
		*index22=t;
	}

	else
	{
		min=find_min(arr,index11,index12);
		max=find_max(arr,index11,index12,n);
		if(min==777)
		{
			*index22=max;
		}
		else
			*index11=min;
		
		
	}

}



int  find_inclusive(int *arr,int *index11,int *index12,int *index21,int *index22,int n)
{
	int min,max,temp;
	min=find_min(arr,index11,index12);
	max=find_max(arr,index11,index12,n);
	if(min!=777&&max!=-777)
	{
		if(arr[min]>arr[max])
		{
			temp=*index12;
			*index12=max;
			*index21=min;
			*index22=*index11+max-temp;
		}


	}
	else if(min==777&&max==-777)
	{
		return 1;
	}
	else if(min==777)
	{
		temp=*index12;
		*index12=max;
		*index21=*index11;
		*index22=max-temp+*index11;
	}
	else
	{
		*index21=min;
		*index22=*index11;
	}

	return 0;

}

int * two_rev_sort_arr(int *arr,int n)
{
	int i=0,check,index11=-1,index12=-1,index21=-1,index22=-1,index31=-1;

		index11=find_first_index(arr,1,n);
		if(index11==-1)
			return arr;
		index12=find_last_index(arr,index11,n);
		if(index12==n)
			return arr;
		index21=find_first_index(arr,index12,n);
		if(index21==-1)
		{
		check=find_inclusive(arr,&index11,&index12,&index21,&index22,n);
		if(check==1)
			return arr;
		}
		else
		{
		index22=find_last_index(arr,index21,n);
		if(index22==n)
			index22=n-1;
		index31=find_first_index(arr,index22,n);
		if(index31!=-1)
			return arr;
		indexcheck(arr,&index11,&index12,&index21,&index22,n);
		}
		arr=rev_arr(arr,index11,index12);
		arr=rev_arr(arr,index21,index22);
		return arr;
	}
int *malloc_int(int ip[],int len)
{
	int i,*arr;
	arr=(int *)malloc(sizeof(int)*len);
	for(i=0;i<len;i++)
		arr[i]=ip[i];
	return arr;
}
int arr_cmp(int *arr1,int *arr2,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(arr1[i]!=arr2[i])
			return 1;
	}
	return 0;
}

void testcases()
{
	int *arr,i,*op,check;
	for(i=0;i<15;i++)
	{
		arr=malloc_int(testDB[i].input,testDB[i].len);
		arr=two_rev_sort_arr(arr,testDB[i].len);
		op=malloc_int(testDB[i].output,testDB[i].len);
		
		check=arr_cmp(arr,op,testDB[i].len);
		if(check==0)
		
			printf("passed\n");

		else 
			printf("failed\n");

	}


}

main()
{
	
	testcases();
	getch();
}
