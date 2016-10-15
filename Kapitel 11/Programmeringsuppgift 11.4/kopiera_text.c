#include <stdio.h>
#include <string.h>
#define N 25


/* Programmeringsuppgift 11.4, Sida 276

Skriv en funktion som kopierar en textsträng till en annan.
Förutom pekare till strängarna ska funktionen få en parameter
som anger storleken på det fält dit texten ska kopieras.

Funktionen ska kontrollera att man inte skriver utanför fältet
OM en kopiering misslyckas, hur bör man lämpligast signalera
detta? 

SVAR: Använd _Bool för funktionen och returnera 1/0 vid lyckad/misslyckad
kopiering av text.

*/

_Bool kopieraText(char till[], const char fran[], int langd_till){
	int langd_fran = strlen(fran);
	for(char *pekare=till;pekare<till+langd_till;pekare++){
		*pekare = *fran++;
	}
	if(langd_fran > langd_till){
		return 0;
	}
	return 1;
}

int main(){
	char text1[N] = "Hej";
	char text2[100] = "Jag ska hamna i text1 MEN JAG ÄR ALLDELES FÖR LÅNG ;((((((((((";
	if(kopieraText(text1, text2, N)){
		printf("Kopieringen lyckades!\nText i text1: %s", text1);
	}
	else{
		printf("Kopieringen misslyckades!\nText i text1: %s", text1);
	}
	return 0;
}