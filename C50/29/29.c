#include <stdio.h>
int main(){
    int i,j,T,sum,nums[10];
    scanf("%d",&T);
    for ( i = 0; i < T; i++)
    {
        scanf("%d",&nums[i]);
    }
    for ( i = 0; i < T-1; i++)
    {
        for ( j = i+1; j < T; j++)
        {
            sum+=10*nums[i]+nums[j];
            sum+=10*nums[j]+nums[i];
        }
        
    }
    printf("%d",sum);
    return 0;
}