#include<stdio.h>
#include<stdlib.h>

char * arr(char *);
void display(char *);
void itooa(char *,int *,int *,int *);
main()
{
	char *str,*res;
	int n;
	scanf("%d",&n);
	str=(char *)malloc(n);
	scanf("%s",str);
	res=arr(str);
	display(res);


getch();

}

char * arr(char *str)
{
	int count=1,i=1,j=1,a1,a2;
	while(*(str+i)!=NULL)
	{
		if(*(str+i-1)==*(str+i))
		{
			count++;
		}
		else if(count==1)
		{
			*(str+j)=*(str+i);
			j++;
		}
		else
		{
			if(count<9)
			{
			*(str+j)=count+'0';
			j++;
			*(str+j++)=*(str+i);
			}
			else
			{
			a2=count%10;
			count=count/10;
			a1=count%10;
			*(str+ j++)=a1+'0';
			*(str+ j++)=a2+'0';
			*(str+j++)=*(str+i);

			}
			count=1;
		}
		i++;
	}

	if( count>1&&count<9)
		*(str+j++)=count+'0';
	if(count>9)
	{
		a2=count%10;
			count=count/10;
			a1=count%10;
			*(str+ j++)=a1+'0';
			*(str+ j++)=a2+'0';
			*(str+j++)=*(str+i);
	}

	
	*(str+j)=NULL;
	return str;

}

void display(char *str)
{
	printf("%s",str);
}
 
void itooa(char *str,int *count,int *j,int *i)
 {
	  char a1,a2;
	  int k,l;
	  k=*count%10;
	  a2=k+'0';
	  k=*count/10;
	  a1=k%10;
	  *(str+ *j)=a1+'0';
	 *j++;
	  *(str+ *j)=a2;
	  *j++;
	  *(str+ *j)=*(str+ *i);
	  *j++;
 }
