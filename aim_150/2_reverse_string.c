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

char *str_rev(char *str,int len)
{
	int i=0;
	int j=len-1;
	while(i<len/2)
	{
		swap(&str[i],&str[j]);
		i++;
		j--;
	}
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
	res=str_rev(string,len);
	printf("the reversed string is \n%s",res);
	getch();

}
