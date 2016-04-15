#include<stdio.h>
#include<stdlib.h>
struct md
{
	char fname[20];
	int size;
	int start_index;
	int time;
};
void create()
{
	FILE *ftr;
	struct md t;
	int res;
	char c;
	printf("enter name size");
	scanf("%s%d",t.fname,&t.size);
	printf("%s\n",t.fname);
	t.size+=t.size%4;
	ftr=fopen("file_8mb","w");
	res=fseek(ftr,0L,SEEK_SET);
	if(res!=0)
	{
		printf("some error");
		return;
	}
	else
	{
		c=fgetc(ftr);
		printf("%c",c);
		if(c=='\0')
		{
			res=fseek(ftr,-1,SEEK_CUR);
			if(res==0)
			{
				fwrite(&t,sizeof(t),1,ftr);

			}

		}

	}
	fclose(ftr);
}

main()
{
	
		int choice;
		printf("menu : 1.create\n2.insert\n3.exit");
		while(1)
		{
			printf("\nenter ur choice");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				create();
				break;
			}

		}

	


}
