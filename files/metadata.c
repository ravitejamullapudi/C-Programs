#include<stdio.h>
#include<stdlib.h>
struct md
{
	char fname[20];
	int size;
	int start_indx;
	int time;
};
int str_cmp(char *str1,char *str2)
{
	int i=0;
	while(str1[i]!=NULL&&str2[i]!=NULL)
	{
		if(str1[i]!=str2[i])
		{
			return 1;
		}
		i++;
	}
	if(str1[i]!=NULL)
		return 1;
	if(str2[i]!=NULL)
		return 1;
	return 0;
}

FILE * search(FILE *ftr,char *str)
{
	int res,res1;
	struct md t1;
	int c;
	while(1)
	{
		c=fgetc(ftr);
		res=fseek(ftr,-1,1);
	if((c)=='0')
	{
		if(res==0)
			return ftr;
		else 
		   return NULL;
	}
	else
	{
		if((res=fread(&t1,sizeof(struct md),1,ftr))==1);
		{
			res1=str_cmp(t1.fname,str);
			if(res1==0)
			{
				return ftr;
			}
		}
	}
	}
}

void create()
{
	FILE *ftr;
	struct md t;
	int res;
	ftr=fopen("file_8mb4.txt","rb+");
	if(ftr==NULL)
	{
		printf("error in opening file");
		return;
	}
 	printf("enter file name and size");
	scanf("%s%d",t.fname,&t.size);
	t.start_indx=0;
	t.time=0;
	ftr=search(ftr,t.fname);
	if(ftr==NULL)
	{
		printf("file name already exists");
		return ;
	}
	if((res=fwrite(&t,sizeof(struct md),1,ftr))!=1)
	{
		printf("error1");
	}
	fflush(ftr);
	fclose(ftr);
 	printf("insertd successfully");
}
void listallfiles()
{
	FILE *ftr;
	int res;
	char c;
	struct md t1;
	ftr=fopen("file_8mb4.txt","rb");
	if(ftr==NULL)
		printf("error");
	if((c=fgetc(ftr))!='0')
	{
		fseek(ftr,-1,1);
	res=fread(&t1,sizeof(struct md),1,ftr);
	}
	while(res==1)
	{
		printf("%s-->%d->%d->%d\n",t1.fname,t1.size,t1.start_indx,t1.time);
		if((c=fgetc(ftr))!='0')
		{
			fseek(ftr,-1,1);
		res=fread(&t1,sizeof(struct md),1,ftr);
		}
		else break;
	}
}
void deletefile()
{
	FILE *ftr=NULL;
	int res;
	char name[20];
	ftr=fopen("file_8mb4.txt","rb+");
	printf("enter file name");
	scanf("%s",name);
	ftr=search(ftr,name);
	if(ftr==NULL)
	{
		printf("file name doesnot exists");
		return ;
	}
	else
	{
		res=fseek(ftr,-sizeof(struct md),1);
		fputc('0',ftr);
		printf("file is deleted");
	}


}

main()
{
	int choice,res;
	printf("menu:1.create\n2.list all files \n delete a file");
	while(1)
	{
		printf("enter ur choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			create();
			break;
		case 2:
			listallfiles();
			break;
		case 3:
			deletefile();
			break;
		case 4:
			fflush(stdin);
			exit(0);

		}

	}

}
