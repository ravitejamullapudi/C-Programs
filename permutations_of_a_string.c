#include<stdio.h>
#include<stdlib.h>

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

void swap(char *a,char *b)

{
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
void permut(char *str,int l,int h)
{
	int i;
	if(l==h)
		printf("\n%s",str);
	else
	{
		for(i=l;i<=h;i++)
		{
			swap(str+l,str+i);
			permut(str,l+1,h);
			swap(str+l,str+i);

		}

	}

}


void main()
{
	int n;
	char *str;
	printf("enter no of elements ");
	n=read();
	str=(char *)malloc((n+1)*sizeof(char));
	printf("enter the string ");

	scanf("%s",str);
	permut(str,0,n-1);
	getch();
}
