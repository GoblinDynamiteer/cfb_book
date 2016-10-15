#include <stdio.h>

/*
Programmeringsuppgift 6.3, sida 120

Skriv en _Bool funktion som heter primtal, som ger v�rde 1 eller 0
Funktionen ska f� ett heltal (>0)
*/

//fuktion som testar om ett tal �r ett primtal, returnerar 1 om sant, 0 om falskt
_Bool primtal(int t){
	for (int k=2;k<t;k++){
		if (t % k == 0)
			return 0; //funktionen avslutas n�r den ger sitt f�rsta returv�rde (sant?)
	}
	return 1;
}

int main(){
	int tal;
	printf("Ange ett tal, f�r test om det �r ett primtal: ", tal);
	scanf("%d", &tal);
	if (primtal(tal)) //if-sats som k�rs om funktionen primtal returnerar 1
		printf("%d �r ett primtal!", tal);
	else
		printf("%d �r inte ett primtal!", tal);
	return 0;
}