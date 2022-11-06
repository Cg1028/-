#include <stdio.h>
void del_digit(char str[]);
int main()
{
  char str[100];
  printf("字符串为：");
  scanf("%s", str);//输入字符串
  del_digit(str);

  return 0;
}
void del_digit(char str[])
{
  int i = 0, j = 0;
  while (str[i]) {
  //数字对应的ASCII值范围是48~57（0~9）
  	
    
    while (str[i] >= 48&&str[i] <= 57)//判断str[i]是否为数字
  		i++;
    /*一直循环到该字符不是数字为止。*/


  	str[j] = str[i];//将数字跳过
  	i++;
  	j++;
  }
  puts(str);//输出不含数字的字符串
}
