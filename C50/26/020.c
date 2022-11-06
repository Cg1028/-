#include <stdio.h>
void CalculateDate(int year, int month, int day) {
    int days;
    scanf("%d",&days);
    if(month==1){/*???*/
            days-=(31-day);
            month++;
        }else if(month==3){
            days-=(31-day);
            month++;
        }
        else if(month==5){
            days-=(31-day);
            month++;
        }
        else if(month==7){
            days-=(31-day);
            month++;
        }
        else if(month==8){
            days-=(31-day);
            month++;
        }
        else if(month==10){
            days-=(31-day);
            month++;
        }
        else if(month==12){
            days-=(31-day);
            month++;
        }
        else if(month==4){
            days-=(30-day);
            month++;
        }else if(month==6){
            days-=(30-day);
            month++;
        }else if(month==9){
            days-=(30-day);
            month++;
        }else if(month==11){
            days-=(30-day);
            month++;
        }else{
            if((year%4==0&&year%100!=0)||(year%400==0)){
                days-=(29-day);
                month++;
            }else{
                days-=28;
                month++;
            }
        }
    /*day零头清空*/

    while(days>31){
        if(month>=12){
            year++;
            month-=12;
        }/*判断年份是否++*/
        if(month==1){/*???*/
            days-=31;
            month++;
        }else if(month==3){
            days-=31;
            month++;
        }
        else if(month==5){
            days-=31;
            month++;
        }
        else if(month==7){
            days-=31;
            month++;
        }
        else if(month==8){
            days-=31;
            month++;
        }
        else if(month==10){
            days-=31;
            month++;
        }
        else if(month==12){
            days-=31;
            month++;
        }
        else if(month==4){
            days-=30;
            month++;
        }else if(month==6){
            days-=30;
            month++;
        }else if(month==9){
            days-=30;
            month++;
        }else if(month==11){
            days-=30;
            month++;
        
        }else{
            if((year%4==0&&year%100!=0)||(year%400==0)){
                days-=29;
                month++;
            }else{
                days-=28;
                month++;
            }
        }/*增长月份。luping电脑好烫，要爆炸了*/
    }
 int resultYear, resultMonth, resultDay;
    resultDay=days;
    resultMonth=month;
    resultYear=year; 

printf("%d %d %d\n", resultYear, resultMonth, resultDay);
}/*？？？？？？？？？？？？*/
  
int main() {
 int year, month, day;
 scanf("%d %d %d", &year, &month, &day);
 CalculateDate(year, month, day);
}
/*怪*/