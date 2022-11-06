#include <stdio.h>
int main(){
    int N,M,i,j;
    char mark;
    scanf("%d %c",&N,&mark);
    M=N*1.0/2+0.5;
    for ( i = 0; i < M; i++)
    {
        if(i==0||i==M-1){
            for ( j = 0; j < N; j++)
            {
                printf("%c",mark);
            }
            printf("\n");
        }else{
            for ( j = 0; j < N; j++)
            {
                if(j==0)
                {
                    printf("%c",mark);
                }else if(j==N-1){
                    printf("%c\n",mark);
                }else{
                    printf(" ");
                }
                
            }
            
        }
    }
    
    return 0;
}