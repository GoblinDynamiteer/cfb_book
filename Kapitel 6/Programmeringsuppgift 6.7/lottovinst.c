#include <stdio.h>
#include <limits.h> //För konstanten INT_MAX

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

//funktion för att beräkna hur länge lottovinsten räcker, med bankränta och årliga uttag
int lotto(double s, double r,  double u){ //s= saldo, r = ränta, u = uttag
	int ar = 0; //år
	//OM räntan för saldot på kontot (vinstumman vid start) är större än eller lika med uttag:
	if (s*r/100 >= u){ 
		//printf("Jag triggade (INT_MAX!)";
		return INT_MAX;
		}
	while(1){
		s = (s + (s*(r/100))) - u;
		//printf("år: %d - saldo efter ränta och uttag: %lf\n", ar, saldo);
		ar++;
		if (s<0) //om pengarna har tagit slut på kontot (negativt värde på saldot) returneras år
			return ar;
	}
}


int main(){
	double vinstsumma, ranta, uttag;
	printf("Ange vinstumma: ");
	scanf("%lf", &vinstsumma);
	printf("Ange årsränta hos banken: ");
	scanf("%lf", &ranta);
	printf("Ange hur stort uttag du vill göra varje år: ");
	scanf("%lf", &uttag);
	printf("Dina pengar räcker i %d år!", lotto(vinstsumma,ranta,uttag));
	return 0;
}