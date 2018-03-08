#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// typedef unsigned long int int;

using namespace std;

int e,n,cipher[50];
int len;

int gcd(int a, int b){
	if (a == 0) return b;
	if (b == 0) return a;
	return (gcd(b,a%b));
}

bool prime(int a){
	int i;
	for (int i = 2; i < a; i++)
		if ((a%i) == 0)
			return false;
	return true;
}

class bob
{
private:
	int phi,d,p,q;
	char msg[50];
public:
	void genKeys(){
		do{
			getProperPrime();
			n = p*q;
		}while (n > 255 && n < 65);
		
		phi = (p-1)*(q-1);
		do{
			e = rand()%100;
		} while( gcd(e,phi) != 1 );

		do{
			d = rand()%phi;
		} while( ((d*e)%phi) != 1 );
		
	}

	void getProperPrime(){
		do{
			p = rand()%30;
		}while ( !prime(p) );

		do{
			q = rand()%30;
		}while ( !prime(q) );
	}
	void dispMsg(){
		int i;
		cout<<"\nDecrypted Ascii message: ";
		for( i = 0; i < len; i++){
			msg[i]=decrypt(cipher[i]);
			cout<<(int)msg[i]<<" ";
		}
		msg[i]='\0';
		cout<<"\nDecrypted Message: "<<msg<<endl;
	}

	char decrypt(int ch) {
		int temp=ch;
		for (int i = 1; i < d; i++)
			ch = (temp*ch)%n;
		return ch;
	}
	
};

class alice{
private:
	char msg[50];
public:
	void getMsg(){
		cout<<"Enter message to encrypt: ";
		cin.getline(msg,sizeof(msg));
		len = strlen(msg);

		for (int i = 0; i < len; ++i)
			cipher[i] = encrypt(msg[i]);

		cout<<"\nAscii message: ";
		for (int i = 0; i < len; ++i)
			cout<<(int)msg[i]<<" ";

		cout<<"\nEncrypted message: ";

		for (int i = 0; i < len; ++i)
			cout<<(char)cipher[i]<<" ";
		
	}
	int encrypt(char ch){
		int temp=ch;
		for (int i = 1; i < e; ++i)
			temp = (temp*ch)%n;
		return temp;
	
	}
};

int main()
{
	bob a;
	alice b;

	a.genKeys();
	b.getMsg();
	a.dispMsg();
	int ac=65;
	cout<<endl<<(char)ac;
	return 0;
}