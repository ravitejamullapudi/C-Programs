#include<stdio.h>
#include<stdlib.h>

struct md
{
	char fname[28];
	int size;
};
void create()
{
	FILE *ftr=NULL;
	int i=0,size;
	struct md t;
	char name[28];
	printf("enter name and size");
	scanf("%s%d",name,&size);
	t.size=size;
	while(name[i]!='\0')
	{
		t.fname[i]=name[i];
		i++;
	}
	t.fname[i]='\0';
	ftr=fopen("ravi4","wb");

	while(feof(ftr)!=0)
	{
		fseek(ftr,sizeof(struct md),SEEK_CUR);
	}
	fwrite(&t,sizeof(struct md),1,ftr);
	fclose(ftr);
}
void display()
{
	FILE *ftr;
	struct md t;
	ftr=fopen("ravi4","r");
	while(feof(ftr)==0)
	{
	fread(&t,sizeof(struct md),1,ftr);
	printf("%s\n",t.fname);
	printf("%d",t.size);
	fseek(ftr,sizeof(struct md),SEEK_CUR);
	}
	fclose(ftr);

}

main()
{
	
	char c;
	int choice;
	printf("menu : 1.create\n2.exit\n3.display");
	while(1)
	{
		printf("enter ur choice");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			exit(0);
		case 3:
			display();
			break;
		}
	}


	getch();

}
