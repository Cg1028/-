#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
int main(){
    long nums[10][3];
    int num,i,j;
    scanf("%d",&num);
    for ( i = 0; i < num; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            scanf("%ld",&nums[i][j]);
        }
    }
    for ( i = 0; i < num; i++)
    {
        if(nums[i][0]+nums[i][1]>nums[i][2]){
            printf("Case #%d: true\n",i+1);
        }else{
            printf("Case #%d: false\n",i+1);
        }
        
    }
    return 0;
}