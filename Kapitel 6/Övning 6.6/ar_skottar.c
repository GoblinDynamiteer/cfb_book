#include <stdio.h>

/*
Uppgift 6.6, Sida 115
Skriv om programmet för skottår på sida 67. 
Det ska använda en funktion som returnerar sanningsvärde (1/0). 
Funktionen ska heta ar_skottar och ha int som parameter.


Krav för skottår:
Jämt delbara med 4:
OM år % 4 == 0  (heltalsdivision med 4 har ingen rest)

MEN INTE om de är jämt delbara med 4 OCH 100!
OM år % == 0 && år % 100 != 0

ELLER om jämnt delbart med 400
(år % == 0 && år % 100 != 0) || (år % 400 == 0)

*/

_Bool ar_skottar(int ar){
		return (ar % 4 == 0 && 100 != 0) || (ar % 400 == 0);
};

int main(){
	int ar; //år
	printf("Skriv in ett år: ");
	scanf("%d", &ar);
	if (ar_skottar(ar))
		printf("Skottår!");
	else 
		printf("Ej Skottår ;(");
	return 0;
}