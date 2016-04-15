#include<stdio.h>
int multiply_with_seven(int n)
{
	return ((n<<3)-n);

}
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

main()
{
	int n;
	printf("enter the element");
	n=read();
	printf("the 7*element is %d",multiply_with_seven(n));
	getch();
}
