#include <stdio.h>
int main(){
    /*求一个矩阵最大子矩阵，题目要求x，y=2，我这里没有特别规定一定要是2阶子矩阵。*/
    int T,z;
    int m,n,x,y,i,j,k,q,p,r,tem,maxmatrix[1000],maxcolsum[1000][1000][1000],result;
    /*录入操作次数T与原矩阵行列数和子矩阵行列数*/
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
    /*用i，j，k遍历每一个子矩阵，对其进行列/行求和，对结果求最大子段和，储存在三维数组*/
    /*需要一个一维数组运算子矩阵的最大子段和*/
    for ( i = 0; i < m; i++)
    {
        for ( j = i; j < m; j++)
        {
            for ( k = 0; k < n; k++)
            {
                for ( p = 0; p < k; p++)/*遍历子矩阵的列*/
                {
                    for ( q = i; q < j; q++)/*对每一列进行求和*/
                    {
                        maxmatrix[k]+=matrix[q][p];
                    }
                }
                /*此时maxmatrix里是子矩阵的列和，对其求最大子段和*/
                for ( r = 0; r < p-1; r++)
                {
                    if(maxmatrix[r]>=0){
                        maxmatrix[r+1]+=maxmatrix[r];
                        if(tem<maxmatrix[r+1]){
                            tem=maxmatrix[r+1];
                        }
                    }else{
                        tem=maxmatrix[r+1];
                    }
                }
                /*tem就是该子矩阵的最大和，存进三维数组*/
                maxcolsum[i][j][k]=tem;
            }
        }
    }
for ( i = 0; i < m; i++)
    {
        for ( j = i; j < m; j++)
        {
            for ( k = 0; k < n; k++)
            {
                if (result<maxcolsum[i][j][k])
                {
                    result=maxcolsum[i][j][k];
                }
                
            }
        }
    }
    printf("%d",result);
    }
    return 0;

}