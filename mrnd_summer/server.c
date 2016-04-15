#include<stdio.h>
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
void str_cpy(char *str1,char *str2)
{
	int i=0;
	 while(str2[i]!='\0')
	 {
		 str1[i]=str2[i];
		 i++;
	 }
	 str1[i]='\0';
}

main()
{
	char buffer[100],c;
	int i,res,flag=0,key=0;
	FILE *ftr,*ptr;
	printf("server\n");
	ftr=fopen("E:\\buffer1.txt","w");
	fputc('+',ftr);
	fclose(ftr);
	ftr=fopen("E:\\buffer1.txt","r+");
	c=fgetc(ftr);
	while(1)
	{
		if(c!=EOF&&c!='+')
		{
			if(flag==0)
			{
			
			flag=1;

			while(c!='+')
			{
				buffer[i]=c;
				c=fgetc(ftr);
				i++;
			}
			buffer[i]='\0';
			
			
			i=0;
			printf("\nClient :");
			puts(buffer);
			fflush(stdin);
			res=fseek(ftr,-1,1);
			if(res!=0)
				return;
			i=0;
			printf("you:");
			if(str_cmp(buffer,"ack")==0)
			{
				buffer[0]='\0';
			}
			if(str_cmp(buffer,"syn")==0)
			{
				str_cpy(buffer,"synack");
			}
			else
			{
			scanf("%c",&c);
			while(c!='\n')
			{
				buffer[i]=c;
				scanf("%c",&c);
				i++;
			}
			buffer[i]='\0';
			}
			i=0;
			while(buffer[i]!='\0')
			{
				fputc(buffer[i],ftr);
				i++;
			}
			i=0;
			fputc('+',ftr);
			fflush(stdin);
			
			}
			else
			{
				fseek(ftr,-1,1);
				c=fgetc(ftr);
			}
		}
		else
		{
			flag=0;
			res=fseek(ftr,-1,1);
			if(res==0)
			{
				c=fgetc(ftr);
				i=0;
			}

		}
	}

	getch();
}
