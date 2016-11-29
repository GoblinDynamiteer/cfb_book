/*
Programmeringsuppgift 6.7, Sida 122

Du har vunnit p� Lotto! Du s�tter in pengarna
p� banken. 

Skriv en funktion som ber�knar hur l�nge pengarna
r�cker om du vill ta ut en viss summa varje �r.

Funktionen ska ha parametrarna: 
vinstumma, r�ntesats och belopp som man vill ta ut

om r�ntan g�r s� att du inte g�r back efter varje �r
(allts� att pengarna r�cker f�r evigt), s� ska funktionen
ge svar INT_MAX, som finns i limits.h

INT_MAX �r en konstant f�r det st�rsta v�rde int kan ha.

*/

#include <stdio.h>
#include <limits.h> //F�r konstanten INT_MAX

#define RANTA 4 //i procent
#define VINSTUMMA 15000000 //15 miljoner
#define UTTAG 1000000 //1 miljon

int lottoBank(long int vinst, int ranta, int uttag);

int main(){
	printf("Pengarna r�cker i %d �r!", lottoBank(VINSTUMMA, RANTA, UTTAG));
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
