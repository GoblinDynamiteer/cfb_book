#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //för INT_MIN
#include <math.h> //för fmax
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 100

/* Programmeringsuppgift 10.1, Sida 236

En textfil innehåller temperaturer som uppmätts kl 13 under en månad,
på en viss plats. Det finns en temperatur på varje rad
Skriv ett program som läser filen och i kommando-
fönstret visar den högsta temperaturen samt temperaturernas medelvärde.

Namnet på filen ska läsas in från tangentbordet. 

Info:
temperaturer.txt
23
24
21
22
19
19
22
18
24
24
22
23
21
23
22
18
18
23
24
21
22
19
19
22
18
24
24
22
23

---
Maxvärde: 24
Medelvärde: 21,5
*/

int main(){
	//s är hållare av text från textfilen
	char filnamn[N], s[N];
	int rader=0, max_temp = INT_MIN, tempSumma = 0, tempHallare;
	printf("Ange filnamn: ");
	radInput(filnamn, N); //finns i strings_text_v1.c
	FILE *temperatur_fil = fopen(filnamn, "r");
	if (temperatur_fil == NULL){
		printf("Kan inte hitta filen: %s, avslutar.", filnamn);
		exit(1);
	}
	while(textfilTillString(s, N, temperatur_fil)){ //finns i strings_text_v1.c
		//läser in siffran till tempHallare
		sscanf(s, "%d", &tempHallare);
		//summerar temperaturerna
		tempSumma += tempHallare;
		max_temp = fmax(max_temp, tempHallare);
		//räknar antal rader i textfilen
		rader++;
	}
	//konstanten 176 är grader-tecknet, skrivs ut med %c - tempSumma/rader = medelvärdet, konverterar till float för decimalutskrift
	printf("Max temperatur: %d%c\nMedelvärde temperatur: %.2f%c", max_temp, 176, (float)tempSumma/rader, 176);
	return 0;
}