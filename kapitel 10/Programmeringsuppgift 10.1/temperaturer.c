#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //f�r INT_MIN
#include <math.h> //f�r fmax
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 100

/* Programmeringsuppgift 10.1, Sida 236

En textfil inneh�ller temperaturer som uppm�tts kl 13 under en m�nad,
p� en viss plats. Det finns en temperatur p� varje rad
Skriv ett program som l�ser filen och i kommando-
f�nstret visar den h�gsta temperaturen samt temperaturernas medelv�rde.

Namnet p� filen ska l�sas in fr�n tangentbordet. 

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
Maxv�rde: 24
Medelv�rde: 21,5
*/

int main(){
	//s �r h�llare av text fr�n textfilen
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
		//l�ser in siffran till tempHallare
		sscanf(s, "%d", &tempHallare);
		//summerar temperaturerna
		tempSumma += tempHallare;
		max_temp = fmax(max_temp, tempHallare);
		//r�knar antal rader i textfilen
		rader++;
	}
	//konstanten 176 �r grader-tecknet, skrivs ut med %c - tempSumma/rader = medelv�rdet, konverterar till float f�r decimalutskrift
	printf("Max temperatur: %d%c\nMedelv�rde temperatur: %.2f%c", max_temp, 176, (float)tempSumma/rader, 176);
	return 0;
}