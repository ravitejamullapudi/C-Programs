#include<stdio.h>
#include<stdlib.h>

main()
{
	int n,*arr,i,l,r,k;
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	scanf("%d%d",&l,&r);
	if(l<0)
		l=0;
	if(r>=n)
		r=n-1;
	if(l>=n||r<0)
	{
		printf("no elements");
		return;
	}
	for(k=r+1;k<n;k++)
	{
		*(arr+k-r+l-1)=*(arr+k);
	}
	*(arr+k)='\0';
	for(i=0;i<k-r+l-1;i++)
		printf("%d",*(arr+i));
	getch();
	 

}
