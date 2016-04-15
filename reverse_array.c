#include<stdio.h>
#include<stdlib.h>

struct test
{
	int len;
	int input[20];
	int output[20];

}testDB[7]={{5,{1,2,3,4,5},{5,4,3,2,1}},
{1,{1},{1}},
{2,{-2,3},{3,-2}},
{4,{1,1,1,1},{1,1,1,1}},
{5,{-4,8,-4,8,-4},{-4,8,-4,8,-4}},
{4,{0,0,0,0},{0,0,0,0}},
{4,{1,2*3,4*5,2+4},{6,20,6,1}}};
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}

int * reverse_array_1(int ip[],int l)
{
	int *input,i,end;
	input=(int *)malloc(sizeof(int)*l);
	for(i=0;i<l;i++)
		input[i]=ip[i];
	end=l-1;
	for(i=0;i<l/2;i++)
	{
		if(input[i]!=input[end])
			swap(&input[i],&input[end]);
		end--;
	}
	return input;
}
int check_op(int arr1[],int arr2[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(arr1[i]!=arr2[i])
			return 0;
	}
	return 1;
}

void testcases()
{
	int i,val;
	int *res;
	for(i=0;i<7;i++)
	{
		res=reverse_array_1(testDB[i].input,testDB[i].len);
		val=check_op(res,testDB[i].output,testDB[i].len);
		if(val==1)
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

