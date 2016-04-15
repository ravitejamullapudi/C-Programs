#include<stdio.h>
#include<stdlib.h>

void testcases()
{
	int long long i,res,res1;
	for(i=123456;i<=987654;i++)
	{
		res=i;
		res1=res*2;
		sort(&res);
		sort(&res1);
		if(res!=res1)
			continue;

		
	}


}

main()
{
	testcases();
	getch();
}
