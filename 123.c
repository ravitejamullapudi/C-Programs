#include<stdio.h>
#include<stdlib.h>

struct test
{
	int input[20];
	int len;
	int output[20];
}testDB[10]={{{3,2,1},3,{1,2,3}},
{{1,2,3,1,2,3},6,{1,1,2,2,3,3}},
	{{1,2,3,1,2,3,1,2,3},9,{1,1,1,2,2,2,3,3,3}},
	{{1,1,1},3,{1,1,1}},
	
	{{3,3,3,1,2,3,3,3,3,3,3},11,{1,2,3,3,3,3,3,3,3,3,3}},
	{{1,2,3},3,{1,2,3}},
	{{1,2,3},3,{1,2,3}},
	{{1,2,3},3,{1,2,3}},
	{{1,2,3},3,{1,2,3}},
{{1,2,3},3,{1,2,3}}};
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
int * swap(int *arr,int i,int j)
{
	int t;
	t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;
	return arr;
}
int move_one(int *arr,int one,int len)
{
	while(one<len)
	{
		if(arr[one]!=1)
			return one;
		one++;
	}
	return one;
}
int move_three(int *arr,int three,int len)
{
	while(three>=0)
	{
		if(arr[three]!=3)
			return three;
		three--;
	}
	return three;
}


int * sort_123(int *arr,int len)
{
	int one=0,two=0,three=len-1;
	 one=move_one(arr,one,len);
	 two=one;
	 three=move_three(arr,three,len);
	 while(two<=three&&two<len)
	 {
		 if(arr[two]==3)
		 {
			 arr=swap(arr,two,three);
			 three=move_three(arr,three,len);

		 }
		 else if(arr[two]==1)
		 {
			 arr=swap(arr,two,one);
			 one=move_one(arr,one,len);
			 two=one;
			 
		 }
		 else 
		 {
			 two++;
		 }

	 }

	 return arr;
	 

}

/*int * sort_123(int *arr, int len)
{
	int ptr_one=0,ptr_three=len-1,ptr=0;
	while(ptr<=ptr_three)
	{
		if(arr[ptr_one]==1)
			ptr_one++;
		if(arr[ptr]==3)
		{
			while(ptr<=ptr_three)
			{
				if(arr[ptr_three]!=3)
				{
					arr=swap(arr,ptr,ptr_three);
					ptr++;
					break;
				}
				else
					ptr_three--;
			}

		}
		else if(arr[ptr]==1)
		{
			if(arr[ptr_one]==1)
				ptr_one++;
			else
			{
				
				arr=swap(arr,ptr,ptr_one);
				ptr_one++;
				break;
			}
		}

		else
		{
			ptr++;
		}

		


	}

}*/

void testcases()
{
	int i,*arr,*op,check;
	for(i=0;i<10;i++)
	{
		arr=malloc_int(testDB[i].input,testDB[i].len);
		arr=sort_123(arr,testDB[i].len);
		op=malloc_int(testDB[i].output,testDB[i].len);
		check=arr_cmp(arr,op,testDB[i].len);
		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(arr);
		free(op);
	}

}


main()
{
	testcases();
	getch();
}

