#include<stdio.h>
#include<stdlib.h>

main()
{
	int w=0,l=0,chara=0;
	FILE *ftr;
	char c;
	ftr=fopen("demoinsert.txt","r");
	c=fgetc(ftr);
	while(c!=EOF)
	{
		printf("%c",c);
		if(c=='\n')
		{
			l++;
			w++;
			if(l%2==0)
			{
				printf("press enter to display next two lines ");
				c=getchar();
				if(c=='\n')
				{
					fflush(stdin);
					c=fgetc(ftr);
					continue;
				}
				else 
					break;

			}

		}
		if(c==' ')
			w++;
		chara++;
		fflush(stdin);
		
		c=fgetc(ftr);
	}
	printf("%d lines, %d words, %d characters",l,w,chara);
	getch();
}
