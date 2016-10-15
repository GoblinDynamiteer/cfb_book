#include <stdio.h>
#include "kolapp.h"
#define L "\n----------------------------------\n" //F�r snygga linjer i printf!
/*
�vning 7.6, Sida 145

Ut�ka modulen f�r k�lappar med tv� funktioner:
init: nollst�ller variablerna sist och betjanad

betjanas: talar om vilken som var den senaste kunden som
senast var betj�nad. Skriv om funktionen main s� att man 
ser vilken kund som betj�nas n�r man tar en lapp!


En modul �r ett par av en .c-fil och en .h-fil
c-filen inneh�ller funktiondefinitoner, och h-filen
deklaration av funktionerna.
*/



int main(){
	printf("* LEK AFF�R *");
	while(1){
		printf("%sSkriv:\n1 om du �r kund\n0 om du �r ledig i kassan\n2 om du vill �terst�lla k�lappar!%sVal: ",L,L); //Lagt till 2 f�r init (�terst�llning)
		int kund;
		if (scanf("%d", &kund) != 1)
			break;
		if (kund == 1)
			printf("%sDu fick k�lapp %d\nNu betj�nas kund nr %d%s", L, ta_lapp(), betjanas(), L);//lagt till anrop f�r betjanas(), som returnerar den senaste kunde som betj�nas
		else if (kund == 2){ //lagt till if-sats som triggar init om 2 sl�s in
			printf("%s�terst�ller!%s",L,L);
			init();
			}
		else {
			int nr = betjana_kund();
			if (nr > 0)
				printf("%sDu �r ledig i kassan!\nBetj�na nr: %d%s",L, nr, L);
			else {
				printf("%sInga kunder i k�n!%s",L, L);
				}
		}
	}
}