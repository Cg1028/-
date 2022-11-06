#include <stdio.h>
int main(){
    int a,b,c,days,i,j;
    scanf("%d/%d/%d\n",&a,&b,&c);
    for(i=b-1;i>0;i--){
        switch(i){
        case 1:
        days=days+31;
        break;
        case 3:
        days=days+31;
        break;
        case 4:
        days=days+30;
        break;
        case 5:
        days=days+31;
        break;
        case 6:
        days=days+30;
        break;
        case 7:
        days=days+31;
        break;
        case 8:
        days=days+31;
        break;
        case 9:
        days=days+30;
        break;
        case 10:
        days=days+31;
        break;
        case 11:
        days=days+30;
        break;
        case 12:
        days=days+31;
        break;
        default:
        break;}
        if(i==2&&a%4==0&&a%100!=0){
            days+=29;
        }else if(i==2){
            days+=28;
        }
    }
        days+=c;
        printf("%d",days);
    return 0;
}