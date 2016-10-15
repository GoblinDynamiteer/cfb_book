
#include <stdio.h>

/*
�vning 9.2, Sida 192

Skriv ett program som l�ser allt anv�ndaren skriver in
och som resultat skriver ut hur m�nga tecken anv�ndaren
skrivit. Inmatningen avslutas med EOF.
*/

int main(){
	int c, raknare=0;
	printf("Sl� in tecken och avsluta med EOF (CTRL+Z i Windows)");
	//While-sats som k�rs s� l�nge anv�ndaren inte matar in EOF
	while(c=getchar() != EOF){
		raknare++; //�kar r�knare med 1 f�r varje inmatat tecken
	}
	printf("Antal tecken inslagna: %d", raknare);
	return 0;
}
