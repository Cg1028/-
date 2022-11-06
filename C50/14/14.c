#include <stdio.h>
int main(){
    int nums[100][100],i,j,tem,index;
    for ( i = 0; i < 100 ; i++)
    {
        scanf("%d",&nums[i][0]);
        for ( j = 1; j <= nums[i][0]; i++)
        {
            scanf("%d",&nums[i][j]);
        }
    }
    for ( i = 0; i < 100; i++)
    {
        for ( j = 1; j < nums[i][0]; j++)
        {
            if (nums[i][j]<=nums[i][j+1])
            {
                index=j;
            }else{
                index=j+1;
            }
        }
    }
    
    return 0;
}