#include<stdio.h>
int no_empty(char *p);
int main()
{
    char *p[100];
    char a[100][80];
    int n,i;
    for(i=0;i<100;i++)
    {
        p[i]=a[i];
    }
    while(scanf("%d",&n)!=EOF&&n)
    {getchar();
    for(i=0;i<n;i++)
    {
        fgets(p[i],100,stdin);
    }
    for(i=0;i<n;i++)
    {
        if(no_empty(p[i])==1) ;
    }
        printf("\n");
    }
    return 0;
}
int no_empty(char *p)
{
    int flag=1,i,sum=0;
    for(i=0;*(p+i)!='\0';i++)
    {
        if(*(p+i)==' ') sum++;
    }
    if(i==sum+1) return 1;
    for(i=0;*(p+i)!='\0';i++)
    {
        if(*(p+i)==' ')
        {
            if(flag==1)
            {
                printf(" ");
                flag=0;
            }
            else ;
        }
        else
        {
            printf("%c",*(p+i));
            flag=1;
        }
    }
    return 0;
}
