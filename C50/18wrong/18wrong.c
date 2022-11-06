#include <stdio.h>
int main(){
    int T,z;
    int m,n,x,y,i,j,k,tem,colsum[1000],result;
    scanf("%d",&T);
    for ( z = 0; z < T; z++)
    {
    scanf("%d%d%d%d",&m,&n,&x,&y);
    int matrix[m][1000];
    /*录入矩阵：*/
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    /*筛每行中y个数之和最大的那y个数并求和*/
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n-1; j++)
        {
            for ( k = 0; k < n-j-1; k++)
            {
                if (matrix[i][k]<matrix[i][k+1])
                {
                    tem=matrix[i][k];
                    matrix[i][k]=matrix[i][k+1];
                    matrix[i][k+1]=tem;
                }
            }
        }
    }
    for ( i = 0; i < m; i++)
    {colsum[i]=0;
        for ( j = 0; j < y; j++)
        {
            colsum[i]+=matrix[i][j];
        }
    }
    /*把行和排序，取前x行在求和*/
    for ( i = 0; i < m-1; i++)
    {
        for ( j = 0; j <m-i-1 ; j++)
        {
            if(colsum[i]<colsum[i+1]){
                tem=colsum[i];
                colsum[i]=colsum[i+1];
                colsum[i+1]=tem;
            }
        }
    }
    for ( i = 0; i < x; i++)
    {
        result+=colsum[i];
    }
    printf("%d",result);
    }
    return 0;
}