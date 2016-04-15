#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct controlfile
{
	int id1;
	int id2;
	char msg[10];
	int flag;
};

void main()
{
	//int *bit_vect=(int *)calloc(5,sizeof(int));
	int n,ch,id2;
	struct controlfile *head=NULL,*temp=NULL,*temp1=NULL;
	printf("\n enter id:");
	scanf("%d",&n);
	printf("\n choice:read(0)/write(1) data to file??");
	scanf("%d",&ch);
	temp=(struct controlfile *)calloc(1,sizeof(struct controlfile));
	if(ch==1)
	{
		FILE *fp=fopen("D:\\multiclient_controlfile","w"); 
		char *msg;
		msg=(char *)calloc(20,sizeof(char));
		fflush(stdin);
		printf("\n enter data you want to write");
		scanf("%[^\n]s",msg);
		//gets(msg);
		//getline(msg,10,stdin);
		if(head==NULL)
		{
			temp->id1=n;
				id2=msg[strlen(msg)-1]-'0';
				temp->id2=id2;
				strcpy(temp->msg,msg);
				temp->flag=0;
				head=temp;
			}
		printf("%s\t %d",temp->msg,temp->id2);
		fprintf(fp,"%d:",n);
		fputs(msg,fp);
		fflush(fp);
		fclose(fp);
		}	
	else
	{
		temp=head;
		FILE *fp=fopen("D:\\multiclient_controlfile","r");
		/*while(feof(fp)==0)
		{
			char x=getc(fp);
			printf("%c",x);

		}*/
		int k=0;
		while(temp!=NULL)
		{
			if(temp->id2==n)
			{
					printf("%s",temp->msg);
					temp->flag=1;
					k=1;
			}
		}
		if(k==0)
		printf("\n you dont have any messages:");
        fclose(fp);

	}
	_getch();
	
}
