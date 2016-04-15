#include<stdio.h>
#include<stdlib.h>
#define ll long long int
struct test
{
	ll input;
	ll output;
}testDB[5]={{1,1},
{2,2},
{3,6},
{5,120},
{-6,0}};
ll fact(ll n)
{
	if(n<0)
		return 0;
	if(n==0||n==1)
		return 1;
	else 
		return n*fact(n-1);
}
ll num_cmp(ll n1,ll n2)
{
	if(n1==n2)
		return 0;
	return 1;
}

void testcases()
{
	int i,check;
	ll res;
	for(i=0;i<5;i++)
	{
		res=fact(testDB[i].input);
		check=num_cmp(res,testDB[i].output);
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
