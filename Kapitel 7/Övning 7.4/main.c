#include <stdio.h>

/*
Övning 7.4, Sida 141

Vad händer om man stryker static från variabeldeklarationen i 
filen g.c?
--SVAR:
gcc ger felet: "multiple definition of `a'"
Två (eller flera) externa variabler inom samma synlighetsområde får inte ha samma namn!
både a i g.c och a i main.c blir externa variabler

int a = extern int a;
*/


int f(void);
int g(void);

int a = 1;
int b;

int main(){
	printf("f()=%d\n" ,f());
	printf("f()=%d\n" ,f());
	printf("g()=%d\n" ,g());
}

