#include<stdio.h>
#include<stdlib.h>

void stdrev(char *,int,int);
void display(char *);

main()
{
	int n,i,j;
		char *str;
		scanf("%d",&n);
		str=(char *)malloc(n*sizeof(char));
		scanf("%s",str);
		scanf("%d%d",&i,&j);
		if(i<0)
			i=0;
		if(j>=n)
		j=n-1;
		if(i>j)
		{
			i=i+j;
			j=i-j;
			i=i-j;
		}
		if(i>=n||j<0)
		{
		printf("the substring is not possible");
		return;
		}

		stdrev(str,i,j);
		display(str);
		getch();
}

void stdrev(char *str,int i,int j)
{
	int k,t;
	char temp;
	k=(i+j)/2;
	for(t=i;t<=k;t++)
	{
		temp=*(str+i);
		*(str+i)=*(str+j);
		*(str+j)=temp;
		i++;
		j--;

	}

}
void display(char *str)
{
	printf("%s",str);
}


