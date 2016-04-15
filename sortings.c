//3. given an array of size N, allocate, read values and write sorting function.
//write as many sort algorithms as you know

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void display(int ,int*);
int * bubsort(int ,int*);

main1()
{
	int i,len,*str,*res;

	printf("enter the size of the  array");
	scanf("%d",&len);
	str=(int * )malloc(len*sizeof(int));
	printf("enter the elements");
	for(i=0;i<len;i++)
	{
		scanf("%d",str+i);
	}
	res=bubsort(len,str);
	display(len,res);
	getch();
}
void display(int len,int *res)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%4d",*(res+i));
	}
}

int * bubsort(int len,int *str)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=1;j<len-i;j++)
		{
			if(*(str+j)<*(str+j-1))
			{
				*(str+j)+=*(str+j-1);
				*(str+j-1)=*(str+j)-*(str+j-1);
				*(str+j)=*(str+j)-*(str+j-1);
			}
		}
	}
}