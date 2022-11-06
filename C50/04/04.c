#include <stdio.h>
int main(){
    /*425 561*/
    int a,b,r;
    scanf("%d %d",&a,&b);
    if (b>a){
    r=b;
    b=a;
    a=r;
    }
while(a%b!=0){
    r=a%b;
    a=b;
    b=r;
}
printf("%d",b);
    return 0;
}