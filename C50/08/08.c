#include <stdio.h>
int main(){
    int pepl,i,j,tem;
    int judge[100];
    float score;
    scanf("%d",&pepl);
    for ( i = 0; i < pepl; i++)
    {
        scanf("%d",&judge[i]);
    }
    for ( i = 0; i < pepl-1; i++)
    {
        for ( j = 0; j < pepl-i-1; j++)
        {
        if(judge[j]>judge[j+1]){
            tem=judge[j+1];
            judge[j+1]=judge[j];
            judge[j]=tem;
        }
        }
    }
    for ( i = 1; i < pepl-1; i++)
        {
            score+=judge[i];
        }
    score=score/(pepl-2);
    printf("%.2f",score);
    return 0;
}
/* 完善一下求平均数结果输出 */