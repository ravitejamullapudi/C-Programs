#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int v1,v2;
	char s1[30], s2[30];
	struct node *next;
};
struct te
{
	int val1,val2;
	char str1[30],str2[30];
};
struct test
{
	int n;
	struct te input;
	struct te output;
}testDB[]={{}};
