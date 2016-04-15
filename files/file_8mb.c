#include<stdio.h>

main()
{
	long long int i,j;
	FILE *ftr=NULL;
	char buffer[512*1024];
	ftr=fopen("file_8mb4.txt","wb");
	
	for(i=0;i<512*1024;i++)
	{
		buffer[i]='0';
	}
	for(i=0;i<16;i++)
	{
		fwrite(buffer,512*1024,1,ftr);
	}
	fclose(ftr);
	getch();
}
