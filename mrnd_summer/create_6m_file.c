#include<stdio.h>

main()
{
	FILE *ftr;
	long long int i,j;
	char c,name[]={'D','i','s','k'};
	ftr=fopen("disk4","a");
	for(i=1;i<=10;i++)
	{
		for(j=0;j<10;j++)
		{
			fputc('0',ftr);
		}

	}
	fputc('\0',ftr);
	fclose(ftr);
	ftr=fopen("disk1","r");
	
	while((c=fgetc(ftr))!='\0')
		printf("%c",c);
	fclose(ftr);
	printf("\n%d\n%d",i,j);
	getch();
}

