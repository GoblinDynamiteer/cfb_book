#include <stdio.h>

/* Programmeringsuppgift 6.3, Sida 120

Skriv en funktion kallad primtal, den ska få ett heltal >0 som parameter 
och vara av typen _Bool. Funktionen ska avgöra om heltalet är ett primtal
och ge returvärdet 1 eller 0. 

Info:
Ett primtal är ett tal som enbart är jämnt delbart med sig själv eller talet 1
Talet ska vara större än 1

Primtal att testa med: 2, 3, 83, 89, 97, 77, 881, 883, 953, 967, 971, 977, 983, 991, 997

*/

//Funktion som testar om ett tal är ett primtal
_Bool primtal(int test_tal){
	//om talet är 1 returneras 0
	if (test_tal == 1){
		return 0; //en funktion avslutas när den ger ett returvärde
	}
	/* for-loop som testar om det inmatade talet är jämnt delbart 
	med något tal i intervallet 2 -> (talet-1).
	Om talet är delbart med något annat tal i intervallet så är det
	inget primtal och returvärdet 0 ges. */
	for(int i=2;i<test_tal;i++){
		if(test_tal % i == 0){
			return 0;
		}
	}
	/* funktionen ger returvärdet 1 om for-loopen kördes igenom utan
	att trigga if-satsen. (talet är ett primtal) */
	return 1;
}

int main(){
	//test av funktion:
	printf("Ange ett tal att testa: ");
	int tal;
	scanf("%d", &tal);
	//if-sats som triggar om funktionen primtal returnerar 1
	if(primtal(tal)){
		printf("Talet är ett primtal!");
	}
	else {
		printf("Talet är inte ett primtal!");
	}
	return 0;
}