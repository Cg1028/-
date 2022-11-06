#include <stdio.h>
void SpiralSort(int a[5][5], int row, int column) {
    int p=1,q=1,i,j,k=5,l=5,kk=0,ll=0,t=0,tem,m=0,res[25]={0};
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            res[t++]=a[i][j];
        }/*录入矩阵*/
    }
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 24-i; j++){
            if(res[j]>res[j+1]){
                tem=res[j];
                res[j]=res[j+1];
                res[j+1]=tem;
            }
        }/*冒泡排序，把值存进一维数组待用*/
    }
    i=0;
    j=0;
    t=0;
    for ( m = 0; m <3; m++)/*可以看成三圈绕成的螺旋,一圈圈递归到最后一个中心位置。*/
    {
    
    while(p&&q){/*用两个开关分别控制列和行的行为*/
        a[i][j++]=res[t++];
        if(j==k--){
            p=!p;
        }/*行不动列右进*/
    }
    while (!p&&q)
    {
        a[i++][j]=res[t++];/*列不动行下进*/
        if(i==l--){
            p=!p;
            q=!q;
        }
        
    }
    while(p&&!q){
        a[i][j--]=res[t++];/*行不动列左进*/
        if(j==kk++){
            q=!q;
        }
    }
    while(p&&q){
        a[i--][j]=res[t++];/*列不动行上进*/
        if(i==ll++){
            break;
        }
    }
    }
/*调试可以一步步走下来，但运行会出问题，凉了。。。*/
}
int main (){
    int a[5][5] = {
 {11, 18, 17, 4, 24},
 {10, 1, 16, 5, 20},
 {6, 9, 12, 15, 25},
 {2, 8, 3, 7, 21},
 {14, 13, 19, 22, 23},
 };
    SpiralSort(a, 5, 5);
    int i, j;
for (i = 0; i < 5; i++) {
for (j = 0; j < 5; j++) {
printf("%d ", a[i][j]);
 }
printf("\n");
 }
    return 0;
}