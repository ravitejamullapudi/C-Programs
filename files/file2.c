#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	char buffer[100];
	char c;
	int len,count=0;
	FILE *ftr;
	for(len=0;len<100;len++)
	{
		buffer[len]='\0';
	}
	ftr=fopen("file3.txt","w");
	fflush(ftr);
	printf("%d\n",feof(ftr));
	len=fseek(ftr,10,SEEK_END);
	printf("seek=%d\n",len);
	printf("%d\n",feof(ftr));
	printf("enter data ");
	scanf("%s",buffer);
	
	fwrite(buffer,100,1,ftr);
	printf("enter second data");
	scanf("%s",buffer);
	fwrite(buffer,100,1,ftr);
	fclose(ftr);
	ftr=fopen("file3.txt","r");
	printf("%d\n",feof(ftr));
	while(count<2)
	{
		/*c=fgetc(ftr);
		if((c)!=NULL)
		printf("%c",c);*/
		fread(buffer,sizeof(buffer),1,ftr);
		printf("%d\n",feof(ftr));
		printf("%s\n",buffer);
		count++;
		fseek(ftr,sizeof(buffer)*count,SEEK_SET);
		printf("%d\n",feof(ftr));
			
		
	}
	printf("%d\n",ftell(ftr));
	printf("%d\n",feof(ftr));
	count++;
	fseek(ftr,sizeof(buffer)*count,SEEK_SET);
	printf("%d\n",ftell(ftr));
	printf("%d\n",feof(ftr));	
	fclose(ftr);
	getch();
}
