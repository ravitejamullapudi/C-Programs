#include<stdio.h>
#include<stdlib.h>
struct st
{
	 char varname[5];
	 int size;
	 char *loc;
	 struct st *next;
};
struct opera
{
	char mode;
	char *val1;
	char  *val2;
	char  *val3;
	struct opera *next;
}*op;
int flag=0;
char A[8]={0};
char carry=0;
char Rel[5]={0,1,2,3,4};
int str_cmp(char *str1,char *str2)
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
int str_cmp1(char *str1)
{
	int i=0;
	int res;
	if(str_cmp(str1,"DATA")==0)
		return 1;
	else if(str_cmp(str1,"CONST")==0)
		return 2;
	else if(str_cmp(str1,"MOV")==0)
		return 3;
	else if(str_cmp(str1,"ADD")==0)
		return 4;
		else if(str_cmp(str1,"SUB")==0)
		return 5;
	else if(str_cmp(str1,"MUL")==0)
		return 6;
	else if(str_cmp(str1,"READ")==0)
		return 7;
	else if(str_cmp(str1,"PRINT")==0)
		return 8;
	else if(str_cmp(str1,"IF")==0)
		return 9;
	else if(str_cmp(str1,"ELSE")==0)
		return 10;
	else if(str_cmp(str1,"X:")==0)
		return 11;
	else if(str_cmp(str1,"JMP")==0)
		return 12;
	else if(str_cmp(str1,";")==0)
		return 13; 
	return 0;
}
struct st * getNode()
{
	
	struct st *temp;
	temp=(struct st *)malloc(sizeof(struct st));
	temp->loc=NULL;
	temp->next=NULL;
	temp->size=0;
	return temp;
}
int str_len(char *str)
{
	int i=0;
	while(str[i]!=NULL)
		i++;
	return i;
}
int getInt(char *buffer,int i)
{
	int x=0;
	while(buffer[i]!=']'&&buffer[i]!='\0')
	{
		x=x*10+buffer[i]-'0';
		i++;
	}
	return x;
}
struct st * find_null(struct st *sdata)
{
		while(sdata->next!=NULL)
		{
			sdata=sdata->next;
		}
		return sdata;
}
struct st * create_var(struct st *sdata,char *buffer,int i)
{
	struct st *temp,*ptr1;
	int j=0;
	char *a;
	
	temp=getNode();
	while(buffer[i]!='\0'&&buffer[i]!='[')
	{
		temp->varname[j]=buffer[i];
		i++;
		j++;
	}
	temp->varname[j]='\0';
	if(str_len(temp->varname)>4)
	{
		printf("variable name length is more then 4");
		return ;
	}
	if(buffer[i]=='[')
	{
		if(buffer[i+1]>='0'&&buffer[i+1]<='9')
		temp->size=getInt(buffer,i+1);
		 
	}
	else
		temp->size=1;
	if(sdata==NULL)
	{
		sdata=temp;
		temp->next=NULL;
	}
	else
	{
		ptr1=find_null(sdata);
		ptr1->next=temp;
		temp->next=NULL;
	}
	a=(char *)malloc(temp->size);
	i=0;
	while(i<temp->size)
	{
		a[i]=0;
		i++;
	}
	temp->loc=a;
	return sdata;
}
struct st * create_const(struct st *sdata,char *buffer,int i)
{
	struct st *temp,*ptr1;
	int j=0;
	char *a;
	a=(char *)malloc(1);
	temp=getNode();
	while(buffer[i]!='=')
	{
		temp->varname[j]=buffer[i];
		i++;
		j++;
	}
	temp->varname[j]='\0';
	if(str_len(temp->varname)>4)
	{
		printf("variable name length is more then 4");
		return ;
	}
	i++;
	temp->size=1;
	*a=getInt(buffer,i);
	printf("%d",*a);
	temp->loc=a;
	if(sdata==NULL)
		sdata=temp;
	else
	{
		ptr1=find_null(sdata);
		ptr1->next=temp;
	}
	return sdata;
}
int reg_cmp(char *str1,char *str2)
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
int find_reg(char *buffer)
{
	
	if(reg_cmp(buffer,"AX")==0)
		return 0;
	else if(reg_cmp(buffer,"BX")==0)
		return 1;
	else if(reg_cmp(buffer,"CX")==0)
		return 2;
	else if(reg_cmp(buffer,"DX")==0)
		return 3;
	else if(reg_cmp(buffer,"EX")==0)
		return 4;
	else if(reg_cmp(buffer,"FX")==0)
		return 5;
	else if(reg_cmp(buffer,"GX")==0)
		return 6;
	else if(reg_cmp(buffer,"HX")==0)
		return 7;
	return 9;
}
/*void read(char *buffer,int i)
{
	int res;
	res=find_reg(buffer,i);
	if(res<0||res>0)
	{
		return;
	}
	scanf("%d",&A[res]);
}
void print(char *buffer,int i)
{
	int res;
	res=find_reg(buffer,i);
	if(res<0||res>0)
	{
		return;
	}
	printf("%d",A[res]);
}*/
struct opera * getNode1()
{
	struct opera *temp;
	temp=(struct opera *)malloc(sizeof(struct opera));
	temp->mode=0;
	temp->next=NULL;
	temp->val1=NULL;
	temp->val2=NULL;
	temp->val3=NULL;
	return temp;
}
struct st * find_st(char *str,struct st *sdata)
{
	struct st *ptr=sdata;
	while(ptr)
	{
		if(str_cmp(str,ptr->varname)==0)
			return ptr;
		ptr=ptr->next;
	}
	return NULL;
}
char * find_reg_var(char *buffer,int *i,struct st *sdata)
{
	char *add;
	char str[10];
	struct st *res1,*res2;
	int res;
	int j=0;
	while(buffer[*i]!=NULL&&buffer[*i]!=','&&buffer[*i]!='[')
	{
		str[j]=buffer[*i];
		j++;
		*i=*i+1;
	}
	str[j]=NULL;
	res=find_reg(str);
	if(res!=9)
	{
		*i=*i+1;
		return &A[res];
	}
	else
	{
		res1=find_st(str,sdata);
		if(res1==NULL)
			return;
		if(buffer[*i]!='[')
		{
			return (res1->loc);
		}
		else
		{
			if(buffer[*i+1]>='0'&&buffer[*i+1]<='9')
			{
				
				res=getInt(buffer,*i+1);
				return &(res1->loc)[res];
			}
			else
			{
				fflush(stdin);
				*i=*i+1;
				j=0;
				while(buffer[*i]!=']')
				{
					str[j]=buffer[*i];
					j++;
					*i=*i+1;
				}
				str[j]='\0';
			res2=find_st(str,sdata);
			if(res2==NULL)
				return;
			add= &(res1->loc)[*(res2->loc)];
			*i=*i+2;
			return add;
			}
			}

	}

}

void move(struct opera *temp,char *buffer,int i,struct st *sdata)
{
	char * res;
	res=find_reg_var(buffer,&i,sdata);
	temp->val1=res;
	res=find_reg_var(buffer,&i,sdata);
	temp->val2=res;

}
void add(struct opera *temp,char *buffer,int i,struct st *sdata)
{
	char str[3];
	int res;
	int j=0;
	str[0]=buffer[i];
	i++;
	str[1]=buffer[i];
	i++;
	i++;
	str[2]='\0';
	res=find_reg(str);
	temp->val1=&A[res];

	str[0]=buffer[i];
	i++;
	str[1]=buffer[i];
	i++;
	i++;
	str[2]='\0';
	res=find_reg(str);
	temp->val2=&A[res];

	str[0]=buffer[i];
	i++;
	str[1]=buffer[i];
	i++;
	i++;
	str[2]='\0';
	res=find_reg(str);
	temp->val3=&A[res];

}
void read_print(struct opera *temp,char *buffer,int i)
{
	char str[3];
	int j=0;
	int res;
	while(buffer[i]!='\0')
	{
		str[j]=buffer[i];
		j++;
		i++;
	}
	str[j]='\0';
	res=find_reg(str);
	if(res==9)
	{
		return;

	}
	else
		temp->val1=&A[res];
}
int find_rel(char *buffer)
{
	if(str_cmp(buffer,"LT")==0)
		return 0;
	else if(str_cmp(buffer,"LTEQ")==0)
		return 1;
	else if(str_cmp(buffer,"EQ")==0)
		return 2;
	else if(str_cmp(buffer,"GT")==0)
		return 3;
	else if(str_cmp(buffer,"GTEQ")==0)
		return 4;
	else 
		return 5;
}

void if_(struct opera *temp,char *buffer, int i)
{
	char str[5];
	int j=0;
	int res;
	int counter=0;
	while(buffer[i]!='T')
	{
		if(buffer[i]==' ')
		{
			str[j]='\0';
			res=find_reg(str);
				if(counter==0||counter==2)
				{
					if(counter==0)
					temp->val1=&A[res];
					else
						temp->val3=&A[res];
					counter++;
				}
				else
				{
					counter++;
					res=find_rel(str);
					if(res==5)
						return;
					temp->val2=&Rel[res];
				}
				i++;
				j=0;;
		}
		else
		{
		str[j]=buffer[i];
		i++;
		j++;
		}
	}
	str[j]='\0';

}
void else_(struct opera *temp,char *buffer, int i)
{

}
void Label_(struct opera *temp,char *buffer, int i)
{

}
void jmp_(struct opera *temp,char *buffer,int i)
{

}
void semi_colon(struct opera *temp,char *buffer,int i)
{

}

void operation(int mode,char *buffer,int i,struct st *sdata)
{
	struct opera *temp;
	struct opera *ptr=op;
	temp=getNode1();
	temp->mode=mode;
	 switch(mode)
	 {
	 case 3:
		 move(temp,buffer,i,sdata);
		 break;
	 case 4:
	 case 5:
	 case 6:
		 add(temp,buffer,i,sdata);
		 break;
	 case 7:
	 case 8:
		 read_print(temp,buffer,i);
		 break;
	 case 9:
		 if_(temp,buffer,i);
		 break;
	 case 10:
		 else_(temp,buffer,i);
		 break;
	 case 11:
		 Label_(temp,buffer,i);
		 break;
	 case 12:
		 jmp_(temp,buffer,i);
		 break;
	 case 13:
		 semi_colon(temp,buffer,i);
		 break;
	 }
	 if(ptr==NULL)
		 op=temp;
	 else
	 {
		 while(ptr->next)
		 {
			 ptr=ptr->next;
		 }
		 ptr->next=temp;
	 }

		 


}

struct st * create_stable(struct st *sdata,char *buffer)
{
	char str[30];
	int i=0,res;
	if(buffer[i]==EOF)
		return sdata;
	while(buffer[i]!=' '&&buffer[i]!=';')
	{
		str[i]=buffer[i];
		i++;
	}
	if(buffer[i]==';')
	{ 
		str[i]=';';
		i++;
	}

	str[i]='\0';
	res=str_cmp1(str);
	switch(res)
	{
	case 1:
		sdata=create_var(sdata,buffer,i+1);
		break;
	case 2:
		sdata=create_const(sdata,buffer,i+1);
		break;
	case 3:
		operation(3,buffer,i+1,sdata);
		break;
	case 4:
		operation(4,buffer,i+1,sdata);
		break;
	case 5:
		operation(5,buffer,i+1,sdata);
		break;
	case 6:
		operation(6,buffer,i+1,sdata);
		break;
	case 7:
		operation(7,buffer,i+1,sdata);
		break;
	case 8:
		operation(8,buffer,i+1,sdata);
		break;
	case 9:
		operation(9,buffer,i+1,sdata);
		break;
	case 10:
		operation(10,buffer,i+1,sdata);
		break;
	case 11:
		operation(11,buffer,i+1,sdata);
		break;
	case 12:
		operation(12,buffer,i+1,sdata);
		break;
	case 13:
		operation(13,buffer,i+1,sdata);
		break;
	 
	}
	fflush(stdin);
	return sdata;
}
struct st * create_st(struct st *sdata,FILE *ftr)
{
	char c,buffer[50];
	int i=0,res;
	FILE *ptr;
	ptr=ftr;
	c=fgetc(ftr);
	while(c!=EOF)
	{
		if(c!='\n')
		{
		buffer[i]=c;
		i++;
		ptr=ftr;
		}
		else
		{
			buffer[i]='\0';
			i=0;
			sdata=create_stable(sdata,buffer);
		}
		
		c=fgetc(ftr);

	}
	buffer[i]='\0';

	sdata=create_stable(sdata,buffer);
	fflush(stdin);
	return sdata;
}
void display(struct st *sdata)
{
	while(sdata)
	{
		printf("%s->%d->%d\n",sdata->varname,sdata->size,*(sdata->loc));
		sdata=sdata->next;
	}
	return ;
}
void display_mode(struct opera *op)
{
	struct opera *op1=op;
	while(op1)
	{
		printf("%d->\n",op1->mode);
		op1=op1->next;
	}

}
void move_val(struct opera *ptr)
{
	ptr->val1=ptr->val2;
	//printf("%d->%d\n",*(ptr->val1),*(ptr->val2));
}
void add_val(struct opera *ptr)
{
	//printf("%d->%d->%d\n",*(ptr->val1),*(ptr->val2),*(ptr->val3));
	*ptr->val1=*ptr->val2+*ptr->val3;
	//printf("%d->%d->%d\n",*(ptr->val1),*(ptr->val2),*(ptr->val3));
}
void sub_val(struct opera *ptr)
{
	*(ptr->val1)=*(ptr->val2)+*(ptr->val3);
}
void mul_val(struct opera *ptr)
{
	*(ptr->val1)=*(ptr->val2)**(ptr->val3);
}
void read_val(struct opera *ptr)
{
	
	printf("enter value\n");
	scanf("%d",&ptr->val1);
}
void print_val(struct opera *ptr)
{
	printf("%d",*(ptr->val1));
}
int if_val(struct opera *ptr)
{
	int res;
	switch(*(ptr->val2))
	{
	case 0:
		if(*(ptr->val1)<*(ptr->val3))
			return 0;
		return 1;
		break;
	case 1:
		if(*(ptr->val1)<=*(ptr->val3))
			return 0;
		return 1;
		break;
	case 2:
		if(*(ptr->val1)==*(ptr->val3))
			return 0;
		return 1;
		break;
	case 3:
		if(*(ptr->val1)>*(ptr->val3))
			return 0;
		return 1;
		break;
	case 4:
		if(*(ptr->val1)>*(ptr->val3))
			return 0;
		return 1;
		break;

	}


}
void simulator(struct opera *op)
{
	struct opera *ptr1=NULL,*ptr2=NULL;
	int res;
	ptr1=op;
	while(ptr1)
	{
		res=ptr1->mode;
		switch(res)
		{
		case 3:
			move_val(ptr1);
			ptr1=ptr1->next;
			break;
		case 4:
			add_val(ptr1);
			ptr1=ptr1->next;
			break;
		case 5:
			sub_val(ptr1);
			ptr1=ptr1->next;
			break;

		case 6:
			mul_val(ptr1);
			ptr1=ptr1->next;
			break;
		case 7:
			read_val(ptr1);
			ptr1=ptr1->next;
			break;
		case 8:
			print_val(ptr1);
			ptr1=ptr1->next;
			break;
		case 9:
			res=if_val(ptr1);
				if(res==0)
				{
					flag=1;
				}
				else
				{
					flag=0;
					while(ptr1->mode!=13)
					{
						ptr1=ptr1->next;
					}
					

				}

				ptr1=ptr1->next;
			break;
		case 10:
			if(flag!=0)
			{
				while(ptr1->mode!=13)
					{
						ptr1=ptr1->next;
					}
			}
			ptr1=ptr1->next;
			break;
		case 11:
			ptr2=ptr1;
			ptr1=ptr1->next;
			break;
		case 12:
			ptr1=ptr2;
			ptr1=ptr1->next;
			break;
		case 13:
			ptr1=ptr1->next;
			break;

		}

	}

}

main()
{
	struct st *sdata=NULL;
	FILE *ftr;
	char fname[20];
	//printf("enter the file name");
	//scanf("%s",fname);
	ftr=fopen("fibonaci.asm","r");
	if(ftr==NULL)
	{
		printf("file name does not exists");
		getch();
		return 0;
	}

	sdata=create_st(sdata,ftr);
	display(sdata);
	display_mode(op);
	simulator(op);
	getch();
}
