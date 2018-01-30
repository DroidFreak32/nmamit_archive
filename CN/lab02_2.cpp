#include <stdio.h>
#include <stdlib.h>

struct Frames
{
	char INFO;
	int f_no;
};

int partition(struct Frames f[],int l,int r)
{
    int p,i,j,temp;
    p=f[l].f_no;
    i=l;
    j=r+1;
    do {
		do {
		    i=i+1;
		} while(f[i].f_no<p && i<=r);

		do{
		    j=j-1;
		} while(f[j].f_no>p);

		temp=f[i].f_no;
		f[i].f_no=f[j].f_no;
		f[j].f_no=temp;
    } while(i<j);
    temp=f[i].f_no;
    f[i].f_no=f[j].f_no;
    f[j].f_no=temp;
    temp=f[l].f_no;
    f[l].f_no=f[j].f_no;
    f[j].f_no=temp;
    return j;
}

void quick(struct Frames f[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(f,l,r);
        quick(f,l,s-1);
        quick(f,s+1,r);
    }
}


int main(){
	struct Frames f[12];
	printf("Enter Info\n");
	for (int i = 0; i < 12; i++) {
		f[i].f_no=i;
		scanf("%c",&f[i].INFO);
	}

	quick(f,0,12-1);
	printf("Sorted!!\n\n");
	for (int i = 0; i < 12; ++i) {
		printf("i = %d fno = %d \n info= %c \n",i,f[i].f_no,f[i].INFO);
	}
	for (int i = 0; i < 12; i++) {
		int j=rand()%11;
		printf("i = %d fno = %d \n info= %c \n",i,f[j].f_no,f[j].INFO);
	}

}
// }
// for (int i = 0; i < 10; ++i)
// {	
// 	j=rand()%10
// 	reci(f[j])
// }