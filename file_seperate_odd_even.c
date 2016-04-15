#include<stdio.h>

void main()
{
	int num,n,i;
	FILE *fp,*fpeven,*fpodd;
	fp=fopen("num","w");
	printf("enter no of elemnts");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		putw(num,fp);
	}
	fclose(fp);
	fp=fopen("num","r");
	fpeven=fopen("even","w");
	fpodd=fopen("odd","w");
	for(i=0;i<n;i++)
	{
		num=getw(fp);
		if(num%2==0)
			putw(num,fpeven);
		else
			putw(num,fpodd);

	}
	if(feof(fpeven))
		printf("end of data ");
	fclose(fp);
	fclose(fpeven);
	fclose(fpodd);
	fpeven=fopen("even","r");
	fpodd=fopen("odd","r");

	printf("the even numbers are");

	while((num=getw(fpeven))!=EOF)
	{
	printf("%d\n",num);

	}
	printf("the odd numbers are");
	i=0;
	while(i<10)
	{
		num=getw(fpodd);
	printf("%d\n",num);
	if(ferror(fpodd))
		printf("error has there");
	i++;
	}
	if(feof(fpeven))
		printf("end of data ");

	getch();
}
