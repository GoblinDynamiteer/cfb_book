#include <stdio.h>

/*
Övning 6.2, Sida 110

Skriv en funktion i programmet som räknar ut "fakulteten" för inmatat tal n, 
n ska matas in i den vanliga main-funktionen.

Funktionen ska heta nfak

fakulteten innebär produkten av 1*2*3*4*5*....n

*/

//funktion för att beräkna fakulteten av ett tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}

int main(){
	double tal;
	printf("Ange ett tal för att beräkna dess fakultet: ");
	scanf("%lf", &tal);
	printf("Fakulteten för talet är %.0lf", nfak(tal));
	return 0;
}