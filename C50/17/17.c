#include<stdio.h>
int main()
{
	int a = 0, b = 10000,fir,sec,z=0,counter=0,prime[3000];
	scanf("%d %d",&fir,&sec);
	for (int i = a; i <=b; i++)
	{
		if (i==2)
		{
			prime[counter]=i;
			counter++;
		}
		for (int j=2; j<10000; j++)
		{
			if (i%j==0)
			{
				break;
			}
			else if (j==i-1)
			{
				prime[counter]=i;
                counter++;
			}
		}
	}
for ( int i = 0; i < counter; i++)
{
    if(i>=fir&& i<=sec){
        if(fir==0&&sec==1){
            printf("%d",prime[i]);
            z++;
            break;}
        if(i==0){
            continue;
        }
        if(z==0){
            printf("%d ",prime[i-1]);
            z++;
        }else if(i==sec){
            printf("%d\n",prime[i-1]);
        }
        else if(z++,z%10!=0){
            printf("%d ",prime[i-1]);
        }else{
            printf("%d\n",prime[i-1]);
        }
    }
}

	return 0;
}
