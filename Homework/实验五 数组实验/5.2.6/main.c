#include<stdio.h>
#include<string.h>
#define n 3
#define max 20
int bin(float a[],int x,int t);
void sort(float score[],int index[],int m);
int main()
{
    float score[n];
    char name[n][max];
    int i,index[n],x,s;
    for(i=0;i<n;i++)
    {
        scanf("%s %f",&name[i][0],&score[i]);
    }
    for(i=0;i<n;i++)
    {
       index[i]=i;
    }
    sort(score,index,n);
    for(i=0;i<n;i++)
    {
        printf("%s:%f\n",name[index[i]],score[index[i]]);
    }
    scanf("%d",&x);
    s=bin(score,x,n);
    if(s!=1)
        printf("%s:%f\n",name[s],score[s]);
    else printf("not found");
    return 0;
}
void sort(float score[],int index[],int m)
{
    int i,j,t;
    for(i=0;i<m-1;i++)
        for(j=0;j<m-1-i;j++)
    {
        if(score[index[j]]>score[index[j+1]])
        {
            t=score[index[j]];
            score[index[j]]=score[index[j+1]];
            score[index[j+1]]=t;
        }
    }
}
int bin(float a[],int x,int p)
{
    int begin=0,end=p-1,mid;
    while(begin<end)
    {
        mid=(begin+end)/2;
        if(x<a[mid])
            end=mid-1;
        else if(x>a[mid])
            begin=mid+1;
        else return mid;
    }
    return 0;
}
