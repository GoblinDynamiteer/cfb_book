#include <stdio.h>
#include "nfak.h" //inneh�ller definitionen av nfak();

/*
�vning 7.1, Sida 128

Skriv en ny version av programmet i �vning 6.2

L�gg funktionen nfak i en egen fil.

f�r att kompilera tv� .c-filer:
gcc fakulteten_include.c nfak.c -o fakulteten_include.exe

*/

int main(){
	double tal;
	printf("Ange ett tal f�r att ber�kna dess fakultet: ");
	scanf("%lf", &tal);
	printf("Fakulteten f�r talet �r %.0lf", nfak(tal));
	return 0;
}