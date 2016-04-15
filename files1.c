#include<stdio.h>


void main()
{
	char name[20],filename[20];
	FILE *fp;
	int i,marks;
	printf("enter the filename");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	fprintf(stdout,"enter name and marks");
	for(i=0;i<3;i++)
	{
		fscanf(stdin,"%s%d",name,&marks);
		fprintf(fp,"%s%d",name,marks);
	}
	fclose(fp);
	fp=fopen(filename,"r");
	fprintf(stdout,"\n\n now details are");
	for(i=0;i<3;i++)
	{
		fscanf(fp,"%s%d",name,&marks);
		fprintf(stdout,"\n\n%s   %d",name,marks);
	}
	getch();


}
