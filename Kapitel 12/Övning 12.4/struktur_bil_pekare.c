#include <stdio.h>
#include "bil.h"

/* �vning 12.4, Sida 292

G�r om programmet i �vning 12.3.
Anv�nd tv� pekare f�r att skriva ut informationen fr�n bil-structen.
*/

void skrivUtStructMedPekare(struct bil *p){
	printf("Registreringsnummer: %s\nFabrikat: %s\n�rsmodell: %d\nTj�nstevikt: %d kg\nMotoreffekt: %d kW", (*p).regNr, (*p).fabrikat, (*p).arsModell, (*p).tjansteVikt, (*p).motorEffekt/1000);
}

int main(){
	struct bil bil1 = {.regNr = "SZS361", .fabrikat = "Polaris BIG Boss 6X6", .arsModell = 2002, .tjansteVikt = 420, .motorEffekt = 23000};
	struct bil bil2 = {.regNr = "SZS351", .fabrikat = "Volvo V70"};
	bil2.arsModell = 2001;
	bil2.tjansteVikt = 1610;
	bil2.motorEffekt = 103000; //103kW
	printf("Utskrift utan pekare: \n\n");
	printf("Fordon 1:\nRegistreringsnummer: %s\nFabrikat: %s\n�rsmodell: %d\nTj�nstevikt: %d kg\nMotoreffekt: %d kW", bil1.regNr, bil1.fabrikat, bil1.arsModell, bil1.tjansteVikt, bil1.motorEffekt/1000);
	printf("\n\nFordon 2:\nRegistreringsnummer: %s\nFabrikat: %s\n�rsmodell: %d\nTj�nstevikt: %d kg\nMotoreffekt: %d kW", bil2.regNr, bil2.fabrikat, bil2.arsModell, bil2.tjansteVikt, bil2.motorEffekt/1000);
	struct bil *pekare_bil; //Jag anv�nde endast 1 pekare, ville prova hur det fungerar med att s�tta den till olika struct
	pekare_bil = &bil1;
	printf("\n\nUtskrift med pekare (och funktion): \n");
	skrivUtStructMedPekare(pekare_bil);
	pekare_bil = &bil2;
	printf("\n\n");
	skrivUtStructMedPekare(pekare_bil+1);
	return 0;
}
