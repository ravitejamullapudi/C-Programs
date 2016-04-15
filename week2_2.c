#include<stdio.h>
#include<stdlib.h>

struct test 
{
	char input[30];
	char output[30];
}testDB[5]={{"      ",NULL},
{"   ravi","r a v i"},
{" ra vi ", "r a v i"},
{"123   rav", "1 2 3 r a v"},
{"12$&&a","1 2 $ & & a"}};

char *remove_spaces(char *input)
{
	int i=0,j=-1;
	while(input[i]!='\0')
	{
		if(input[i]!=' ')
		{
			if(i==j+1)
			{
				i++;
				j++;
			}
			else
			
				input[++j]=input[i++];
		}
		else i++;
	}
	input[j+1]='\0';
	return input;
}
int str_cmp(char *str1,char *str2)
{
	int i=0;
	while(str2[i]!='\0')
	{
		if(str1[i]!=str2[i])
			return 1;
		i++;

	}
	return 0;
}
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
char *include_spaces(char *input,int len)
{
	int i=0,temp=2*len-2,var=len-1;
	input=(char *)realloc(input,2*len);
	input[len]=' ';
	
	
	for(i=0;i<2*len-1;i++)
	{
		if(i%2==0)
		{
			input[temp]=input[var];
			temp--;
			var--;
		}
		else
		{
			input[temp]=' ';
			temp--;
		}
	}
	input[2*len-1]='\0';
	return input;
}


void testcases()
{
	int i,check,len,j;
	
	char *input;
	for(i=0;i<5;i++)
	{
		len=str_len(testDB[i].input);
		input=(char *)malloc(sizeof(char)*(len+1));
		str_cpy(testDB[i].input,input);

		input=remove_spaces(input);
		len=str_len(input);
		 if(len!=0)
			input=include_spaces(input,len);
		check=str_cmp(input,testDB[i].output);
		if(check==0)
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

