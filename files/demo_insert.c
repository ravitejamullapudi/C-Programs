//append data to a file

#include<stdio.h>
#include<stdlib.h>

main()
{
	FILE *ftr=NULL;
	char c;
	int i;
	ftr=fopen("demoinsert.txt","a");
	while(1)
	{
		printf("enter data");
		c=getchar();
		while(c!='\n')
		{
			fputc(c,ftr);
			c=getchar();
		}
		fputc(c,ftr);
		printf("add more data ?? y or n");
		c=getchar();
		if(c=='n')
			break;
		fflush(stdin);
	}
	getch();

}
