#include <stdio.h>
#include <string.h>
#define N 25


/* Programmeringsuppgift 11.4, Sida 276

Skriv en funktion som kopierar en textstr�ng till en annan.
F�rutom pekare till str�ngarna ska funktionen f� en parameter
som anger storleken p� det f�lt dit texten ska kopieras.

Funktionen ska kontrollera att man inte skriver utanf�r f�ltet
OM en kopiering misslyckas, hur b�r man l�mpligast signalera
detta? 

SVAR: Anv�nd _Bool f�r funktionen och returnera 1/0 vid lyckad/misslyckad
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
	char text2[100] = "Jag ska hamna i text1 MEN JAG �R ALLDELES F�R L�NG ;((((((((((";
	if(kopieraText(text1, text2, N)){
		printf("Kopieringen lyckades!\nText i text1: %s", text1);
	}
	else{
		printf("Kopieringen misslyckades!\nText i text1: %s", text1);
	}
	return 0;
}