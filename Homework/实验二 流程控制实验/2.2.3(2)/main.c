#include <stdio.h>
int main(void)
{
    int x;
    scanf("%d",&x);
    do
        putchar(x%10+'0');
    while((x/=10)!=0);
    return 0;
}
