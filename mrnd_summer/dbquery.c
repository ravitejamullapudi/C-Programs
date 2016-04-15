#include<stdio.h>
#include<stdlib.h>
struct student
{	char rno[15];
	char name[20];
	char marks[4];
	char address[50];
};
void display(struct student st)
{
	printf("%s\t%s\t%s\t%s",st.rno,st.name,st.marks,st.address);

}
 
int strcmp(char *str1,char *str2)
{
	int i=0;
	while(str1[i]!='\0')
	{
		if(str1[i]!=str2[i])
		{
			return 1;
		}
		i++;
	}
	if(str2[i]!='\0')
		return 1;
	return 0;
}
void strcpy(char *str1,int i,int j,char *str2)
{
	int iter=i;
	for(iter=i;iter<=j;iter++)
	{
		str2[iter-i]=str1[iter];
	}
	str2[iter-i]='\0';
}
int get_token_value1(char *token)
{
	if(strcmp(token,"rno")==0)
		return 10;
	else if(strcmp(token,"name")==0)
		return 11;
	else if(strcmp(token,"marks")==0)
		return 12;
	else if(strcmp(token,"address")==0)
		return 13;
	else 
		return 0;
}
int get_token_value2(char *token)
{
	if(strcmp(token,"sw")==0)
		return 21;
	else if(strcmp(token,"ew")==0)
		return 22;
	else if(strcmp(token,"eq")==0)
		return 23;
	else if(strcmp(token,"neq")==0)
		return 24;
	else if(strcmp(token,"gt")==0)
		return 25;
	else if(strcmp(token,"lt")==0)
		return 26;
	else if(strcmp(token,"gteq")==0)
		return 27;
	else if(strcmp(token,"lteq")==0)
		return 28;
	else if(strcmp(token,"contain")==0)
		return 29;
	else if(strcmp(token,"notcontain")==0)
		return 30;
}

void compare_tokens(char *query,int precedence)
{
	int i=0,k=0,res,res1,counter=0;
	char token[10];
	while(query[i]!='\0')
	{
		if(query[i]==' ')
		{
			strcpy(query,k,i-1,token);
			if(counter==0)
			{
			res=get_token_value1(token);
			counter ++;
			}
			else if(counter==1)
			{
				res1=get_token_value2(token);
			}
			k=i+1;
		}
		i++;
	}

}
void make_query_part(char *buffer,int i,int j,int precedence)
{
	char query[20];
	strcpy(buffer,i,j,query);
	compare_tokens(query,precedence);

}
void seperate_queries(char *buffer)
{
	int i=0,j=0,k=0;
	char check[4];
	while(buffer[i]!='\0')
	{
		if(buffer[i]==' ')
		{
			check[j]='\0';
			if(strcmp(check,"and")==0)
			{
				make_query_part(buffer,k,i-3,1);
				k=i+1;
			}
			else if(strcmp(check,"or")==0)
			{
				make_query_part(buffer,k,i-3,0);
			}
			else 
			{
				j=0;
			}

		}
		else 
		{
			check[j]=buffer[i];
			j++;
		}
		i++;
	}
	make_query_part(buffer,k,i-1,2);
}
main()
{
	char choice;
	char buffer[100];
	do
	{
		printf("enter the query\n ");
		scanf("%s ",buffer);
		seperate_queries(buffer);
		printf("do u want to continue y/n");
		scanf("%c",&choice);
	}while(choice=='y');
	getch();
}
