#include<stdio.h>
#include<stdlib.h>
struct nam
{
	int len;
	char s[100];
	char o[100];
};
char * removeupper(char *str)
{
	int i=0,j=0;
	//printf("ravi1");
	while(*(str+i+j)!='\0')
	{
		if(*(str+i)>='A'&&*(str+i)<='Z')
		{
			j++;
			*(str+i)=*(str+i+j);
			//printf("%s",str);
		}
		else
		{i++;
		}
	}
	*(str+i)='\0';
	//printf("%s",str);
	return str;
}

void test(struct nam arr[],int l)
{
	int i=0,j=0,k=0;
	char *res;
	for(i=0;i<l;i++)
	{
		res=(char *)malloc(sizeof(char )*(arr[i].len+1));
		for(j=0;j<arr[i].len;j++)
			res[j]=arr[i].s[j];
		res[j]='\0';
		//printf("%s",res);
		res=removeupper(res);
		//printf("ravi");
		for(j=0;*(res+j)!=NULL;j++)
		{
			if(*(res+j)==arr[i].o[j])
				;
			else
			{
				printf("failed\n");
				k=1;
				break;
			}

		}
		if(k==0)
		printf("passed\n");
		free(res);
	}

}

main()				
{
	struct nam arr[10]={{4,"peri","peri"},
						{4,"raVi","rai"},
						{3,"naG","na"},
						{5,"11011","11011"},
						{5,"RAVIT",NULL},
						{1," "," "},
	{2,"\0","\0"},{4,"123R","123"},{10,"&%6R*((8AB","&%6*((8"},{8,"1.2T.3.r","1.2.3.r"}
							};
	//printf("hello");
	test(arr,10);
	//printf("end");
	getch();

}
