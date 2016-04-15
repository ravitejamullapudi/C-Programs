//copy one file to another file
#include<stdio.h>
#include<stdlib.h>

main()
{
	FILE *ftr1,*ftr2;
	char file1[20],file2[20];
	char c,buffer[50];
	int j;
	printf("enter file name to copy");
	scanf("%s",file1);
	ftr1=fopen(file1,"rb");
	if(ftr1==NULL)
	{
		printf("the file doesnot exists");
		getch();
		return;
	}
	printf("enter file name to create");
	scanf("%s",file2);
	ftr2=fopen(file2,"wb");
	j=fread(&c,sizeof(char),1,ftr1);
	fflush(stdin);
	while(!feof(ftr1))//j==1
	{
		fwrite(&c,sizeof(char),1,ftr2);
		fflush(stdin);
		j=fread(&c,sizeof(char),1,ftr1);
	}
	printf("file is copied");
	fflush(ftr2);
	fcloseall();
	getch();
}
