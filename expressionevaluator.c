#include<stdio.h>
#include<stdlib.h>
struct exp * expeval(char *,struct exp *);
void display(struct exp *);
struct exp 
{
	int val;
	char alpha;
};


main()
{
	char *ptr,str[100];
	struct exp *arr,*res;
	ptr=str;
	arr=(struct exp *)malloc(sizeof(struct exp)*26);
	arr->alpha=NULL;
	while(1)
	{
		printf(">");
		scanf("%s",ptr);
		res=expeval(ptr,arr);
		display(res);

	}
	getch();

}

struct exp * expeval(char *str,struct exp *arr)
{
	int i=0,j,value=0,flag=1,value1=0,k=0,temp1=0;
	char temp=*str;
	while((arr+i)->alpha!=NULL)
	{
		if(temp==(arr+i)->alpha)
		{
			temp1++;
			k=i;
			break;
		}
		i++;

	}
	if(temp1==0)
	{
	(arr+i++)->alpha=temp;
	(arr+i)->alpha=NULL;
	k=i-1;
	}
	else
	k=i;

	

	for(i=2;*(str+i)!=NULL;i++)
	{
		if(*(str+i)>='a'&&*(str+i)<='z')
		{j=0;
			while((arr+j)->alpha!=NULL)
			{
				if((arr+j)->alpha==*(str+i))
				{
					if(flag==1)
					value+=(arr+j)->val;
					else
						value-=(arr+j)->val;
					break;
				}
				j++;
			}

		}
		else if(*(str+i)=='+')
		{
			flag=1;
		}
		else if(*(str+i)=='-')
			flag=0;
		else 
		{j=i;
			value1=0;
			while(*(str+j)!='+'&&*(str+j)!='-'&&*(str+j)!=NULL)
			{
				value1 *=10;
				value1=*(str+j)-'0';
				
				j++;
			}
			i=j-1;
			if(flag==1)
			value+=value1;
			else
				value-=value1;

		}


	}


	(arr+k)->val=value;
	return arr;
}


 void display(struct exp *arr)
 {
	 int i=0;
	 printf(">");
	 while((arr+i)->alpha!=NULL)
	 {
		 printf("%c=%d",(arr+i)->alpha,(arr+i)->val);
		 printf(",");
		 i++;
	 }

	 printf("\n");
 }
