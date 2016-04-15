#include<stdio.h>
#include<stdlib.h>

struct test 
{
	char input[30];
	char output[30];
}testDB[5]={{"      ",NULL},
{"   ravi","ravi"},
{" ra vi ", "ravi"},
{"123   rav", "123rav"},
{"12$&&a","12$&&a"}};

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


void testcases()
{
	int i,check,len,j;
	char *res;
	char *input;
	for(i=0;i<5;i++)
	{
		len=str_len(testDB[i].input);
		input=(char *)malloc(sizeof(char)*(len+1));
		str_cpy(testDB[i].input,input);

		res=remove_spaces(input);
		check=str_cmp(res,testDB[i].output);
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

