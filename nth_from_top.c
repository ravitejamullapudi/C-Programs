#include<stdio.h>
#include<stdlib.h>

struct test
{
	int len;
	int input[20];
	int n;
	int op;
}testDB[6]={{5,{1,2,3,4,5},3,3},
{5,{4,4,4,4,4},2,4},
{5,{4,4,4,4,4},0,1111},
{2,{1,2},3,1111},
{1,{2},1,2},
{1,{3},2,1111}};

int nth_from_top(int ip[],int l,int n)
{
	int *input,i;
	input=(int *)malloc(sizeof(int)*l);
	for(i=0;i<l;i++)
		input[i]=ip[i];
	if(n>0&&n<=l)
		return input[l-n];
	else
		return 1111;
}
int check_res(int res,int op)
{
	if(op==res)
		return 1;
	else return 0;
}

void testcases()
{
	int i, res,check;
	for(i=0;i<6;i++)
	{
		res=nth_from_top(testDB[i].input,testDB[i].len,testDB[i].n);
		check=check_res(res,testDB[i].op);
		if(check==1)
			printf("passed\n");
		else printf("failed\n");
	}
}
	



main()
{
	testcases();
	getch();

}

