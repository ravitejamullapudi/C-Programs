#include<stdio.h>
#include<stdlib.h>
int str_equals(char *input,int start_index,int end_index,char *str)
{
	int i,j=0;
	for(i=start_index;i<=end_index&&str[j]!=NULL;i++)
	{
		if(input[i]!=str[j])
		{
			return 1;
		}
		j++;
	}
	if(str[j]!=NULL)
		return 1;
	if(input[i]!=' '&&input[i]!='\0')
	return 1;
	return 0;
}
void mov_spaces(char *input,int *i)
{
	//printf("%d\n",input[*i]);
	while(1)
	{
		if((input[*i]!=' ')||(input[*i]=='\0'))
			break;
		(*i)++;
	}

}
void find_word_indexes(char *input,int *i,int *j)
{
	for(*j=*i;input[*j]!=' '&&input[*j]!='\0';(*j)++)
		;
	(*j)--;
}
void replace_word(char *input,int i,int j,char *str)
{
	int k=0;
	while(i!=j+1&&str[k]!=NULL)
	{
		input[i]=str[k];
		i++;
		k++;
	}

}

char * ori_equal_rep(char *input, int len,char *ori, char *rep)
{
	int i=0,j=0,res;
	//printf("%s",input);
	mov_spaces(input,&i);//to move to the starting index of the word
	j=i;
	while(input[i]!=NULL)
	{
	find_word_indexes(input,&i,&j);//to find the word
	res=str_equals(input,i,j,ori);//to check if the word is equal to the given word of not
	if(res==0)
	{
		replace_word(input,i,j,rep);//to replace the original word with the new word
	}
	i=j+1;
	mov_spaces(input,&i);
	j=i;
	}
	return input;
}
void copy_str_rev(char *input,int *len_new,char *rep,int len2)
{
	len2--;
	while(len2>=0)
	{
		input[*len_new]=rep[len2];
		(*len_new)--;
		len2--;
	}

}

char * ori_less_then_rep(char *input,int len, char *ori,int len1,char *rep,int len2)
{
	int i=0,j=0,res,len_new;
	int index[10],k=0;
	mov_spaces(input,&i);//to move to the starting index of the word
	j=i;
	while(input[i]!=NULL)
	{
	find_word_indexes(input,&i,&j);//to find the word
	res=str_equals(input,i,j,ori);//to check if the word is equal to the given word of not
	if(res==0)
	{
		index[k]=j;
		k++;
	}
	i=j+1;
	mov_spaces(input,&i);
	j=i;
	}
	i--;
	input=(char *)realloc(input,len+1+k*(len2-len1));
	len_new=len+k*(len2-len1);
	input[len_new]='\0';
	len_new--;
	k--;
	while(k>=0)
	{
		if(i==index[k])
		{
			i-=len1;
			copy_str_rev(input,&len_new,rep,len2);
			k--;
		}
		else
		{
			input[len_new]=input[i];
			len_new--;
			i--;
		}

	}

	return input;
}
void copy_str_start(char * input, int *i,char *rep,int len2)
{
	int k=0;
	while(k<len2)
	{
		input[*i]=rep[k];
		k++;
		(*i)++;
	}

}

char * ori_greater_then_rep(char *input,int len,char *ori,int len1,char *rep,int len2)
{
	int i=0,j=0,res,len_new,iter=0,iter_new=0;
	int index[10]={0},k=0;
	mov_spaces(input,&i);//to move to the starting index of the word
	j=i;
	while(input[i]!=NULL)
	{
	find_word_indexes(input,&i,&j);//to find the word
	res=str_equals(input,i,j,ori);//to check if the word is equal to the given word of not
	if(res==0)
	{
		index[k]=i;
		k++;
	}
	i=j+1;
	mov_spaces(input,&i);
	j=i;
	}
	i=index[0];
	//input=(char *)realloc(input,len+1+k*(len2-len1));
	len_new=len-k*(len1-len2);
	
	
	k--;
	iter_new=i;
	while(iter_new<len)
	{
		if(iter_new==index[iter])
		{
			
			copy_str_start(input,&i,rep,len2);
			iter++;
			iter_new+=len1;
			
			
		}
		else
		{
			input[i]=input[iter_new];
			iter_new++;
			i++;
		}

	}
	input[len_new]='\0';
	return input;
}

void main()
{
	int len,len1,len2,i=0;
	char *input,*ori,*rep,*res;
	char c;
	printf("enter the string length\n");
	scanf("%d",&len);
	input=(char *)malloc(sizeof(char)*(len+1));
	printf("enter text\n");
	fflush(stdin);
	//while((c=getchar())!='\n')
	//{
		//input[i]=c;
		//i++;
	//}
	gets(input);
	printf("%s",input);
	//input[i]='\0';
	printf("enter original word length\n");
	scanf("%d",&len1);
	ori=(char *)malloc(sizeof(char)*(len1+1));
	printf("enter the original word\n");
	scanf("%s",ori);
	printf("enter replacable word length\n");
	scanf("%d",&len2);
	rep=(char *)malloc(sizeof(char )*(len2+1));
	printf("enter replacable word\n");
	scanf("%s",rep);
	if(len1==len2)
		res=ori_equal_rep(input,len,ori,rep);
	else if(len1<len2)
		res=ori_less_then_rep(input,len,ori,len1,rep,len2);
	else 
		res=ori_greater_then_rep(input,len,ori,len1,rep,len2);
	printf("the new text is \n %s",res);
	getch();
}
