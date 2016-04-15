#include<stdio.h>
#include<stdlib.h>
struct st
{
	char varname[5];
	int size;
	int *location;
	struct st *next;
};
int str_cmp(char *str1,char *str2)
{
	int i=0;
	while(str1[1]&&str2[i])
	{
		if(str1[i]!=str2[i])
		{
			return 1;
		}

	}
	if(str1[i]!=NULL)
		return 1;
	if(str2[i]!=NULL)
		return 1;
	return 0;
}
struct st * getNode()
{
	struct st *temp;
	temp=(struct st *)malloc(sizeof(struct st));
	temp->next=NULL;
	temp->size=0;
	temp->location=NULL;
	return temp;

}
int strlen(char *str)
{
	int i=0;
	while(str[i]!=NULL)
		i++;
	return i;
}
int getInt(char *str,int i)
{
	int x=0;
	while(str[i]!=']'&&str[i]!='\n')
	{
		x=10*x+str[i]-'0';
		i++;
	}
	return x;
}

struct st * create_st(struct st *sdata,char *buffer)
{
	char buffer1[10];
	struct st *t1;
	int i=0,res;
	while(buffer[i]!=' ')
	{
		buffer1[i]=buffer[i];
		i++;
	}
	buffer1[i]='\0';
	res=str_cmp(buffer1,"DATA");
	if(res==0)
	{
		t1=getNode();
		i++;
		while(buffer[i]!='\n'&&buffer[i]!='[')
		{
			t1->varname[i]=buffer[i];
			i++;
		}
		t1->varname[i]='\0';
		if(strlen(t1->varname)>4)
		{
			printf("invalid file");
			return NULL;
		}
		if(buffer[i]=='[')
		{
			t1->size=getInt(buffer,i++);
		}
		else
		t1->size=1;
	} 	
    else
	{
			res=str_cmp(buffer1,"CONST");
			if(res==0)
			{
			t1=getNode();
			i++;
			while(buffer[i]!='\n'&&buffer[i]!='=')
			{
			t1->varname[i]=buffer[i];
			i++;
			}
			t1->varname[i]='\0';
		
			if(strlen(t1->varname)>4)
			{
			printf("invalid file");
			return NULL;
			}
			if(buffer[i]=='=')
			{
			t1->size=getInt(buffer,i++);
			}
		}
		else
		{
			return;
		}
	}
}

struct st * create_s_table(struct st *sdata,char * fname)
{
	FILE *ftr;
	int i=0;
	char buffer[20],c;
	ftr=fopen(fname,"r");
	char c=fgetc(ftr);
	while(c!=EOF)
	{
		if(c!='\n')
		{
		buffer[i]=c;
		i++;
		c=fgetc(ftr);
		}
		else
		{
			buffer[i]='\0';
			i=0;
			sdata=create_st(sdata,buffer);
			if(sdata==NULL)
			{
				printf("file is not in correct format");
				return sdata;
			}

			fflush(stdin);
			c=fgetc(ftr);

		}

	}
	return sdata;
}
void display(struct st *sdata)
{

}

main()
{
	struct st *sdata=NULL;
	char fname[20];
	printf("enter file name");
	scanf("%s",fname);
	sdata=create_s_table(sdata,fname);
	display(sdata);
	getch();
}