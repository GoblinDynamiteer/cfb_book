#include <stdio.h>

/*
Programmeringsuppgift 6.3, sida 120

Skriv en _Bool funktion som heter primtal, som ger värde 1 eller 0
Funktionen ska få ett heltal (>0)
*/

//fuktion som testar om ett tal är ett primtal, returnerar 1 om sant, 0 om falskt
_Bool primtal(int t){
	for (int k=2;k<t;k++){
		if (t % k == 0)
			return 0; //funktionen avslutas när den ger sitt första returvärde (sant?)
	}
	return 1;
}

int main(){
	int tal;
	printf("Ange ett tal, för test om det är ett primtal: ", tal);
	scanf("%d", &tal);
	if (primtal(tal)) //if-sats som körs om funktionen primtal returnerar 1
		printf("%d är ett primtal!", tal);
	else
		printf("%d är inte ett primtal!", tal);
	return 0;
}