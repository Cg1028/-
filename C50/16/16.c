#include <stdio.h>
int main (){
    int n,j;
    scanf("%d",&n);
    fflush(stdin);
    char words;
    for ( j = 0; j < n; j++)
    {
        int a=0,e=0,i=0,o=0,u=0;
        while (scanf("%c",&words),words!='\n')
        {
            switch (words)
            {
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            default:
                break;
            }
        }
        words='p';
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
    }
    return 0;
}