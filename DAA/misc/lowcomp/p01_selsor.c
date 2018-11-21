#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
//void selection();
int n,j,i,temp=0,a[50],min;
struct timeval tim;
double dtime1,dtime2;
void selection()
{
  for(i=0;i<n-1;i++){
    min = i;
    for(j=i+1;j<n;j++)
        if(a[min]>a[j])
        {
            min = j;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}

int main()
{
    printf("enter the  number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=rand()%100;
    printf("entered elements\n");
    for(i=0;i<n;i++)
        printf(" %d\t",a[i]);
    gettimeofday(&tim,NULL);
    dtime1=tim.tv_sec+(tim.tv_usec/1000000.0);
    selection();
    gettimeofday(&tim,NULL);
    dtime2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("\nSorted Array: \n");
    for(i=0;i<n;i++)
    {
        printf(" %d\t",a[i]);
    }

    printf("\n Elapsed time is %lf\n", dtime2-dtime1);
    printf("\n\n%lf\n\n",tim.tv_usec);
    return 0;
}
