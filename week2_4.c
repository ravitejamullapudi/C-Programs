#include<stdio.h>
#include<stdlib.h>

struct test
{
	char input[100];
	char output[100];
}testDB[5]={{"ravi is good boy","boy good is ravi"},
{" " , " "},
{"ravi","ravi"},
{"    ravi   ","   ravi    "},
{"ravi is teacher","teacher is ravi"}};

int str_cmp(char *str1,char *str2)
{
	int i=0;
	while(str2[i]!='\0'||str1[i]!='\0')
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
void reverse(char *input,int l,int h)
{
	int middle=(l+h)/2;
	char temp;
	while(l<=middle)
	{
		temp=input[l];
		input[l]=input[h];
		input[h]=temp;
		l++;
		h--;
	}

}

char * reverse_words(char *input, int len)
{
	int i,j,k;
	reverse(input,0,len-1);
	for(i=0;i<len;i++)
	{
		if(input[i]==' ');
		else 
		{
			for(j=i+1;j<=len;j++)
			{
				if(input[j]==' '||input[j]=='\0')
				{
					reverse(input,i,j-1);
					i=j;
					break;
				}

			}

		}

	}
	return input;
}

void testcases()
{
	int i,len,check;
	char *input;
	for(i=0;i<5;i++)
	{
		len=str_len(testDB[i].input);
		input=(char *)malloc(sizeof(char)*(len+1));
		str_cpy(testDB[i].input,input);
		input=reverse_words(input,len);
		check=str_cmp(input,testDB[i].output);
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

