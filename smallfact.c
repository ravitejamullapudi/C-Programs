/*
You are asked to calculate factorials of some small positive integers.
Input


An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.
Output


For each integer n given at input, display a line with the value of n!
Example

Sample input:
4
1
2
5
3
Sample output:
1
2
120
6
*/
#include<stdio.h>
int main()
{
	int a[200],i,n,temp,index,m,t,x,j;
	
	scanf("%d",&t);
	while(t--)
	{
		a[0]=1;
		m=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		index=0;
		temp=0;
		for(j=0;j<m;j++)
		{
		x=a[index]*i+temp;
		a[index]=x%10;
		temp=x/10;
		index++;
		}
		while(temp!=0)
		{
	
			x=temp;
			a[index]=x%10;
			temp=x/10;
			index++;
		}
		m=index;
	}
	for(i=m-1;i>=0;i--)
		printf("%d",a[i]);
	printf("\n");

	}
return 0;
}

