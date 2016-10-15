#include <stdio.h>
#include "bil.h" //Deklaration av struct bil

/* Övning 12.4, Sida 292

Gör om programmet i övning 12.3.
Använd två pekare för att skriva ut informationen från bil-structen.
*/

void skrivUtStructMedPekare(struct bil *p){
	printf("Registreringsnummer: %s\n",(*p).regNr);
	printf("Fabrikat: %s\n", (*p).fabrikat);
	printf("Årsmodell: %d\n", (*p).arsModell);
	printf("Tjänstevikt: %d kg\n", (*p).tjansteVikt);
	printf("Motoreffekt: %d kW", (*p).motorEffekt/1000);
}

int main(){
	//Från övning 12.3:
	struct bil bil1 = {
		.regNr = "SZS361",
		.fabrikat = "Polaris BIG Boss 6X6",
		.arsModell = 2002,
		.tjansteVikt = 420,
		.motorEffekt = 23000
	};

	struct bil bil2 = {
		.regNr = "SZS351",
		.fabrikat = "Volvo V70"
	};

	bil2.arsModell = 2001;
	bil2.tjansteVikt = 1610;
	bil2.motorEffekt = 103000; //103kW

	//Pekare till struct:
	struct bil *pekare_bil;
	//Pekaren sätts till addressen för bil1
	pekare_bil = &bil1;
	printf("Utskrift med pekare (och funktion): \n");
	//Skriver ut värden för bil1 med funktion:
	skrivUtStructMedPekare(pekare_bil);
	//Pekaren sätts till addressen för bil2
	pekare_bil = &bil2;
	printf("\n\n");
	//Skriver ut värden för bil2 med funktion:
	skrivUtStructMedPekare(pekare_bil);
	return 0;
}
