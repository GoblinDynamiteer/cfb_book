#include <stdio.h>

/*
Uppgift 6.6, Sida 115
Skriv om programmet f�r skott�r p� sida 67. 
Det ska anv�nda en funktion som returnerar sanningsv�rde (1/0). 
Funktionen ska heta ar_skottar och ha int som parameter.


Krav f�r skott�r:
J�mt delbara med 4:
OM �r % 4 == 0  (heltalsdivision med 4 har ingen rest)

MEN INTE om de �r j�mt delbara med 4 OCH 100!
OM �r % == 0 && �r % 100 != 0

ELLER om j�mnt delbart med 400
(�r % == 0 && �r % 100 != 0) || (�r % 400 == 0)

*/

_Bool ar_skottar(int ar){
		return (ar % 4 == 0 && 100 != 0) || (ar % 400 == 0);
};

int main(){
	int ar; //�r
	printf("Skriv in ett �r: ");
	scanf("%d", &ar);
	if (ar_skottar(ar))
		printf("Skott�r!");
	else 
		printf("Ej Skott�r ;(");
	return 0;
}