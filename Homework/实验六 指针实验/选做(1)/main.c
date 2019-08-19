#include<stdio.h>
#include<ctype.h>
#define N 20
#define M 10
int main()
{
    int x_int[N],x_point[M];
    int y_int[N],y_point[M];
    int sum_int[N+1],sum_point[M],i,carry=0;
    for(i=0;i<=N;i++)
    {
        *(sum_int+i)=0;
    }
    for(i=0;i<M;i++)
    {
        *(sum_point+i)=0;
    }
    i=N-1;
    while(i>=0 && isdigit(*(x_int+i) = getchar()))
    {
        *(x_int + i--)-='0';
    }
    if(getchar()=='.') ;
    i=M-1;
    while(i>=0 && isdigit(*(x_point+i) = getchar()))
    {
        *(x_point + i--)-='0';
    }
    i=N-1;
    getchar();
    while(i>=0 && isdigit(*(y_int+i) = getchar()))
    {
        *(y_int + i--)-='0';
    }
    getchar();
    i=M-1;
    while(i>=0 && isdigit(*(y_point+i) = getchar()))
    {
        *(y_point + i--)-='0';
    }
    for(i=0;i<M;i++)
    {
        *(sum_point + i) = *(x_point + i) +*(y_point + i) +carry;
        carry = (*(sum_point+i)-*(sum_point+i)%10)/10;
        *(sum_point+i)=*(sum_point+i)%10+'0';
    }
    for(i=0;i<N;i++)
    {
        *(sum_int + i) = *(x_int + i) +*(y_int + i) +carry;
        carry = (*(sum_int+i)-*(sum_int+i)%10)/10;
        *(sum_int+i)=*(sum_int+i)%10+'0';
    }
    *(sum_int + N)=carry + '0';
    for(i=N-1;i>=0;i--)
    {
        putchar(*(sum_int+i));
    }
    if(sum_int[N]!='0') putchar(*(sum_int + N));
    putchar('.');
    for(i=M-1;i>=0;i--)
    {
        putchar(*(sum_point+i));
    }
    return 0;
}
