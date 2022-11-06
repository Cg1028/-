#include <stdio.h>
int main(){
    int T,i;
    scanf("%d",&T);
    char string[T];
    for ( i = 0; i < T; i++)
    {
        scanf("%d",&string[i]);
    }
    for ( i = 0; i <T; i++)
    {
        putchar(string[i]);
    }
    return 0;
}