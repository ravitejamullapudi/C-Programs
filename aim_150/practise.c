#include<stdio.h>
void to_fun(char *a)
{
	a[2]='r';
}

main()
{
	char a[10];
	scanf("%s",a);
	printf("%s\n",a);
	to_fun(a);
	printf("%s",a);
	getch();
}
