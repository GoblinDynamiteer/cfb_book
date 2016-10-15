#include <stdio.h>

/*
Övning 6.3, Sida 111
Skriv en funktion som beräknar antalet siffror i ett heltal. Förutsätt att talet är större än noll.

Tips: Gör om funktionen siff_sum (sida 110), men räkna varv i stället för att beräkna summan
*/

int antal_siffror(int tal){
	int sum = 0, counter = 0;
	while(tal > 0){ //while-sats som kör så länge tal är större än 0
		tal /= 10; //heltalsdivision med 10, innebär att den sista siffran i talet försvinner för varje while-varv
		counter++; //räknare som ökar med ett för varje while-varv (räknar antal siffror)
	}
	return counter; //returnerar antalet siffror (varv som while-satsen kört)
}

int main(){
	int tal;
	printf("Ange ett tal, för att beräkna antal siffor det innehåller: ");
	scanf("%d", &tal);
	printf("Det finns %d siffror i %d", antal_siffror(tal), tal);
	return 0;
}