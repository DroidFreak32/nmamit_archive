#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[30];
    printf("Enter a string");
    scanf("%s",s);
    int count=ccount=0;
//  printf(isalpha(s[2]));
    for(int i=0;i<strlen(s);i++){
        switch(s[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': count++;
            printf("\nVowel is: %c",s[i]);
            break;
            default:ccount++;

        }
    }
    printf("\nTotal number of vowels: %d \nConsonants: %d",count,ccount);
}
