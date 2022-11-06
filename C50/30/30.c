#include <stdio.h>
#include <string.h>
int main (){
    int i,DA,DB,PA=0,PB=0,sum=0;
    char A[10],B[10];
    scanf("%s %d %s %d",A,&DA,B,&DB);
    for ( i = 0; i < 10; i++)
    {
        if(A[i]-48==DA){
            PA=10*PA+DA;
        }
        if(B[i]-48==DB){
            PB=10*PB+DB;
        }
    }
    
    sum=PA+PB;
    printf("%d\n",sum);
    return 0;
}