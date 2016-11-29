/*
Programmeringsuppgift 6.7, Sida 122

Du har vunnit på Lotto! Du sätter in pengarna
på banken. 

Skriv en funktion som beräknar hur länge pengarna
räcker om du vill ta ut en viss summa varje år.

Funktionen ska ha parametrarna: 
vinstumma, räntesats och belopp som man vill ta ut

om räntan gör så att du inte går back efter varje år
(alltså att pengarna räcker för evigt), så ska funktionen
ge svar INT_MAX, som finns i limits.h

INT_MAX är en konstant för det största värde int kan ha.

*/

#include <stdio.h>
#include <limits.h> //För konstanten INT_MAX

#define RANTA 4 //i procent
#define VINSTUMMA 15000000 //15 miljoner
#define UTTAG 1000000 //1 miljon

int lottoBank(long int vinst, int ranta, int uttag);

int main(){
	printf("Pengarna räcker i %d år!", lottoBank(VINSTUMMA, RANTA, UTTAG));
	return 0;
}

int lottoBank(long int vinst, int ranta, int uttag){
	int summaKvar = vinst, antalAr=0;
	while(1){
		antalAr++;
		summaKvar += (double)summaKvar * ranta/100.0;
		summaKvar -= uttag;
		if(summaKvar <= 0){
			break;
		}
		if(summaKvar > vinst){
			return INT_MAX;
		}
	}
	return antalAr;
}
