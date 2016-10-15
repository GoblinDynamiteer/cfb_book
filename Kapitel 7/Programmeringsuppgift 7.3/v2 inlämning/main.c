#include <stdio.h>
#include "area.h"

/* Programmeringsuppgift 7.3, Sida 147
Johan Kämpe

Skapa ett funktionsbibliotek 'area', som innehåller
funktioner för att beräkna arean av en cirkel, en triangel
och en rektangel. */

int main(){
	//Test för funktioner, ingick dock inte i uppgiften.
	double radie = 2.0, bas = 10.0, hojd = 15.5;
	printf("Arean av en cirkel med radien %.2f är %.2f\n", radie, area_cirkel(radie));
	printf("Arean av en rektangel med basen %.2f, och höjden %.2f är %.2f\n", bas, hojd, area_rektangel(bas, hojd));
	printf("Arean av en triangel med basen %.2f, och höjden %.2f är %.2f\n", bas, hojd, area_triangel(bas, hojd));
	return 0;
}