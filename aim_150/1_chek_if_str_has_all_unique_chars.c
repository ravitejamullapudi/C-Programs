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
int check_unique_char(char *str)
{
	int i=1;
	if(str[0]==NULL)
		return 0;
	while(str[i]!=NULL)
	{
		if(str[i]!=str[i-1])
			return 1;
		i++;
	}
	return 0;
}

main()
{
	char str[100],*string;
	int len,res;


	printf("enter string\n");
	scanf("%s",str);
	len=str_len(str);
	string=(char *)malloc(sizeof(char )*(len+1));
	copy_str(str,string);
	res=check_unique_char(string);
	if(res==0)
		printf("it has unique characters\n");
	else 
		printf("it has no unique characters\n");


	getch();
}

