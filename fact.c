#include<stdio.h>
#include<stdio.h>
double fact(int n)
{
	if(n==1)
		return 1;
	else
		return fact(n-1)*n;
}
void main()
{
	double a;
	printf("enter number");
	scanf("%lf",&a);
	a=fact(a);
	printf("%lf",a);
	getch();
}