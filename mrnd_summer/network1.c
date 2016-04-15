//client
#include<stdio.h>
#include<stdlib.h>

main()
{
	FILE *ftr,*ptr;
	char buffer[100],c;

	ftr=fopen("buffer.txt","r+");
	if(ftr==NULL)
	{
		printf("error in opening file");
		return ;
	}
	fputc('a',ftr);
	fseek(ftr,0,0);
	while((c=fgetc(ftr)!=EOF))
		printf("hi");
	printf("hello");

	getch();

}



