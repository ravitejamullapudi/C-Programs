#include<stdio.h>
#include<stdlib.h>

float median(int *,int *,int ,int );

main()
{
	int *arr1,*arr2,i,n1,n2;
	float res;
	scanf("%d%d",&n1,&n2);
	arr1=(int *)malloc(n1*sizeof(int));
	arr2=(int *)malloc(n2*sizeof(int));
	for(i=0;i<n1;i++)
		scanf("%d",arr1+i);
	for(i=0;i<n2;i++)
		scanf("%d",arr2+i);
	res=median(arr1,arr2,n1,n2);
	printf("%f",res);
	getch();

}

float median(int *arr1,int *arr2,int n1,int n2)
{
	float res=0;
	 
	int i,j,k;

	k=(n1+n2);
	if(k%2==0)
	{
		if(n1%2==0)
		{
			i=n1/2-1;
			j=n2/2-1;
		}
		else
		{
			i=n1/2;
			j=n2/2;
		}

	}



}
