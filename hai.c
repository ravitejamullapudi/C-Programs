#include <stdio.h>
#include<conio.h>
#define MX 13
#define NS 715
 
int n, se[NS], pi[NS], pm[NS], cu;
char pu[MX+1];
const int bi[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
const int mo[6][7]={{10,12,9,6,4,7,10},{10,7,4,6,9,12,10},{5,3,6,9,11,8,5},{5,8,11,9,6,3,5},{4,6,3,1,0,2,4},{4,2,0,1,3,6,4}};
const int go=0x258;
 
int f1(int m, int p)
{
int c=p, i=0;
for(; i++<6; c=((p&bi[mo[m][i]]))?(c|bi[mo[m][i-1]]):(c&(~bi[mo[m][i-1]])));
return c;
}
 
int f2(int c)
{
int i;
for(i=cu-1; i>=0; i--)
	if(c==se[i])
		return i;
return -1;
}
 
int f3(char p[])
{
int i=0, s=0;
for(; i<MX; s=(p[i]=='1')?(s|bi[MX-i-1]):s, i++);
return s;
}
 
void f4(int s)
{
int i=0, j, p[12], in=f2(s);
for(; in; p[i++]=pm[in], in=pi[in]);
for(printf("%d\n",i+(j=0)); j++<i; printf("%d %d\n",(p[j-1]>>1),(p[j-1]%2)));
}
 
main()
{
int fall, p=0, m, c;
 
for(se[!(cu=1)]=go; p<cu; p++)
	for(m=0; m<6; m++)
		if(f2(c=f1(m,se[p]))==-1)
			{
			se[cu]=c;
			pi[cu]=p;
			pm[cu++]=m^0x1;
			}
for(scanf("%d",&fall); fall--;)
	{
	scanf("%s",pu);
	f4(f3(pu));
	}
 
getch();
}