#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct test
{
	int len;
	int input[20];
	int output[20];
}testDB[26]={
	{5,{0,0,0,0,0},{0,0}},
	{1,{-1},{-1,-1}},
	{2,{9999,-000001},{-1,9999}},
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
int * find_min_max1(int ip[],int l)
{
	int *input,i,opp[2],*op;
	op=opp;
	
	
	input=(int *)malloc(sizeof(int)*l);
	for(i=0;i<l;i++)
	{
		input[i]=ip[i];
	}
	op[0]=op[1]=input[0];
	for(i=1;i<l;i++)
	{
		if(op[0]>input[i])
			op[0]=input[i];
		if(op[1]<input[i])
			op[1]=input[i];
	}

	 return op;
}

void testcases()
{
	int i;
	int *res;
	for(i=0;i<25;i++)
	{
		res=find_min_max1(testDB[i].input,testDB[i].len);

	
	if(res[0]==testDB[i].output[0]&&res[1]==testDB[i].output[1])
		printf("passed \n");
	else printf("failed \n");
	}
}

main()
{
	testcases();
	getch();
}
