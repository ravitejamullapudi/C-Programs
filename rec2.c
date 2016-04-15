#include<stdio.h>
#include<stdlib.h>
#define ll long long int
struct test
{
	int input[20];
	int len;
	ll output;
}testDB[3]={{{1,1,2,3,4,4,5,5,6},9,31},
{{2,2,3,4,5,2,1},7,19},
{{3,6,-4,-5,-6},5,-6}};
ll num_cmp(ll n1,ll n2)
{
	if(n1==n2)
		return 0;
	return 1;
}
ll sum_array(int *arr,int i,int len)
{
	if(i==len)
	return 0;
	else
	{
		return arr[i]+sum_array(arr,i+1,len);
	}


}

void testcases()
{
	int i,check;
	ll res;
	for(i=0;i<3;i++)
	{
		res=sum_array(testDB[i].input,0,testDB[i].len);
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
