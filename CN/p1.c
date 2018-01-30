/*
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    char charac;
    int a[10],i,j=7,temp,exp[30],data[24];
    a[0]=0;
    printf("Enter the character: ");
    scanf("%c",&charac);
    printf("\nASCII value is: %d",charac);
    i=charac;
    while (i!=0){
        temp=i%2;
        a[j--]=temp;
        i=i/2;
    }
    a[8]='\0';
    printf ("\nThe binary value is: ");
    for (i=0;i<8;i++)
        printf("%d",a[i]);
    printf("\n");
    j=0;
    for (i=0;i<8;i++){
        if(a[i]==0){
            exp[j++]=0;

            exp[j++]=0;

            exp[j++]=0;

        }
        else {
            exp[j++]=1;

            exp[j++]=1;

            exp[j++]=1;

        }
    }
     for (i=0;i<24;i++)
        printf("%d",exp[i]);

    printf("\nEnter the data:\n");
    for (i=0;i<24;i++)
        scanf("%d",&data[i]);

    printf("\n");
    for (i=0;i<24;i++)
        printf("%d",data[i]);
    int flag=0;
    for (i=0;i<24;i+=3){
        if(data[i]==data[i+1] && data[i+1]==data[i+2])
            continue;
        if(data[i]!=data[i+1] && data[i+1]==data[i+2])
            data[i]=data[i+1];
        else if(data[i+1]!=data[i+2] && data[i+1]==data[i])
            data[i+1]=data[i+2];
        else
            data[i+2]=data[i];
        flag++;

    }
    if (!flag)
        printf ("\nno error");

    else if(flag==1){
        printf ("\n1 bit error, string corrected\n");
    }
    else
        printf("\nMore than 1 error bit");

}
