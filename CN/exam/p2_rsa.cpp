/*
Description: Write a program for simple RSA algorithm to encrypt and decrypt the data.
RSA ALGORITHM
-------------
1.Generate two large random primes, p and q, of approximately equal size.
2.Compute n=p*q;
3.Calculate another number Φ=(p-1)*(q-1)
4.Choose a random number e. Then calculate d so that d*e=1 mod phi
5.We can now announe e and n to public. Φ and d is kept secret
  Hence, the public key is (n, e) and the private key is (Φ, d).
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long int ulint; // To avoid typing "unsigned long int" all the time.

using namespace std;

ulint e,n,cipher[50];
int len;

ulint gcd(ulint a,ulint b){
    if(a==0) return b;
    if(b==0) return a;
    return gcd(b ,a%b);
}

bool prime(ulint a){
    int i;
    for(i = 2; i < a; i++)
        if((a%i) == 0)
            return false;
    return true;
}


class bob // The server
{
private:
    ulint phi,d,p,q; // Shh...
    char msg[50];
public:

    // To find prime numbers P&Q, Public Key n & e, Private key Φ & d.
    void genKeys(){
        // P
        do{
            p = rand()%30;
        } while( !prime(p) );

        // Q
        do {
            q = rand()%30;
        } while( !prime(q) );

        //n & Φ formula
        n=p*q;
        phi = (p-1)*(q-1);

        // e
        do {
            e = rand()%phi;
        } while( gcd(e,phi) != 1 );

        // d
        do {
            d = rand()%phi;
        } while( ((d*e)%phi) != 1 );
    }

    void dispMsg(){
        int i;
        //Decrypt the cipher msg
        for(i = 0; i < len; i++){
            msg[i]=decrypt(cipher[i]);
        }
        msg[i]='\0'; // Array termination
        cout<<"\nDecrypted message: "<<msg<<endl;
    }

    char decrypt(ulint ch) {
        ulint temp=ch;
        for(int i = 1; i < d; i++)
            ch=(temp*ch)%n;
        return ch;
    }

    void dispData(){
        cout<<"\n\nPrime number P: "<<p<<" and Q: "<<q<<endl;
        cout<<"n = "<<p<<" * "<<q<<" = "<<n<<endl;
        cout<<"Φ = "<<p-1<<" * "<<q-1<<" = "<<phi<<endl;
        cout<<"Public Variables n, e : "<<n<<", "<<e<<"\n";
        cout<<"Private Variables Φ, d : "<<phi<<", "<<d<<"\n";
    }

    
};

class alice // User
{

private: 
    char msg[50];
public:

    void getMsg(){
        cout<<"Enter the message to encrypt: ";
        cin.getline(msg,sizeof(msg)); 			// To take in spaces in the string.
        len = strlen(msg);

        // Encrypt text 1 char at a time, store it in cipher
        for(int i = 0; i < len; i++)
            cipher[i]=encrypt(msg[i]);

        cout<<"\nEncrypted message: ";
        
        for(int i = 0; i < len; i++)
            cout<<cipher[i]<<" ";
    }

    // Client encrypts with the public key of server (e) so only server can decrypt it using (d)
    ulint encrypt(char ch){
        ulint temp=ch;
        for(int i = 1; i < e; i++)
            temp=(temp*ch)%n;
        return temp;
    }
};




int main(){
    alice a;
    bob b;
    b.genKeys(); // Calculates required public keys
    a.getMsg();
    b.dispMsg();
    return 0;
}


