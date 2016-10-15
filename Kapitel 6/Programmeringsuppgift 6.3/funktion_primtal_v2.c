#include <stdio.h>

/* Programmeringsuppgift 6.3, Sida 120

Skriv en funktion kallad primtal, den ska f� ett heltal >0 som parameter 
och vara av typen _Bool. Funktionen ska avg�ra om heltalet �r ett primtal
och ge returv�rdet 1 eller 0. 

Info:
Ett primtal �r ett tal som enbart �r j�mnt delbart med sig sj�lv eller talet 1
Talet ska vara st�rre �n 1

Primtal att testa med: 2, 3, 83, 89, 97, 77, 881, 883, 953, 967, 971, 977, 983, 991, 997

*/

//Funktion som testar om ett tal �r ett primtal
_Bool primtal(int test_tal){
	//om talet �r 1 returneras 0
	if (test_tal == 1){
		return 0; //en funktion avslutas n�r den ger ett returv�rde
	}
	/* for-loop som testar om det inmatade talet �r j�mnt delbart 
	med n�got tal i intervallet 2 -> (talet-1).
	Om talet �r delbart med n�got annat tal i intervallet s� �r det
	inget primtal och returv�rdet 0 ges. */
	for(int i=2;i<test_tal;i++){
		if(test_tal % i == 0){
			return 0;
		}
	}
	/* funktionen ger returv�rdet 1 om for-loopen k�rdes igenom utan
	att trigga if-satsen. (talet �r ett primtal) */
	return 1;
}

int main(){
	//test av funktion:
	printf("Ange ett tal att testa: ");
	int tal;
	scanf("%d", &tal);
	//if-sats som triggar om funktionen primtal returnerar 1
	if(primtal(tal)){
		printf("Talet �r ett primtal!");
	}
	else {
		printf("Talet �r inte ett primtal!");
	}
	return 0;
}