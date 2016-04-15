#include<stdio.h>
#include<stdlib.h>
void swap(char *a,char *b)
{
	char c;
	c=*a;
	*a=*b;
	*b=c;
}

char * rev_line(char *str,int start_index,int end_index)
{
	while(start_index<end_index)
	{
		swap(&str[start_index],&str[end_index]);
		start_index++;
		end_index--;
	}
	return str;
}
void find_non_space(char *input,int *i)
{
	while(1)
	{
		if(input[*i]!=' ')
			break;
		(*i)++;
	}

}
void find_space(char *input,int *j)
{
	while(1)
	{
		if(input[*j]==' '||input[*j]=='\0')
			break;
		(*j)++;
	}
	(*j)--;
}

char * rev_line_rev_alt_word(char *input,int len)
{
	int i=0,j=0,flag=1;
	input=rev_line(input,0,len-1);
	find_non_space(input,&i);
	while(input[i]!=NULL)
	{
		j=i;
		find_space(input,&j);
		if(flag==1)
		{
			flag=0;
		}
		else
		{
			input=rev_line(input,i,j);
			flag=1;
		}
		i=j+1;
		find_non_space(input,&i);
	}
	return input;
}

main()
{
	int i,len=0,t=10;
	char *input,c,*res;
	input=(char *)malloc(sizeof(char)*(t));
	printf("enter the text \n");
	fflush(stdin);
	while((c=getchar())!='\n')
	{
		input[len]=c;
		len++;
		if(len==t)
		{
			t=t+t;
			input=(char *)realloc(input,sizeof(char)*t);
		}

	}
	input[len]='\0';
	res=rev_line_rev_alt_word(input,len);
	printf("%s",res);
	getch();
}
