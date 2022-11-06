#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int match[100][4];
	int countera=0, counterb=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<4; j++)
		{
			scanf("%d", &match[i][j]);
		}
	}
	for(int k=0; k<N; k++)
	{
	
			if(match[k][0]+match[k][2] == match[k][1] && match[k][0]+match[k][2] != match[k][3])
			{
				counterb++;
			}
			if(match[k][0]+match[k][2] != match[k][1] && match[k][0]+match[k][2] == match[k][3])
			{
				countera++;
			}

	}
	printf("%d %d", countera, counterb);
	return 0;
}

