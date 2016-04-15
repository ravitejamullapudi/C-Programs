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
int testfun(char *str,int *i,int *j,int n1)
{
	if(*i<0)
		*i=0;
	if(*j>=n1)
		*j=n1-1;
	if(*j<0||*i>=n1)
	{
		printf("enter correct i,j values");
		return 0;

	} 
	if(*str==NULL)
	{
		printf("enter valid string ");
		return 0;
	}
	if(*i>*j)
	{
		*i=*i+*j;
		*j=*i-*j;
		*i=*i-*j;
	}

	return 1;
}
char * removeitoj(char *str,int i,int j,int n)
{
	int k;
	for(k=i;k<n-i;k++)
	{
		*(str+k)=*(str+k+n-j-1);
	}

	*(str+k)='\0';
	return str;
}

main()
{
	int i=0,j,n,test,n1;
	char *str,c;
	n=read();
	str=(char *)malloc(sizeof(char )*n);
	printf("enter string ");
		while((c=getchar())!='\n')
		{
			*(str+i)=c;
			i++;
		}
		*(str+i)='\0';
		n1=i;
		printf("%s",str);
	printf("enter i,j values");
	i=read();
	j=read();
	test=testfun(str,&i,&j,n1);
	if(test==1)
	{
		str=removeitoj(str,i,j,n1);
		printf("%s",str);
	}
	else
	{
		printf("enter string again ");
	}
	getch();
}
