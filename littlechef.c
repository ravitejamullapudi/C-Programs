#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int *arr,n,i,t,count=0,count_2=0;
	scanf("%u",&t);
	while(t--)
	{ 
		count=0;
		count_2=0;
		scanf("%u",&n);
		arr=(unsigned int *)malloc(sizeof(unsigned int )*n);
		for(i=0;i<n;i++)
		{
			scanf("%u",arr+i);
		}
		printf("\n");
		 for(i=0;i<n;i++)
		 {
			if(*(arr+i)>2)
				count++;
			else if((*arr+i)==2)
				count_2++;
			else ;
		 }
		 if(count!=1)
		 count=count*(count-1)/2+count*count_2;
		 else
			 count=count+count*count_2;

		printf("%u\n",count);
		free(arr);
	}
	return 0;

}
