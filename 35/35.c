#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1,const void* p2){
    return *((int *)p2)-*((int*)p1);
}
int main(){
    int t,j,i,n;
    float score[100]={0};
    scanf("%d",&t);
    for ( i = 0; i < t; i++)
    {
        scanf("%d",&n);
        for ( j = 0; j < n; j++)
        {
            scanf("%f",&score[j]);
        }
        int size=sizeof(score)/sizeof(score[0]);
        qsort(score,size,sizeof(score[0]),cmp);
        printf("%.2f\n",score[0]);
    }
    
    return 0;
}