#include<stdio.h>
#include<stdlib.h>

char * reverse_words(char *str,int n)
{
	int i=0,k=n-1;
	while(i<=n/2)
	{
		*(str+i)=*(str+i)+*(str+k);
		*(str+k)=*(str+i)-*(str+k);
		*(str+i)=*(str+i)-*(str+k);
		k--;
		i++;
	}

}
