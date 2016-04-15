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

int check_for_anagram(char *str1,char *str2)
{
	int count1=1,count2=0;
	char c;
	int i=0,j=0,k;
	while(str1[i]!=NULL)
	{
		if(str1[i]!='$')
		{
			c=str1[i];
			str1[i]='$';
			k=i+1;
			i++;
			while(str1[i]!=NULL)
			{
				if(str1[i]==c)
				{
					str1[i]='$';
					count1++;
				}
				i++;
			}
			while(str2[j]!=NULL)
			{
				if(str2[j]==c)
					count2++;
				j++;
			}
			if(count1!=count2)
				return 1;
			count1=1;
			count2=0;
			i=k;
			j=0;
		}
		else
			i++;

	}
	return 0;
}

main()
{
	char str1[100],str2[100],*string1,*string2;
	int res;
	int len1,len2;


	printf("enter string\n");
	fflush(stdin);
	gets(str1);
	printf("enter string to check\n");
	gets(str2);
	len1=str_len(str1);
	len2=str_len(str2);
	if(len1!=len2)
	{
		printf("they are not anagrams\n");
		getch();
		exit(0);
	}
	string1=(char *)malloc(sizeof(char )*(len1+1));
	copy_str(str1,string1);
	string2=(char *)malloc(sizeof(char )*(len2+1));
	copy_str(str2,string2);
	res=check_for_anagram(string1,string2);
	if(res==0)
		printf("they are anagrams\n");
	else
		printf("they are not anagrams\n");
	getch();

}
