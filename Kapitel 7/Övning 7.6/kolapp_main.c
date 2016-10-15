#include <stdio.h>
#include "kolapp.h"
#define L "\n----------------------------------\n" //För snygga linjer i printf!
/*
Övning 7.6, Sida 145

Utöka modulen för kölappar med två funktioner:
init: nollställer variablerna sist och betjanad

betjanas: talar om vilken som var den senaste kunden som
senast var betjänad. Skriv om funktionen main så att man 
ser vilken kund som betjänas när man tar en lapp!


En modul är ett par av en .c-fil och en .h-fil
c-filen innehåller funktiondefinitoner, och h-filen
deklaration av funktionerna.
*/



int main(){
	printf("* LEK AFFÄR *");
	while(1){
		printf("%sSkriv:\n1 om du är kund\n0 om du är ledig i kassan\n2 om du vill återställa kölappar!%sVal: ",L,L); //Lagt till 2 för init (återställning)
		int kund;
		if (scanf("%d", &kund) != 1)
			break;
		if (kund == 1)
			printf("%sDu fick kölapp %d\nNu betjänas kund nr %d%s", L, ta_lapp(), betjanas(), L);//lagt till anrop för betjanas(), som returnerar den senaste kunde som betjänas
		else if (kund == 2){ //lagt till if-sats som triggar init om 2 slås in
			printf("%sÅterställer!%s",L,L);
			init();
			}
		else {
			int nr = betjana_kund();
			if (nr > 0)
				printf("%sDu är ledig i kassan!\nBetjäna nr: %d%s",L, nr, L);
			else {
				printf("%sInga kunder i kön!%s",L, L);
				}
		}
	}
}