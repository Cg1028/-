#include <stdio.h>
int main(){
    long long n;
    int c,i,j,cost=0;
    scanf("%lld%d",&n,&c);
    int enemy=n;
    int a[n],counter[n];/*存敌人与坐标、某位置的敌人数目*/
    for ( i = 0; i < n; i++)
    {
        counter[i]=0;
    }
    
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        counter[a[i]]++;
    }
    for ( i = 0; i < n; i++)
    {
        if(counter[i]>=c){/*如果某位置人数多余c，致命一只因更划算。*/
            cost+=c;
            enemy-=counter[i];
        }
    }
    cost+=enemy;/*剩下的敌人单点。*/
    printf("%d",cost);
    
    return 0;
}