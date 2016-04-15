#include<stdio.h>
#include<stdlib.h>
void print_lines(int);
void print_values(int *,int,int,int);
void display(int *,int,int);
int removeone(int *,int ,int,int,int);
main()
{
	int *arr,i,row,col,j,res;
	printf("enter no of rows and cols");
	scanf("%d%d",&row,&col);
	if(row<=0||col<=0)
	{
		printf("enter correct value");
		
	}
	else{
	arr=(int *)malloc(sizeof(int)*row*col);
	printf("enter elements");

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		scanf("%d",arr+i*row+j);
		}
	}
	printf("\n");
	display(arr,row,col);
	res=removeone(arr,0,0,row,col);
	if(res==1)
	display(arr,row,col);
	
	}
	
	getch();
}
 
int  removeone(int *arr,int row_len,int col_len,int row,int col)
{
	int flag=0;
	if(row_len<0||col_len<0)
		return 0;
	 if(row_len==row-1&&col_len==col-1)
	 {
		 if(*(arr+row_len*row+col_len)==1)
		 {
			 *(arr+row_len*row+col_len)=2;
			 return 1;
		 }
		 else
			 return 0;
	 }
	 else 
	 {
		 if(*(arr+row_len*row+col_len)==1)
		 {
			flag=removeone(arr,row_len,col_len+1,row,col);
			if(flag==1)
			{
				*(arr+row_len*row+col_len)=2;
				return 1;
			}
			else 
			{
				*(arr+row_len*row+col_len)=1;
				flag=removeone(arr,row_len+1,col_len,row,col);
				if(flag==1)
				{
				*(arr+row_len*row+col_len)=2;
				return 1;
				}
				else 
				{
					 
					flag=removeone(arr,row_len-1,col_len,row,col);
						if(flag==1)
						{
						*(arr+row_len*row+col_len)=2;
						return 1;
						}
						else return 0;
				
				}


			}			

		 }
		 else return 0;
	 }


}


void display(int *arr,int row,int col)
{
	int i;
	print_lines(col);
	for(i=0;i<row;i++)
	{
	
	print_values(arr,row,col,i);
	print_lines(col);
	}
}
void print_lines(int n)
{
	int i;
	for(i=0;i<4*n+1;i++)
		printf("-");
	printf("\n");
}

void print_values(int *arr,int row,int col,int rowth)
{
	int i;
	printf("|");
	for(i=0;i<col;i++)
		printf(" %d |",*(arr+row*rowth+i));
	printf("\n");

}

