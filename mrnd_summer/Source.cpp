#include <stdio.h>
#include<stdlib.h>
struct s
{
	char *a;
};

struct b
{
	char *c;
};


void main()
{
	struct s *abc;
	struct b *cde;
	char *rvi;
	rvi=(char *)malloc(sizeof(char));
	abc=(struct s *)malloc(sizeof(struct s));
	cde=(struct b *)malloc(sizeof(struct b));
	*rvi='t';
	abc->a=rvi;
	cde->c=&(abc->a);

	printf("%c",*(cde->c))
}