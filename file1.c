#include<stdio.h>
int main()
{
	FILE *fp;
	char c;
	fp=fopen("INPUT.txt","w");
	while((c=getchar())!='\n')
	{
		putc(c,fp);
	}
	fclose(fp);
	fp=fopen("INPUT.txt","r");
	while((c=getc(fp))!=EOF)
	{
		  putchar(c);
	}
	fclose(fp);
	getch();
	return 0;
}