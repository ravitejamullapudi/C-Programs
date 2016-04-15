#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct test
{
	int len;
	int input[20];
	int output[20];
}testDB[26]={
	{5,{0,0,0,0,0},{0}},
	{1,{-1},{-1}},
	{5,{1,987,-90,-8,98},{1,987,-90,-8,98}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}},
	{5,{0,0,0,0,0},{0,0}}
};
int * remove_adj_duplicates1(int ip[],int l)
{
	int *input,i,j=1;
	input=(int *)malloc(sizeof(int)*(l+1));
	for(i=0;i<l;i++)
	{
		input[i]=ip[i];
	}
	i=0;
	for(;j<l;j++)
	{
		if(input[i]!=input[j])
		{
			if(i+1!=j)
			{
				input[++i]=input[j];
			}

				
		}

	}
	
	input[i+1]=-123;
	return input;
}

void testcases()
{
	int i,j,k;
	int *res;
	for(i=0;i<25;i++)
	{
		res=remove_adj_duplicates1(testDB[i].input,testDB[i].len);
		j=0;
		k=0;
		while(res[j]!=-123)
		{
			if(res[j]!=testDB[i].output[j])
			{
				printf("failed\n");
				break;
			}
			j++;
		}
		if(res[j]==-123)
		{
			printf("passed\n");
		}


	 
	}
}

main()
{
	testcases();
	getch();
}
