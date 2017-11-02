#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int i=0,id=0,kw=0,num=0,op=0;
char keys[5][10]={"end", "main", "int", "begin", "while"};                                  // Keyword list

void keyword(char *p){
    int k,flag=0;
    for(k=0;k<=4;k++)
        if(strcmp(keys[k],p)==0){
            printf("%s is a keyword\n",p);
            kw++;
            flag=1;
            break;
        }
    if(flag==0){
        if(isdigit(p[0])){
            printf("%s is a number\n",p);
            num++;
        }
        else
        //if(p[0]!=13&&p[0]!=10)
            if(p[0]!='\0'){
                printf("%s is an identifier\n",p);
                id++;
            }
    }
    i=-1;
}


int main(){
    char ch;
    char fname[50];
    char seperators[15]=" \t\n,;(){}[]#\"<>";
    char oper[]="!%^&*-+=~|.<>/?";
    char str[25];
    int j;
    FILE *f1;
    printf("Enter the path of the file relative to current directory: ");
    scanf("%s",fname);
    f1 = fopen(fname,"r");
    if(f1==NULL){
        printf("File not found!");
        exit(0);
    }
    while((ch=fgetc(f1))!=EOF){                                                             // Scan each char of file to check for identifiers etc
        for(j=0;j<=14;j++)
            if(ch==oper[j]){
                printf("%c is an operator\n",ch);
                op++;
                str[i]='\0';
                keyword(str);
            }
        for(j=0;j<=14;j++){
            if(i==-1)
                break;
            if(ch==seperators[j]){
                str[i]='\0';
                keyword(str);
            }
        }
        if(i!=-1){
            str[i]=ch;
            i++;
        }
        else
            i=0;
    }
    printf("Keywords: %d\nIdentifiers: %d\nOperators: %d\nNumbers: %d\n",kw,id,op,num);     //getch();
    return 0;
}
