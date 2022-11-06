#include <stdio.h>
int main(){
    char i,n,a[100];
    int res;
    res=1;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
   for ( i = 0; i < n; i++)
    {
    if(a[i]%2!=0){
        res=res*a[i];
        }
    }
    
printf("%d",res);
    return 0;
}