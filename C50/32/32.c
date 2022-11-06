#include<stdio.h>
int main()
{
	int n,g,s,b,i;
	scanf("%d",&n);
	g=n%10;
	s=n%100/10;
	b=n/100;
	while(b--)
		printf("B");
	while(s--)
		printf("S");
	for(i=1;i<=g;i++)
		printf("%d",i);
}
