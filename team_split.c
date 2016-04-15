﻿/*

Chef wants to split a team of new chef into two teams to play a game. In order to make the split, 
he first designates two team captains who take alternate turns selecting players for their teams.
During each turn, the captain selects a single player for his team. Since each captain wants to make
the strongest possible team, he will always select the best available player. The players have strengths 
as integer number, where higher strength indicate better players. After all the players have been selected,
the team strength is computed as the sum of the strengths of the players on that team.
For example, if strengths of 5 players are 5,7,8,4 and 2, then the first captain selects the player with strength 8
for his team, the second captain gets the player with strength 7, the first gets the one with strength 5, the second 
the one with strength 4, and the last one (strength 2) goes to the first team. The first team now has a total strength 
8+5+2=15, and the second team has strength 7+4=11.
Now Chef wants to find the absolute strength difference between the two teams. For the example above the answer is 4(=|15-11|).
But Chef does not know exact strengths of each player. He knows some parameter a, b, c and d and a formula to find 
the strength of each player. The formula is 

S0 = d,

Si = (a * Si-12 + b * Si-1 + c) mod 1000000, for i = 1 to N - 1
There are N players numbering 0 to N-1 and Si is the strength of player i.
Input

First line of the input contains an integer T, number of test cases to follow. Each test consist of single line containing five integers N, a, b, c and d.
Output

For each test case, you have to print a single line containing the absolute strength difference between the two teams.
Constraints

1 ≤ T ≤ 50
1 ≤ N ≤ 3000000
0 ≤ a, b, c, d ≤ 100
Example

Input:
4
1 1 1 1 1
2 1 1 1 1
3 1 2 3 4
4 2 3 4 1

Output:
1
2
763
74896   */

#include<stdio.h>
#include<stdlib.h>
int main()
{
	long int n,i,j,temp,sum;
	int t,a,b,c,d,*arr;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		i=1;
		scanf("%ld%d%d%d%d",&n,&a,&b,&c,&d);
		arr=(int *)malloc(sizeof(int)*n);
		*arr=d;
		while(i<n)
		{
			*(arr+i)=(a**(arr+i-1)**(arr+i-1)+b**(arr+i-1)+c)%1000000;
			i++;
		}
	//	for(i=0;i<n;i++)
		//	printf("%d\t",*(arr+i));
		 for(i=0;i<n;i++)
		 {
			 for(j=0;j<n-1;j++)
			 {
				 if(*(arr+j)<*(arr+j+1))
				 {
					 temp=*(arr+j);
					 *(arr+j)=*(arr+j+1);
					 *(arr+j+1)=temp;
				 }

			 }

		 }
		 for(i=0;i<n;i++)
		 {
			 if(i%2==0)
			 {
				 sum+=*(arr+i);
			 }
			 else
				 sum-=*(arr+i);
		 }
		 free(arr);
			
		 printf("%ld\n",sum);
	}
	return 0;
}