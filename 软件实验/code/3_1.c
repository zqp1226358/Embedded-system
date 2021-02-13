#include<stdio.h>
extern void strswap(char *d,const char *s);

int main()
{
	const char *srcstr="old";
	char *dststr="new";
	printf("Before swaping:\n");
	printf("%s\n %s\n",srcstr,dststr);
	strswap(dststr,srcstr);
	printf("After swaping:\n");
	printf("%s\n %s\n",srcstr,dststr);
	return (0);
}
