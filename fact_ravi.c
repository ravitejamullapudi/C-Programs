#include<stdio.h>
int main()
{
	unsigned long int t,n;
	int count;
	scanf("%lu",&t);
	while(t--)
	{
		count=0;
		scanf("%lu",&n);
		while(n!=0){
		n=n/5;
		count+=n;
		}
	
	printf("%d\n",count);
	}
	return 0;
}