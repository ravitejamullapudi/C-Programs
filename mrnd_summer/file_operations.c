#include<stdio.h>
struct md
{
	char fname[20];
	int size;
	int cre_time;
	int start_index;
};
FILE * create_8mb(FILE *ftr)
{
	long long int i,j;
	char c='0';
	for(i=0;i<8*1024;i++)
	{
		for(j=0;j<1024;j++)
		{
			fputc(c,ftr);
		}

	}
	return ftr;
}
int md_create(char *name,FILE *ftr)
{
		long long int i,pos;
		while(name[i]!=NULL)
		{
			fputc(name[i],ftr);
		}
		pos=fseek(ftr,16,SEEK_SET);
		putw(4*1024,ftr);
		return 0;
}

int create_file(char *name,FILE *ftr)
{
	char c;
	int i=0;
	long long int pos;
	FILE *ptr1,*ptr2;
	 rewind(ftr);
	ptr1=ftr;
	
	if((c=getc(ftr)=='0'))
	{
		rewind(ftr);
		 
		return 0;
	}
	else
	{
		rewind(ftr);
		pos=search(name,ftr);
	
		if(pos!=1)
		{
			rewind(ftr);
			pos=fseek(ftr,pos,SEEK_SET);
			if((c=fgetc(ftr))=='0')
				return 1;
			pos=ftell(ftr);
			pos=fseek(ftr,pos-1,SEEK_SET);


		}

	}


}

main()
{
	FILE *ftr;
	char c;
	int i,choice,res;
	char fname[20];
	ftr=fopen("file_8mb","a");
	ftr=create_8mb(ftr);
	printf("Menu:\n1.create a file\n2.insert into file\n3.format a file\n4.delete a file\n5.display file\n6.exit,search");

	while(1)
	{
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("enter file name to create");
				scanf("%s",fname);
				res=create_file(fname,ftr);
				if(res==0)
					printf("file is created");
				else 
					printf("file name exists");
				break;
		case 2:
			printf("enter file name");
			scanf("%s",fname);
			res=insert(fname,ftr);
			if(res==0)
				printf("insertd");
			else 
				printf("file does not exists");
			break;
		case 3:
			printf("enter file name");
			scanf("%s",fname);
			res=format(fname,ftr);
			if(res==0)
				printf("format");
			else 
				printf("file does not exists");
			break;
		case 4:
			printf("enter file name");
			scanf("%s",fname);
			res=delete_file(fname,ftr);
			if(res==0)
				printf("deletd");
			else 
				printf("file does not exists");
			break;
		case 5:
			printf("enter file name");
			scanf("%s",fname);
			res=display(fname,ftr);
			if(res!=0)
				printf("file name does not exists");
			break;
		case 5:
			exit(0);
		}

	}


}
