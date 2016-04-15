#include<stdio.h>
#include<stdlib.h>
struct nam
{
	int len;
	char s[100];
	char o[100];
};
char * casechange(char *str)
{
	int i=0;
	//printf("ravi1");
	while(*(str+i)!='\0')
	{
		if(*(str+i)>='a'&&*(str+i)<='z')
			*(str+i)=*(str+i)-32;
		else 
			*(str+i)=*(str+i)+32;
		i++;
	}
	return str;
}

void test(struct nam arr[],int l)
{
	int i=0,j=0;
	char *res;
	for(i=0;i<l;i++)
	{
		res=(char *)malloc(sizeof(char )*(arr[i].len+1));
		for(j=0;j<arr[i].len;j++)
			res[j]=arr[i].s[j];
		res[j]='\0';
		//printf("%s",res);
		res=casechange(res);
		//printf("ravi");
		for(j=0;j<arr[i].len;j++)
		{
			if(*(res+j)==arr[i].o[j]);
			else
			{
				printf("failed\n");
				break;
			}

		}
		if(j==arr[i].len)
		printf("passed\n");
	}

}

main()
{
	struct nam arr[3]={{4,"peri","PERI"},{4,"raVi","RAvI"},{3,"naG","NAg"}};
	//printf("hello");
	test(arr,3);
	//printf("end");
	getch();

}
