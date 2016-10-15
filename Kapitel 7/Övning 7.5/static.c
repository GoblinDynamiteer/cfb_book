/*
Övning 7.5, Sida 143

Programmet ger INNAN ändring
a=1, b=1 c=1
a=3, b=1 c=2

STEG: 
a är STATISK
main anropar f()
	b initieras som INTE STATISK
	c initieras som STATISK
	f() ökar a,b,c med 1 och skriver ut detta
åter main
	a är STATISK och har kvar sitt värde 1
	b är INTE STATISK och har nu tappat sitt värde efter att funktionen är klar
	c är STATISK och har kvar sitt värde 1
	main ökar a med 1 (till 2)
main anropar f()
	b har tappats och återinitieras igen till 0 som INTE STATISK
	c är STATISK och har ett värde, initering av c utförs enbart första gången f() körs, c behåller sitt värde 1
	f() ökar a,b,c med 1 och skriver ut detta (a=2+1) (b=0+1) (c=1+1)

UPPGIFT:
Vilken utskrift får programmet om man ersätter:
static int c = 0;
med
static int c;
c = 0;

Utskrift efter ändring:
a=1, b=1 c=1
a=3, b=1 c=1

Förklara varför
likt int b = 0 i funktionen så blir c INTE STATISK och tappar sitt värde när funktionen har kört kört klart.
samt återsätts c = 0, varje gång funktionen körs

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