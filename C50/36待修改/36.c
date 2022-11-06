#include <stdio.h>
#include <string.h>
int main(){
    char youngest[6],old[6],name[6];
    char oldest[6];
    int N,counter,i,day,month,year,birth,older=18170905,younger=20140907;
    scanf("%d",&N);
    for ( i = 0; i < N; i++)
    {
        fflush(stdin);
        scanf("%s %d/%d/%d",name,&year,&month,&day);
        birth=year*10000+month*100+day;
        if(birth<=20140906&&birth>=18140906){
            counter++;
            if (birth<younger){
                younger=birth;
                strcpy(oldest,name);
            }
            if(birth>older){
                older=birth;
                strcpy(youngest,name);
            }
        }
    }
    printf("%d",counter);
    if(counter!=0){
    printf(" %s %s\n",oldest,youngest);
    }
    return 0;
}