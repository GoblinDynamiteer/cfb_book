#include <stdio.h>
#include "bil.h"

/* �vning 12.2, Sida 2286

Skapa tv� bilar f�r struct 'bil' som skapades i �vning 12.1
Initiera den ena bilen p� ett l�mpligt s�tt.

Programmet ska inte ge n�gon utskrift.
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