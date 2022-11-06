#include <stdio.h>
int main (){
    int popu[100000],n,naire,i,j,tem;
    RE:
    scanf("%d%d",&n,&naire);
    if(n==0&&naire==0){
        return 0;
    }
    for ( i = 0; i <n; i++)
    {
        scanf("%d",&popu[i]);
    }
    if(n<=naire){
        for ( i = 0; i < n; i++)
        {
            printf("%d",popu[i]);
        }
    }
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j <n-i-1; j++)
        {
            if(popu[j]<popu[j+1]){
                tem=popu[j];
                popu[j]=popu[j+1];
                popu[j+1]=tem;
            }
        }
    }
    for ( i = 0;  i<naire; i++)
    {
        printf("%d",popu[i]);
    }
    goto RE;
    
    return 0;
}