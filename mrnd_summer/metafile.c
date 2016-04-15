#include<stdio.h>
main()
{
	FILE *ftr;
	long long int i,j;
	char c,name[]={'D','i','s','k'};
	char buffer[512*1024];
	for(i=0;i<512*1024;i++)
		buffer[i]='0';
	ftr=fopen("disk3","a");
	for(i=0;i<16;i++)
	{
		fwrite(buffer,512*1024,1,ftr);
	}

	fclose(ftr);
	ftr=fopen("disk1","r");
	for(i=0;i<16;i++)
	{
		fread(buffer,512*1024,1,ftr);
		for(j=0;j<512*1024;j++)
			printf("%c",buffer[i]);
	}

	fclose(ftr);
	printf("\n%d\n%d",i,j);
	getch();
}

