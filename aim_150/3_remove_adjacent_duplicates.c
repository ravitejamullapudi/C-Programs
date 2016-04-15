#include<stdio.h>
#include<stdlib.h>
int str_len(char *str)
{
	int i=0;
	while(str[i]!=NULL)
		i++;
	return i;
}
void copy_str(char *str1,char *str2)
{
	int i=0;
	while(str1[i]!=NULL)
	{
		str2[i]=str1[i];
		i++;
	}
	str2[i]=NULL;
}
void swap(char *a,char *b)
{
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
char * rem_adj_dup(char *str)
{
	int i=0,j=1;
	if(str[0]==NULL)return str;
	while(str[j]!=NULL)
	{
		if(str[j]!=str[i])
		{
		i++;
		if(i!=j)
			swap(&str[i],&str[j]);
		}
		j++;
	}
	str[i+1]=NULL;
	return str;
}

main()
{
	char str[100],*string,*res;
	int len;


	printf("enter string\n");
	fflush(stdin);
	gets(str);
	len=str_len(str);
	string=(char *)malloc(sizeof(char )*(len+1));
	copy_str(str,string);
	res=rem_adj_dup(string);
	printf("the reversed string is \n%s",res);
	getch();

}
