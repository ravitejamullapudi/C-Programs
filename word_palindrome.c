#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input[100];
	int output;
}testDB[5]={{"this is not a not is this                  ",1},
{"bad boy is boy bad",1},
{"bad",1},
{"good bad",0},
{"madam",1}};
int str_len(char *str)
{
	int i=0;
	while(str[i]!='\0')
		i++;
	return i;
}
void str_cpy(char *str1,char *str2)
{
	int i=0;
	while(str1[i]!='\0')
	{
		str2[i]=str1[i];
		i++;
	}
	str2[i]='\0';

}
int word_palindrome(char *input,int len)
{
	int i=0,j=len-1,k;
	while(i<j)
	{
		while(input[j]==' '&&j!=0)
			j--;
		while(input[j]!=' '&&j!=-1)
		{
			j--;
		}
		if(j==-1)
			return 1;
		if(input[j]==' ')
		{
			k=j+1;

		}
		while(input[i]==' ')
			i++;
		while(input[i]!=' '&&input[i]!='\0')
		{
			if(input[i]!=input[k])
				return 0;
			i++;
			k++;
		}
		
	}
	return 1;
}

void testcases()
{
	int i,check,len;
	char *input;
	for(i=0;i<5;i++)
	{
		len=str_len(testDB[i].input);
		input=(char *)malloc(sizeof(char)*(len+1));
		str_cpy(testDB[i].input,input);
		check=word_palindrome(input,len);
		if(check==testDB[i].output)
			printf("passed\n");
		else 
			printf("failed\n");
	}


}

main()
{
	testcases();
	getch();
}

