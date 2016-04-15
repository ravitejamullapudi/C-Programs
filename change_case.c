#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input[20];
	char output[20];
}testDB[6]={{"abcd","ABCD"},
{"1234","1234"},
{"12abc3","12ABC3"},
{"$123a","$123A"},
{"ABCD","abcd"},
{"12Ab,cD","12aB,Cd"}};

char * case_change(char *input)
{
	int val='a'-'A';
	int i=0;
	while(input[i]!='\0')
	{
		if(input[i]>='a'&&input[i]<='z')
			input[i]-=val;
		else if(input[i]>='A'&&input[i]<='Z')
			input[i]+=val;
		else ;
		i++;

	}
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
	int i; char *res;int check;
	for(i=0;i<6;i++)
	{
		res=case_change(testDB[i].input);
		 
		check=str_cmp(res,testDB[i].output);
		if(check==0)
			printf("passed\n");
		else printf("failed\n");
	}

}


main()
{
	testcases();
	getch();
}

