#include<iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<iomanip>
using namespace std;
int main()
{
        int i=0,j=0,k=0,m=0,n=0,o=0,o1=0,var=0,l=0,f=0,c=0,f1=0;
    char   str8[200] ,str5[300],str[100],str1[300]="S",temp[50],temp1[50],temp2[100],tt[20],t3[20],err[10],stak[200];
    strcpy(temp1,"");
    strcpy(temp2,"");
    strcpy(str5,"");
    char t[10];
    char array[15][20][20] = {
                  //0  //1    //2    //3     //4   //5    //6    //7    //8   //9  //10  /*11 12   12  13   14   15  16   17  18
 "NT","main","int","begin","end","while", "count","n", "return","_", "+", "/", "$", "=", "1", "2", ">",")","(",";",
"S", "Er", "TPES","beginSD","","WOCORDPWS","R","R","returnPV","","Er","Er","","Er","Er","Er","Er","Er","Er","Er",
              "E", "MOO","Er",  "Er",  "Er", "Er",   "L",   "L", "Er" , "Er" , "Er" ,"Er","Er","Er","Er","Er","Er","Er","Er","Er",
                 "P",  "Er", "Er", "Er" , "Er" , "Er" , "Er" , "Er" , "Er" , "_" , "Er" , "Er" , "Er","Er","Er","Er","Er","Er","Er","Er",
                 "T",  "Er", "int", "Er" , "Er" , "Er" ,"Er" ,"Er" , "Er" , "Er" , "Er" , "Er" , "Er","Er","Er","Er","Er","Er","Er","Er",
                 "W",  "Er", "Er", "Er" , "Er" , "while" , "Er", "Er" , "Er" , "Er" , "Er" , "Er" , "Er","Er","Er","Er","Er","Er","Er","Er",
                 "D", "Er", "Er", "Er", "endS", "Er" , "Er" ,"Er", "Er" , "Er" , "Er" , "Er" , "Er" ,"Er","Er","Er","Er","Er","Er","Er",
                 "R",  "Er", "Er" , "Er" ,"", "Er" ,"VOVAOR","VOVAOR", "Er" , "Er" , "Er" , "Er" , "" ,"Er","Er","Er","Er","Er","Er","Er",
                 "C",  "Er", "Er" , "Er" ," Er", "Er" ,"VON","VON", "Er" , "Er" , "Er" , "Er" , "Er" ,"Er","Er","Er","Er","Er","Er","Er",
                 "V", "Er" , "Er" , "Er" ," Er", "Er" ,"count", "n" ,"Er" , "Er" , "Er" , "Er" , "Er" ,"Er","Er","Er","Er","Er","Er","Er",
                 "A", "Er", "Er" , "Er", "Er" , "Er" , "Er" , "Er" , "Er" , "Er" ,"ON", "ON" , "Er" ,"Er","Er","Er","Er","Er","Er","Er",
                 "L", "Er", "Er", "Er" , "Er" ,"Er" ,"VONO","VONO", "Er" , "Er" , "Er" , "Er" , "Er","Er","Er","Er","Er","Er","Er","Er",
                 "O", "Er", "Er", "Er" , "Er" ,"Er" ,"Er","Er", "Er" , "_" , "+" , "/" , "Er", "=" , "Er" , "Er" , ">",")","(",";",
                 "N", "Er", "Er", "Er" , "Er" , "Er" ,"Er","Er", "Er" , "Er" , "Er" , "Er" , "Er","Er","1","2","Er","Er","Er","Er",
                 "M", "main", "Er", "Er" , "Er" ,"Er" ,"Er","Er", "Er" , "Er" , "Er" , "Er" , "Er","Er","Er","Er","Er","Er","Er","Er"
                };
       cout <<setw(100)<<"PARSER TABLE"<<endl;
       cout<<endl;
    for(i=0;i<15;i++) //nonterminal
    {
        for(j=0;j<20;j++) //terminal
        {
            cout.setf(ios::right);
            cout.width(10);
            cout<<array[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"\n\tENTER THE STRING :";
   gets(str);
    strcpy(str8,str);
    if(str[strlen(str)-1] != '$')
    {
          cout<<"END OF STRING MARKER SHOULD BE '$'";
          getch();
          exit(1);
    }
     cout <<setw(100)<<"STRING PARSING TABLE"<<endl;
     cout<<setw(100)<<"\n_____________________________"<<endl;
     cout<<setw(93)<<"PRODUCTION"<<endl;
     cout<<endl;
     cout<<setw(90)<<str1;
     i=0;
     while(i<strlen(str))
    {
     again:
          if(str[i] == ' ' && i<strlen(str))
          {
               cout << "\n\tSPACES IS NOT ALLOWED IN SOURSE STRING ";
               getch();
               exit(1);
          }
          temp[k]=str[i];
          temp[k+1]='\0';
          f1=0;
     again1:
          if(i>=strlen(str))
          {
               getch();
               exit(1);
          }
          for(int l=1;l<=20;l++) //terminal
          {
            if(strcmp(temp,array[0][l])==0)
            {
                f1=1;
                m=0,o=0,var=0,o1=0;
                strcpy(temp1,"");
                strcpy(temp2,"");
                int len=strlen(str1);
                while(m<strlen(str1) && m<strlen(str))
                {
                      if(str1[m]==str[m])
                      {
                           var=m+1;
                           temp2[o1]=str1[m];
                           m++;
                           o1++;
                      }
                      else
                      {
                           if((m+1)<strlen(str1))
                           {
                               m++;
                               temp1[o]=str1[m];
                               o++;
                           }
                           else
                               m++;
                      }
                }
                temp2[o1] = '\0';
                temp1[o] = '\0';
                t[0] = str1[var];
                t[1] = '\0';
                for(n=1;n<=15;n++) //nonterminal
                {
                    if(strcmp(array[n][0],t)==0)
                    {
                        break;
                    }
                }
                strcpy(str1,temp2);
                strcpy(str5,temp2);
                strcat(str1,array[n][l]);
                strcat(str1,temp1);
                cout<<"\n  "<<setw(90)<<str1;
                strcpy(str5,"");
                getch();
                if(strcmp(array[n][l],"")==0)
                {
                    if(i==(strlen(str)-1))
                    {
                          int len=strlen(str1);
                           cout<<setw(100)<<"\n______________________________________"<<endl;
                          cout <<"\n  "<<setw(90)<<str1<<endl<<endl<<setw(90)<<"ACCEPTED"<<endl;
                          cout << "\n"<<setw(90)<<"ENTERED STRING IS VALID";
                          getch();
                          exit(1);
                      }
                      strcpy(temp1,"");
                      strcpy(temp2,"");
                      strcpy(t,"");
                      goto again1;
                }
                if(strcmp(array[n][l],"Er")==0)
                {
                      cout<<"\n  "<<setw(90)<<str1<<endl;
                        cout<<setw(100)<<"\n_______________________________________"<<endl;
                        cout <<"\n  "<<setw(90)<<str1<<endl<<endl<<setw(95)<<"REJECTED..!!"<<endl;
                      cout << "\n"<<setw(100)<<"ERROR IN YOUR SOURCE STRING NEAR "<<temp;
                      getch();
                      exit(1);
                }
                strcpy(tt,"");
                strcpy(tt,array[n][l]);
                strcpy(t3,"");
                f=0;
                for(c=0;c<strlen(tt);c++)
                {
                     t3[c]=tt[c];
                     t3[c+1]='\0';
                     if(strcmp(t3,temp)==0)
                     {
                           f=0;
                          break;
                     }
                     else
                           f=1;
                 }
                 if(f==0)
                 {
                    strcpy(temp,"");
                    strcpy(temp1,"");
                    strcpy(temp2,"");
                    strcpy(t,"");
                    i++;
                    k=0;
                    goto again;
                 }
                 else
                 {
                    strcpy(temp1,"");
                    strcpy(temp2,"");
                    strcpy(t,"");
                    goto again1;
                }
            }
          }
          i++;
          k++;
    }
    if(f1==0)
           cout <<setw(50)<< "\nENTERED STRING IS INVALID";
    else                     cout<<setw(200)<<"\n____________________________________________"<<endl;
                          cout <<endl<<setw(90)<<str1<<endl<<endl<<setw(95)<<"ACCEPTED"<<endl;
                          cout << endl<<setw(100)<<"ENTERED STRING IS VALID";
    getch();
}
