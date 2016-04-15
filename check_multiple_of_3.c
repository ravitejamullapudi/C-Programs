#include<stdio.h>
int read()
{
	int val=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		val=val*10+c-'0';
		c=getchar();
	}
	return val;
}
int check_multiple_of_three(int n)
{
int odd=0,even=0,res;
if(n==0)
	return 1;
if(n==1)
	return 0;
while(n>0)
{
	if((n&1)==1)
		odd++;
	n=n>>1;
	if((n&1)==1)
		even++;
	n=n>>1;
}
if(odd>even)
	res= check_multiple_of_three(odd-even);
else
	res= check_multiple_of_three(even-odd);
return res;
}
void main()
{
	int n;
	int res;
	n=read();
	res=check_multiple_of_three(n);
	if(res==1)
		printf("the given number is a multiple of 3");
	else printf("the given number is not a multiple of 3");
	getch();
}
