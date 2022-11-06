#include<stdio.h>
#include<string.h>
float maxx;
int n;
int ts[100];
int data[35*1000*100];
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{

    int i;
    char rt;
    float tmp;
    int k;
    while(scanf("%f %d",&maxx,&n),n)
    {
        k=n;
        maxx=maxx*100;
        memset(ts,0,sizeof(ts));
       int count;
       int l=1;
       while(n--)
       {
            scanf("%d",&count);
            float ws[3];
            float sum=0;
            int flag=1;
            memset(ws,0,sizeof(ws));
            while(count--)
            {
                getchar();
                rt=getchar();
                scanf(":%f",&tmp);
                if(rt=='A'||rt=='B'||rt=='C')
                {
                    ws[rt-'A']+=tmp;
                    sum+=tmp;
                }
                else
                    flag=0;
            }
                if(flag&&ws[0]<=600&&ws[1]<=600&&ws[2]<=600&&sum<=1000)
                {
                ts[l++]=(int)(sum*100);
                }
        }
     memset(data,0,sizeof(data));
     int j;
     for(i=1;i<=k;i++)
     {
         for( j=(int)maxx;j>=ts[i];j--)
         {
            data[j]= max(data[j],data[j-ts[i]]+ts[i]);
         }
     }

     printf("%.2lf\n",1.0*data[(int)maxx]/100);
   }
    return 0;
}
