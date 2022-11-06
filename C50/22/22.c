#include <stdio.h>

char *multiply(char *num1, char *num2) {
    scanf("%s*%s",num1,num2);
    char num3=" ";
    int t=10,k=10,Y,J,res=0,tem=0;
    while (get(num1[t--])!=' ')/*从第一个数个位开始*/
    {
        while (get(num2[k--])!=' ')/*第二个数个位开始*/
        {
            res=(int)num1[t+1]*(int)num2[k+1]+res;/*单数相乘,并加上次进位*/
            if(res>10){
                tem=res%10;/*保留原位*/
                res/=10;/*保留进位*/
            }
            /*没有append用这可如何是好。。。*/
        }
        /*只好往下做6题了。。。*/
    }
    
}
int main() {
 char num1[10] = "123";
 char num2[10] = "456";
 char * num3 = multiply(num1, num2);
}
