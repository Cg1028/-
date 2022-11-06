#include <stdio.h>
void CalculateDate(int year, int month, int day) {
    int days;
    if(month==(1||3||5||7||8||10||12)){
            days-=(31-day);
            month++;
        }else if(month==(9||4||6||11)){
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

    while(days<59&&days>31){
        if(month>=12){
            year++;
            month-=12;
        }/*判断年份是否++*/
        
        if(month==(1||3||5||7||8||10||12)){
            days-=31;
            month++;
        }else if(month==(9||4||6||11)){
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
    resultDay=day;
    resultMonth=month;
    resultYear=year; 
 printf("%d %d %d\n", resultYear, resultMonth, resultDay);
}/*哎*//*？？？？？？？？？？？？*/

int main() {
 int year, month, day;
 scanf("%d %d %d", &year, &month, &day);
 CalculateDate(year, month, day);
}
/*怪*/