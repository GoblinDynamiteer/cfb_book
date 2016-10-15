#include <stdio.h>

/*
Programmeringsuppgift 6.2, Sida 120

Skriv en funktion som beräknar vad en vara kostar inklusive moms

Som parametrar ska funktionen få dels priset exklusive moms och 
momssatsen uttryckt i procent
*/

//Funktion för att beräkna pris inklusive moms,
double momsberakning(double p, int m){
	return p + p * (m/100.0);
	//ex 100 + 100 * (30/100) = 130
}

int main(){
	double pris; 
	int moms;
	printf("Ange pris exklusive moms: ");
	scanf("%lf", &pris);
	printf("Ange momssats i procent: ");
	scanf("%d", &moms);
	printf("Priset inklusive moms är: %.2lf kr", momsberakning(pris,moms));
	return 0;
}