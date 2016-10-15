
#include <stdio.h>

/*
Övning 9.2, Sida 192

Skriv ett program som läser allt användaren skriver in
och som resultat skriver ut hur många tecken användaren
skrivit. Inmatningen avslutas med EOF.
*/

int main(){
	int c, raknare=0;
	printf("Slå in tecken och avsluta med EOF (CTRL+Z i Windows)");
	//While-sats som körs så länge användaren inte matar in EOF
	while(c=getchar() != EOF){
		raknare++; //ökar räknare med 1 för varje inmatat tecken
	}
	printf("Antal tecken inslagna: %d", raknare);
	return 0;
}
