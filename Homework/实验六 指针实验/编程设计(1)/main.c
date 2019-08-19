#include<stdio.h>
int main()
{
    long x,i,j;
    int n;
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%ld",&x);
        char *p=(char *)&x;
    char low,high;
    p=p+3;
    for(i=3;i>=0;i--)
    {
        low=(*p)&0x0f;
        if(low<10)
            low=low+'0';
        else low=low+'A'-10;
        high=((*p)>>4)&0x0f;
        if(high<10)
            high=high+'0';
        else high=high+'A'-10;
        p--;
        if(i>0)
        printf("%c %c ",high,low);
        else printf("%c %c",high,low);
    }
    printf("\n");
    }
    return 0;
}
