#include<stdio.h>

main()
{
	FILE *ftr,*ptr;
	int i=0,res,flag=0;
	char buffer[100],c;
	printf("client\n");
	ftr=fopen("buffer1.txt","r+");
	c=fgetc(ftr);
	while(1)
	{
		if(c=='+')
		{
			if(flag==0)
			{
			res=fseek(ftr,-1,1);
			if(res==0)
			{
		printf("You:");
		scanf("%c",&c);
		while(c!='\n')
		{
			buffer[i]=c;
			i++;
			scanf("%c",&c);

		}
		buffer[i]='\0';
		i=0;
		while(buffer[i]!='\0')
		{
			fputc(buffer[i],ftr);
			i++;
		}
		fflush(stdin);
		fputc('+',ftr);
		fseek(ftr,-1,1);
		c=fgetc(ftr);
			}
			 
			}
			else
			{
				res=fseek(ftr,-1,1);
			if(res==0)
			{
				c=fgetc(ftr);
			}

			}


		}
		else
		{
			i=0;
			 while(c!='+')
			 {
				 buffer[i]=c;
				 c=fgetc(ftr);
				 i++;
			 }
			 buffer[i]='\0';
			 puts(buffer);
			 fflush(stdin);
			 fseek(ftr,-1,1);
			 flag=0;
			 c=fgetc(ftr);
			 fflush(stdin);
		}

	}


}
