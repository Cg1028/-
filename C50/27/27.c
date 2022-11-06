#include <stdio.h>
int main (){
    int N,i,j,m[1000];
    double tem,Q,money,reimbursement=0,items[30][1000],price[30]={0};
    char type[30][1000];
    for (;;)
    {fflush(stdin);
    scanf("%lf%d",&Q,&N);/*接收报销额度和发票数目*/
    for ( i = 0; i < N; i++)/*遍历每一张发票*/
    {
        scanf(" %d",&m[i]);/*接收发票上物品数目*/
        if(m==0){
            return 0;
        }
        for ( j = 0; j < m[i]; j++)/*接收每一件物品信息*/
        {
            
            scanf(" %c: %Lf",&type[i][j],&items[i][j]);
            if(items[i][j]>600){/*单个物品超过600的发票不考虑报销*/
                items[i][j]=Q+1;
                break;
            }
            if(type[i][j]=='A'){/*非报销物品不考虑价格*/
                items[i][j]=items[i][j];
            }else if(type[i][j]=='B'){
                items[i][j]=items[i][j];
            }else if(type[i][j]=='C'){
                items[i][j]=items[i][j];
            }else{
                items[i][j]=0;
            }
    }}
    for ( i = 0; i < N; i++)/*开始处理发票*/
    {
        for ( j = 0; j < m[i]; j++)
        {
            price[i]+=items[i][j];/*计算每一张发票的物品总额*/
        }
        if (price[i]>Q)/*不得超过报销总额Q*/
        {
             price[i]=0;
        }
    }
    /*对数组price动态规划，以Q为标准。*/
    for ( i = 0; i < N-1 ; i++)/*把每张发票的价格冒泡排序。*/
    {
        for ( j = 0; j < N-i-1; j++)
        {
            if (price[j]<price[j+1])
            {
                tem=price[j+1];
                price[j+1]=price[j];
                price[j]=tem;
            }
        }
    }
    for ( i =N-1; i >=0 ;i--)/*背包算法，求最大报销量，*/
    {
        if(reimbursement<Q-price[i]){
            reimbursement+=price[i];
        }
    }
    printf("%.2Lf",reimbursement);
    }
    
    return 0;}

