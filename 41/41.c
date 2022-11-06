#include <stdio.h>
#include <ctype.h>
 
int main(){
	int a[128]={0},i;
	char c;
	while((c=tolower(getchar()))!='\n')	a[(int)c]++;/*逐个获取c的字符，并转化成小写，a[c的ASCII码值]+1。*/
	int max[2]={0,0};	//max[0]=key,max[1]=value
	for(i=97;i<123;i++){
		if(max[1]<a[i]){	//选value多的
			max[0]=i;
			max[1]=a[i];
		}
		if(max[1]==a[i]&&max[0]>i){	//个数一样多的话，如果现在的key比较大，才更新 
			max[0]=i;
			max[1]=a[i];
		}
	}
	printf("%c %d",(char)(max[0]),max[1]);
}