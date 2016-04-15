#include<stdio.h>
#include<stdlib.h>

struct student
{
	char rno[15];
	char name[20];
	char marks[4];
	char address[50];
};
/*struct student * getNode()
{
	struct student *st;
	st=(struct student *)malloc(sizeof(struct student ));
	return st;

}*/
void create_data()
{
	struct student st;
	FILE *fp;
	int res;
	fp=fopen("dbfile.txt","a");
	if(fp==NULL)
		fp=fopen("dbfile.txt","w");
	printf("enter roll no ");
	scanf("%s",st.rno);
	fflush(stdin);
	printf("enter name");
	scanf("%[^\n]s",st.name);
	fflush(stdin);
	printf("enter marks");
	scanf("%s",st.marks);
	fflush(stdin);
	printf("enter address");
	scanf("%[^\n]s",st.address);
	res=fwrite(&st,sizeof(struct student),1,fp);
	if(res==1)
	{
		printf("record inserted successfully\n");
		
	}
	else
	{
		printf("error in record insertion\n");
		return;
	}
	fflush(stdin);
	//fflush(fp);
	fclose(fp);
}

void display_data()
{
	struct student st;
	int res;
	FILE *fp;
	fp=fopen("dbfile.txt","r");
	if(fp==NULL)
	{
		printf("error in opening file\n");
		return ;
	}
	while(1)
	{
		res=fread(&st,sizeof(struct student),1,fp);
		if(res!=1)
			return;
		printf("%s\t%s\t%s\t%s\n",st.rno,st.name,st.marks,st.address);
	}
	fclose(fp);
}

main()
{
	int choice;
	printf("Menu : 1.insert\n2.display\n3.exit\n");
	while(1)
	{
		printf("enter ur choice\n ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			create_data();
			break;
		case 2:
			display_data();
			break;
		case 3:
			exit(0);

		}

	}

}




