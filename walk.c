#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int *arr,n,i,t,temp;
	scanf("%u",&t);
	while(t--)
	{ 
		temp=0;
		scanf("%u",&n);
		arr=(unsigned int *)malloc(sizeof(unsigned int )*n);
		for(i=0;i<n;i++)
		{
			scanf("%u",arr+i);
		}
		printf("\n");
		while(n--)
		{
			if(temp<(*(arr+n)+n))
			{
				temp=*(arr+n)+n;
			}

		}
		printf("%d\n",temp);
		free(arr);
	}
	return 0;

}
