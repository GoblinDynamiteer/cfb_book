#include <stdio.h>
#include "bil.h"

/* Övning 12.2, Sida 2286

Skapa två bilar för struct 'bil' som skapades i övning 12.1
Initiera den ena bilen på ett lämpligt sätt.

Programmet ska inte ge någon utskrift.
*/

int main(){
	struct bil bil1;
	struct bil bil2 = {.regNr = "SZS351", .fabrikat = "Volvo V70"};
/* 	bil2.regNr = "SZS351";
	bil2.fabrikat = "Volvo V70"; */
	bil2.arsModell = 2001;
	bil2.tjansteVikt = 1610;
	bil2.motorEffekt = 103000; //103kW
	//printf("regnr: %s", bil2.regNr);
	//printf("Motoreffekt: %d kW", bil2.motorEffekt/1000);
	return 0;
}