#include <stdio.h>
int main (){
    int n,i,j;
    scanf("%d",&n);
    int matrix[n][n],tem[n];
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&matrix[i][j]);/*录入矩阵*/
        }
    }
    for ( i = 0; i < n/2; i++)
    {
        for ( j = 0; j < n/2; j++)/*变换位置时相关的四个元素要同时变换，否则会因为覆盖造成数据丢失*/
        {
            tem[0]=matrix[i][j];
            tem[1]=matrix[i][n-j-1];
            tem[2]=matrix[n-i-1][n-j-1];
            tem[3]=matrix[n-i-1][j];
            matrix[i][j]=tem[3];
            matrix[i][n-j-1]=tem[0];
            matrix[n-i-1][n-j-1]=tem[1];
            matrix[n-i-1][j]=tem[2];
        }
    }
    
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%4d",matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}