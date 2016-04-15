/*
Given a natural number n (1 <= n <= 500000), please output the summation of all its proper divisors.

Definition: A proper divisor of a natural number is the divisor that is strictly less than the number.

e.g. number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.

 

Input

An integer stating the number of test cases (equal to about 200000), and that many lines follow,
each containing one integer between 1 and 500000 inclusive.

Output

One integer each line: the divisor summation of the integer given respectively.

Example

Sample Input:
3
2
10
20

Sample Output:
1
8
22

*/

#include<stdio.h>
unsigned long int summ(unsigned long int);
int main()
{
	unsigned long int test,num,i,res;
	scanf("%ld",&test);
	for(i=0;i<test;i++)
	{
		scanf("%ld",&num);
		res=summ(num);
		printf("%ld",res);
		
	}
	return 0;


}
unsigned long int summ(unsigned long int num)
{
	unsigned long int t=num/2+1,sum=0,i,temp;
	for(i=1;i*i<=num;i++)
	{
		if(num%i==0)
		{sum+=i;
		}
		if(num%(t-i*i)==0)
		{sum+=t-i*i;
		}
	}
	return sum;
}


	
	
