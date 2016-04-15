#include<stdio.h>

float atm(int ,float);
int main()
{
	int withdraw;
	float initial;
	scanf("%d%f",&withdraw,&initial);
	printf("%.2f",atm(withdraw,initial));
	return 0;
}
float atm(int withdraw, float initial)
{
	if((initial>=withdraw+0.5)&& withdraw%5==0)
		return (initial-withdraw-0.5);
	else 
		return initial;
}