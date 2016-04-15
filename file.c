#include<stdio.h>

main()
{
	FILE *fp;
	char c;
	fp=fopen("Input","w");
	printf("enter the data into the input file");
	while((c=getchar())!='\n')
		putc(c,fp);
	fclose(fp);
	fp=fopen("Input","r");
	printf(" the data from the file is");
	while((c=getc(fp))!=EOF)
		putchar(c);

	fclose(fp);
	getch();

}
