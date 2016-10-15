#include <stdio.h>
#include "nfak.h" //innehåller definitionen av nfak();

/*
Övning 7.1, Sida 128

Skriv en ny version av programmet i övning 6.2

Lägg funktionen nfak i en egen fil.

för att kompilera två .c-filer:
gcc fakulteten_include.c nfak.c -o fakulteten_include.exe

*/

int main(){
	double tal;
	printf("Ange ett tal för att beräkna dess fakultet: ");
	scanf("%lf", &tal);
	printf("Fakulteten för talet är %.0lf", nfak(tal));
	return 0;
}