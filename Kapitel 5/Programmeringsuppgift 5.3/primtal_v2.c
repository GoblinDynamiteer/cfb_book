#include <stdio.h>

/* Programmeringsuppgift 5.3, Sida 99

Använd programmet på sida 98 som förebild och skriv ett 
nytt program som läser in ett positivt heltal 'n'. Skriv sedan 
ut alla primtal som är större eller lika med 'n'.

Högst 10 primtal ska visas per rad!

Info:
Ett primtal är ett tal som enbart är jämnt delbart med sig själv eller talet 1
Talet ska vara större än 1
*/


int main(){
	//Variabler för inmatning av det positiva heltalet, samt en räknare för när newline ska skrivas ut
	int n, nyrad = 0;
	_Bool ar_primtal;
	printf("Ange ett positivt heltal: ");
	scanf("%d", &n);
	printf("Primtal:\n");
	/* 
	Den yttre for-satsen kör lika många gånger som det inmatade värdet till variabeln 'n' är stort. 
	Det minsta primtalet är 2, därför sätts i till 2. i är det tal som ska undersökas, om det är ett primtal.
	
	För varje nytt varv sätts ar_primtal till 1, den andra for-satsen undersöker om talet i är jämnt delbart med 
	något av talen i intervallet 2 -> i-1. I såfall sätts ar_primtal till 0.
	*/
	for(int i = 2; i<=n;i++){
		ar_primtal = 1;
		for(int delning = 2;delning<i;delning++){
			if(i % delning == 0){
				ar_primtal = 0;
			}
		}
		//if-sats som triggar om ar_primtal == 1, i skrivs ut, då det är ett primtal
		if(ar_primtal){
			printf("%5d ", i); //%5d innebär att utskriften kommer högerjusteras med minst 5 tecken (likt Excel-celler med siffror)
			nyrad++; //nyrad ökar med 1 för varje utskrivet primtal, om nyrad når 10 skrivs en ny rad ut och nyrad sätts till 0
			if(nyrad == 10){
				printf("\n");
				nyrad = 0;
			}
		}
	}
	return 0;
}