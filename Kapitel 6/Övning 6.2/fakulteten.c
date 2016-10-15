#include <stdio.h>

/*
�vning 6.2, Sida 110

Skriv en funktion i programmet som r�knar ut "fakulteten" f�r inmatat tal n, 
n ska matas in i den vanliga main-funktionen.

Funktionen ska heta nfak

fakulteten inneb�r produkten av 1*2*3*4*5*....n

*/

//funktion f�r att ber�kna fakulteten av ett tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}

int main(){
	double tal;
	printf("Ange ett tal f�r att ber�kna dess fakultet: ");
	scanf("%lf", &tal);
	printf("Fakulteten f�r talet �r %.0lf", nfak(tal));
	return 0;
}