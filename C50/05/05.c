#include <stdio.h>
int main(){
    int i,j,a[100];
/*     for (i=0,i<100,i++){
        a[i]=0
    } */
    for (i=2;i<100;i++){
        if (!a[i]){
            for(j=i;i*j<100;j++){
            a[i*j]=1;
        }
    }
    }
    for ( i = 0; i < 100; i++)
    {
    if (!a[i]){
        printf("%d\t",i);
    }
    }
    
    return 0;
}