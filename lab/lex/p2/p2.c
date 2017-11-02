//Write a C program to count number of words, chars, lines & spaces, taking input from a file.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
FILE  *fp ; 
char  ch ; 
fp = fopen ( "test.txt", "r" ) ; 
while ( 1 ) 
       {       
ch = fgetc ( fp ) ; 
if ( ch == EOF ) 
   break ; 
printf ( "%c", ch ) ; 
       }       
fclose ( fp ) ; 
}
