#include <stdio.h>
int main(){
    int num,step;
    scanf("%d",&num);
    for(;num!=1;){
    if(num%2==0){
        num=num/2;
    }else{num=(3*num+1)/2;}
    step++;
    }
    printf("%d",step);
    return 0;
}