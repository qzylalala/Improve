#include<stdio.h>
#define M 5
#define N 5
double average_student(double *p,int m);
double average_subject(double *p,int m,int n);
void less_than_average(double *p,int m,int n,double average);
int main()
{
    char name[M][20];
    int i;
    for(i=0;i<M;i++)
    {
        gets(name[i]);
    }
    double score[N][M];
    for(i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%lf",&score[i][j]);
        }
    }
    for(i=0;i<N;i++)
    {
        printf("%lf\t",average_student(score[i],M));
    }
    printf("\n");
    for(i=0;i<M;i++)
    {
        printf("%lf\t",average_subject(&score[0][i],M,N));
    }
    printf("\n");
    for(i=0;i<M;i++)
    {
        less_than_average(&score[0][i],M,N,average_subject(&score[0][i],M,N));
    }
    printf("\n");
    for(i=0;i<M;i++)
    {
        special_person(&score[0][i],M,N);
    }
    return 0;
}
double average_student(double *p,int m)
{
    int i;
    double sum=0;
    for(i=0;i<m;i++)
    {
        sum=sum+*(p+i);
    }
    return sum/m;
}
double average_subject(double *p,int m,int n)
{
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+*(p+m*i);
    }
    return sum/n;
}
void less_than_average(double *p,int m,int n,double average)
{
    int i,k=0;
    for(i=0;i<n;i++)
    {
        if(*(p+i*m)>average)
            k++;
    }
    printf("%d\t",k);
}
void special_person(double *p,int m,int n)
{
    int i,less_than60=0,good=0;
    for(i=0;i<n;i++)
    {
        if(*(p+i*m)<60) less_than60++;
        else if(*(p+i*m)>=90) good++;
    }
    printf("less than 60:%d   good:%d\n",less_than60,good);
}
