#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 300

/* Programmeringsuppgift 10.5, Sida 237

Skriv ett program som läser in en befintlig textfil och 
söker efter de rader i filen som innehåller en viss text.
De funna raderna ska kopieras till en ny fil.

Filnamnen ska läsas in från kommandofönstret. 

filer:
werther.txt
kafka.txt

exempel-ord: soul 			(5 rader kafka)
exempel-ord: sanctuary 	(2 rader werther)
*/

int main(){
	char infil_namn[N], utfil_namn[N], s[N], sok[N];
	int rader_kopierade = 0;
	printf("Ange infilens namn: ");
	radInput(infil_namn, N);
	printf("Ange utfilens namn: ");
	radInput(utfil_namn, N);
	printf("Söktext: ");
	radInput(sok, N);
	FILE *infil = fopen(infil_namn, "r");
	FILE *utfil = fopen(utfil_namn, "w");
	//Egen funktion, skriver från textfil till variabel s, returnerar 0 när klar
	while(textfilTillString(s, N, infil)){
		//printf("%s\n", s);
		if(strstr(s, sok) != NULL){
			fprintf(utfil,"%s\n", s);
			rader_kopierade++;
		}
	}
	printf("Ordet %s hittades i %d rader - kopierade till %s", sok, rader_kopierade, utfil);
	fclose(infil); 
	fclose(utfil);
	return 0;
}