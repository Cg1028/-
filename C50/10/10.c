#include <stdio.h>
int main(){
    int n,m,i,j,people;
    int stu[20][20];
    float personscore[20],subjectscore[20];
    scanf("%d%d",&n,&m);
    people=n;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j< m; j++)
        {
            scanf("%d",&stu[i][j]);
        }
    }
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            personscore[i]+=stu[i][j];
        }
    personscore[i]=personscore[i]/m;
    }

    for ( j = 0; j <m; j++)
    {
        for ( i = 0; i < n; i++)
        {
            subjectscore[j]+=stu[i][j];
        }
    subjectscore[j]=subjectscore[j]/n;
    }

    for ( i = 0; i < n; i++)
    {
        printf("%4.2f ",personscore[i]);
    }
    printf("\n");
    for ( j = 0; j < m; j++)
    {
        printf("%4.2f ",personscore[j]);
    }
    printf("\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j< m; j++)
        {
            if(stu[i][j]<subjectscore[j]){
                people--;
                break;
            }
        }
    }
    printf("%d",people);
    return 0;
}