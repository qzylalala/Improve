#include<stdio.h>
int main(void)
{
    int i,n=0,s,m=1;
    printf("Please enter s:");
    scanf("%d",&s);
    for(i=1;;i++)
        {
        m=m*i;
        n++;
        if(m>=s){
            printf(" n=%d",n);
            break;}}
    return 0;
}
