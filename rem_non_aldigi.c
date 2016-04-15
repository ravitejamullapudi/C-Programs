#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input[20];
	char output[20];

}testDB[8]={{"ravi","ravi"},
{"$$$",NULL},
{"$abc$","abc"},
{"1234","1234"},
{"  ",NULL},
{"  123","123"},
{";:12:23","1223"},
{"*(()asdf","asdf"}};

char * rem_non_aldigi(char *input)
{
	int i=0,j=-1;
	while(input[i]!='\0')
	{
		if(input[i]>='a'&&input[i]<='z'||input[i]>='A'&&input[i]<='Z'||input[i]>='0'&&input[i]<='9')
		{
			if(i==j+1)
			{
				i++;
				j++;
			}
			else
			{
				j++;
				input[j]=input[i];
				i++;
			}

		}
		else
			i++;
	}
	input[j+1]=NULL;
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

void testcases()
{
	int i,check;char *res;
	for(i=0;i<8;i++)
	{
		res=rem_non_aldigi(testDB[i].input);
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

