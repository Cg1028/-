#include <stdio.h>
#include <math.h>
int multi(int a,int b){
    return a*a+b*b;
}
int main(){
    int T,z,i,j,special[10000][2];
    double result;
    scanf("%d",&T);
    for ( z = 0; z < T; z++)
    {
        fflush(stdin);
        scanf("%d %d",&special[z][0],&special[z][1]);        
    }
    for ( i = 0; i < T; i++)
    {
        special[i][0]=multi(special[i][0],special[i][1]);
        if(result<special[i][0]){
            result=special[i][0];
        }
    }
    result=sqrt(result);
    printf("%.2f",result);
    return 0;
}