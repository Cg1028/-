#include<stdio.h>
#include <string.h>
int main()
{
    int i,j,k,T;
    char objct[10000]={'A'};
    scanf("%d",&T);
    for ( j = 0; j< T;j++)
    {
        fflush(stdin);
    int number = 0,c;
    scanf("%s",&objct);
    k=strlen(objct);
   for ( i = 0; i <k; i++)
   {
    if(objct[i]>'0'&&objct[i]<'9'){
        number++;
    }
   }
   
    printf("%d\n",number);
    }
    return 0;
}