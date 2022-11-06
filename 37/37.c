#include <string.h>
#include <math.h>
int main()
{
	int n,m;
	scanf("%d",&n);/*学生数*/
	char a[1000][20];/*考生号*/
	int b[1000],c[1000],r[1000];/*机试座位号、考场座位号、要查询的机试座位号*/
	for(int i=0;i<n;i++)
	{
		scanf("%s %d %d",a[i],&b[i],&c[i]);/*录入考生信息*/
	}
	scanf("%d",&m);/*录入要查询的机试座位号个数*/
	for(int j=0;j<m;j++)
	{
		scanf("%d",&r[j]);/*录入要查询的机试座位号*/
		for(int i=0;i<n;i++)
		{
			if(r[j] == b[i])/*找到这个考生并输出他的考生号和考场座位号*/
			printf("%s %d\n",a[i],c[i]);
		}
	}
}
