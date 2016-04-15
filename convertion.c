//1. write print_number_hex, print_number_octal, print_number_dec.
//these three take binary number string as input and do printing.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int print_number_dec(char *);
int print_number_octal(char *); 
void print_number_hex(char *);
void dec_hexa(int);
main()
	
{
	int val,n;
	char *str;

	printf("enter the no of elements");
	scanf("%d",&n);
	str=(char *)malloc(sizeof(char)*n);
	printf("enter the string");
	scanf("%s",str);
	val=print_number_dec(str);
	printf("%d\n",val);
	val=print_number_octal(str);
	printf("%d\n",val);
	print_number_hex(str);
	getch();

}

int print_number_dec(char *str)
{
	int i=0,dec=0,n;
	
	while(*(str+i)!=NULL)
	{
		n=*(str+i)-'0';
		dec=dec*2+n;
		i++;
	}
	return dec;
}

 int print_number_octal(char *str)
 {
	 int dec,octal=0,rem,t=1;
	 dec=print_number_dec(str);
	 while(dec>0)
	 {
		 rem=dec%8;
		 dec=dec/8;
		 rem=rem*t;
		 t=t*10;
		 octal=octal+rem;

	 }
	 return octal;


 }
 void print_number_hex(char *str)
{
	int dec;
	dec=print_number_dec(str);
	dec_hexa(dec);
}

void dec_hexa(int value)
{
	int rem,ascii;
	char ch;
	if(value==0)  return;
	rem=value%16;
	if(rem>=0&&rem<=9)
	{
		ascii=rem+'0';
		ch=ascii;
	}
	else if(rem>=10&&rem<=15)
	{
		ascii=rem+'0';
		ch=ascii+7;
	}
	dec_hexa(value/16);
	printf("%c",ch);
	
}

