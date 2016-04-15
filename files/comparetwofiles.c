#include<stdio.h>
#include<stdlib.h>

main()
{
	FILE *ftr1=NULL,*ftr2=NULL;
	char c1,c2;
	ftr1=fopen("demoinsert.txt","r");
	ftr2=fopen("demoinsert1.txt","r");
	if(!ftr1||!ftr2)
		printf("error in opening files");
	else 
	{
		while(1)
		{
			c1=fgetc(ftr1);
			c2=fgetc(ftr2);
			if(c1==c2)
			{
				if(c1==EOF)
				{
					printf("two files are same");
					break;
				}
				continue;
			}
			else
			{
				printf("two files are not same");
				break;
			}

		}

	}
	getch();
}
