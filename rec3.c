#include<stdio.h>
#include<stdlib.h>
#define ll long long int
struct test
{
	int input[20];
	int len;
	int key;
	ll output;
}testDB[4]={{{1,1,2,3,4,4,5,5,6},9,3,1},
{{2,2,3,4,5,2,1},7,1,1},
{{3,6,-4,-5,-6},5,-6,1},
{{3,6,-4,-5,-6},5,-3,0}};
ll num_cmp(ll n1,ll n2)
{
	if(n1==n2)
		return 0;
	return 1;
}
 int find_ele(int *arr,int len, int key,int i)
 {
	 if(i==len)return 0;
	 if(arr[i]==key)
		 return 1;
	 else 
		 return find_ele(arr,len,key,i+1);
 }

void testcases()
{
	int i,check;
	ll res;
	for(i=0;i<3;i++)
	{

		res=find_ele(testDB[i].input,testDB[i].len,testDB[i].key,0);
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
