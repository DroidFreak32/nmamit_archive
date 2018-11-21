// ERRROOORRRR
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
void merge(int b[],int p,int c[],int q,int a[])
{
    int i,j,k;
    i=0;j=0;k=0;
    while(i<p&&j<q)
    {
        if(b[i]<=c[j])
        {
            a[k]=b[i];
            i=i+1;
        }
        else
        {
            a[k]=c[j];
            j=j+1;
        }
        k++;
    }
    if(i==p)
        for(;j<q;j++)
            a[k++]=c[j];
    else
        for(;i<p;i++)
            a[k++]=b[i];
}
void mergesort(int a[],int n)
{
    int b[100],c[100],temp,i,j;
    if(n>1)
    {
        for(i=0;i<floor(n/2);i++)
            b[i]=a[i];
        for(i=floor(n/2),j=0;i<n;i++,j++)
            c[j]=a[i];
        mergesort(b,floor(n/2));
        mergesort(c,ceil(n/2));
        merge(b,floor(n/2),c,ceil(n/2),a);
    }
}
int main()
{
    int n;
    int a[100];
    struct timeval tim;
    double dtime1,dtime2;
    printf("Enter n: ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        a[i]=rand()%100;
    printf("\nThe array: ");
    for(i=0;i<n;i++)
        printf("%d \t",a[i]);
    gettimeofday(&tim,NULL);
    dtime1=tim.tv_sec+(tim.tv_usec/1000000.0);
    mergesort(a,n);
    gettimeofday(&tim,NULL);
    dtime2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("%d \t",a[i]);
    printf("\nElapsed time: %f seconds",dtime2-dtime1);
}
