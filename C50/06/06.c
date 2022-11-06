#include <stdio.h>
int main(){
    char n,i,j,tem;
    scanf("%d",&n);
    char a[n];
    char counter[n];

    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
        if (a[i]<0){
            counter[a[i]]=1;
            a[i]=-a[i];
        }
    }
    for(i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
                tem=a[j];
                a[j]=a[j+1];
                a[j+1]=tem;
            }
        }
    }
    for(i=0;i<n;i++){
        if (counter[a[i]]){
            a[i]=-a[i];
            printf("%3d",a[i]);
        }else{
            printf("%3d",a[i]);
        }
    }

return 0;
}