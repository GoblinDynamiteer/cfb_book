#include <stdio.h>
#include "bil.h"

/* Övning 12.3, Sida 288

Komplettera programmet i övning 12.2, så att båda bilarna tilldelas lämpliga
värden. Skriv sedan ut värdena för de båda bilarna.
*/

int main(){
	struct bil bil1 = {.regNr = "SZS361", .fabrikat = "Polaris BIG Boss 6X6", .arsModell = 2002, .tjansteVikt = 420, .motorEffekt = 23000};
	struct bil bil2 = {.regNr = "SZS351", .fabrikat = "Volvo V70"};
	bil2.arsModell = 2001;
	bil2.tjansteVikt = 1610;
	bil2.motorEffekt = 103000; //103kW
	printf("Fordon 1:\nRegistreringsnummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt: %d kg\nMotoreffekt: %d kW", bil1.regNr, bil1.fabrikat, bil1.arsModell, bil1.tjansteVikt, bil1.motorEffekt/1000);
	printf("\n\nFordon 2:\nRegistreringsnummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt: %d kg\nMotoreffekt: %d kW", bil2.regNr, bil2.fabrikat, bil2.arsModell, bil2.tjansteVikt, bil2.motorEffekt/1000);
	return 0;
}
