#include <stdio.h>

/* 
Övning 11.2, Sida 243

Deklarera en variabel 'x' av typen float, initiera den till 5.8.
Deklarera två pekare 'q1' och 'q2', som pekar till variabler av
typen float.

Låt q1 peka på variabeln x och låt q2 vara oinitierad.

Försök skriva ut värderna för q1 och q2. Vad händer?
-- Man får ett värde från bada utskrifterna

Blir det någon skillnad om man initerar q2 till NULL
-- Värdet av pekaren q2 blir 0 vid utskriften

Ändra slutligen så att programmet bara skriver ut värdet
av det variabeln q2 pekar på om det inte är en tom pekare.
Hade detta fungerat om du inte initierat q2?
-- Nej, den tilldelas ett slumpmässigt(?) värde om den inte initieras

 */

int main(){
	float x = 5.8, *q1 = &x, *q2 = NULL;
	printf("pekare q1: %d", q1);
	if (q2 != NULL){
		printf("\npekare q2: %d", q2);
	}
	return 0;
}