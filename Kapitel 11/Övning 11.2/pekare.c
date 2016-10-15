#include <stdio.h>

/* 
�vning 11.2, Sida 243

Deklarera en variabel 'x' av typen float, initiera den till 5.8.
Deklarera tv� pekare 'q1' och 'q2', som pekar till variabler av
typen float.

L�t q1 peka p� variabeln x och l�t q2 vara oinitierad.

F�rs�k skriva ut v�rderna f�r q1 och q2. Vad h�nder?
-- Man f�r ett v�rde fr�n bada utskrifterna

Blir det n�gon skillnad om man initerar q2 till NULL
-- V�rdet av pekaren q2 blir 0 vid utskriften

�ndra slutligen s� att programmet bara skriver ut v�rdet
av det variabeln q2 pekar p� om det inte �r en tom pekare.
Hade detta fungerat om du inte initierat q2?
-- Nej, den tilldelas ett slumpm�ssigt(?) v�rde om den inte initieras

 */

int main(){
	float x = 5.8, *q1 = &x, *q2 = NULL;
	printf("pekare q1: %d", q1);
	if (q2 != NULL){
		printf("\npekare q2: %d", q2);
	}
	return 0;
}