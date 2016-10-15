/*
�vning 7.5, Sida 143

Programmet ger INNAN �ndring
a=1, b=1 c=1
a=3, b=1 c=2

STEG: 
a �r STATISK
main anropar f()
	b initieras som INTE STATISK
	c initieras som STATISK
	f() �kar a,b,c med 1 och skriver ut detta
�ter main
	a �r STATISK och har kvar sitt v�rde 1
	b �r INTE STATISK och har nu tappat sitt v�rde efter att funktionen �r klar
	c �r STATISK och har kvar sitt v�rde 1
	main �kar a med 1 (till 2)
main anropar f()
	b har tappats och �terinitieras igen till 0 som INTE STATISK
	c �r STATISK och har ett v�rde, initering av c utf�rs enbart f�rsta g�ngen f() k�rs, c beh�ller sitt v�rde 1
	f() �kar a,b,c med 1 och skriver ut detta (a=2+1) (b=0+1) (c=1+1)

UPPGIFT:
Vilken utskrift f�r programmet om man ers�tter:
static int c = 0;
med
static int c;
c = 0;

Utskrift efter �ndring:
a=1, b=1 c=1
a=3, b=1 c=1

F�rklara varf�r
likt int b = 0 i funktionen s� blir c INTE STATISK och tappar sitt v�rde n�r funktionen har k�rt k�rt klart.
samt �ters�tts c = 0, varje g�ng funktionen k�rs

*/

#include <stdio.h>
int a = 0;

void f(){
	int b = 0;
	static int c = 0;
	printf("a=%d, b=%d c=%d\n", ++a, ++b, ++c);
}

int main(){
	f();
	++a;
	f();
}