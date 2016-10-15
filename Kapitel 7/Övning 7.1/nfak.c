/*
Övning 7.1, Sida 128

Skriv en ny version av programmet i övning 6.2

Lägg funktionen nfak i en egen fil.

*/

#include "nfak.h"

//funktion för att beräkna fakulteten av ett tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}