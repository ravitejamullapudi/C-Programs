//replace spaces with '%20'

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
int count_spaces(char *str)
{
	int i=0;
	int count=0;
	while(str[i]!=NULL)
	{
		if(str[i]==' ')
			count++;
		i++;
	}
	return count;
}
char * insert_str(char *str,int *full_length)
{
	str[(*full_length)--]='0';
	str[(*full_length)--]='2';
	str[(*full_length)--]='%';
	return str;
}

char * replace_sp(char *str,int len, int sp_count)
{
	int full_length=len+2*sp_count-1;
	str[full_length+1]=NULL;
	
	len--;
	while(len>=0)
	{
		if(str[len]==' ')
		{
			str=insert_str(str,&full_length);
		}
		else 
		{
			str[full_length]=str[len];
			full_length--;
		}
		len--;
	}
	return str;
}

main()
{
	 char str[100];
	 int sp_count=0,len,res;
	 char *string;
	 printf("enter the string \n");
	 fflush(stdin);
	 gets(str);
	 len=str_len(str);
	 string=(char *)malloc(sizeof(char)*(len+1));
	 copy_str(str,string);
	 sp_count=count_spaces(string);
	 string=(char *)realloc(string,len+1+2*sp_count);
	 string=replace_sp(string,len,sp_count);
	 printf("the string is \n%s",string);
	 getch();
}
