#include<stdio.h> 
#include<stdlib.h>

struct md
{
	char fname[20];
	int start_index;
	int size;
	int cr_time;
};

int create_file(FILE *ftr,struct md *t)
{
	int i,val;
	FILE *ptr;
	char c,dummy[10];
	ftr=fopen("disk4","r+");
	rewind(ftr);
	for(i=0;i<10;i++)
	{
		ptr=ftr;
		c=fgetc(ptr);
		printf("%c\n",c);
		if((c)!='0')
		{
			fseek(ftr,sizeof(struct md),SEEK_CUR);

		}
		else
		{
			val=ftell(ptr);
			printf("\n%d\n",val);
			scanf("%s",t->fname);
			fwrite(t,sizeof(struct md),1,ftr);
			val=ftell(ftr);
			printf("\n%d\n",val);
			fclose(ftr);
			return 0;
		}

	}
	return 1;
}

main()
{
	FILE *ftr=NULL;
	struct md *t;
	int pos,choice;
	t=(struct md *)malloc(sizeof(struct md));
	printf("Menu: 1.create\n2.exit");
	while(1)
	{
		printf("enter ur choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
		printf("enter name");
		scanf("%s",&t->fname);
		printf("enter size");
		scanf("%d",&t->size);
		t->size+=t->size%4;
		pos=create_file(ftr,t);
		if(pos==0)
			printf("file created");
		else 
			printf("file not created");
		break;
		case 2:
			exit(0);
	}
	}
		getch();
}
