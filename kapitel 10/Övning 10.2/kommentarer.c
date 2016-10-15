#include <stdio.h>
#include <string.h>

/* Skriv ett program som läser in en .c-fil. Programmet ska fråga efter filens namn.
Programmet ska undersöka vilka rader i filen som innehåller kommentarer.
anta att endast // används för kommentering. Programmet ska skriva ut hur
många procent av raderna som innehåller kommentarer 

Tips: Avänds strstr

strstr(x,y) där x och y är textsträngar, returnerar substrängen efter det att y hittats i x.
om strängen ej finns i x returneras NULL

ex: 
printf("%s\n", strstr("hejhajhoj", "haj")); //skriver ut "hajhoj"
printf("%s", strstr("hejhajhoj", "kalle")); //returnerar NULL - skriver ut (null)

*/

int main(){
	char filnamn[30], /* = "cfilmedkommentarer.c", */s[300]; //ska innehålla 12 st "//" och har 80 rader
	//char filnamn[30] = "5rader2kommentarer.c", s[100]; //ska innehålla 2 st "//" och har 5 rader
	printf("Ange filnamn: ");
	scanf("%s", filnamn);
	FILE * cfil = fopen(filnamn, "r");
	//räknare för antal rader och kommentarer
	int rader = 0, kommentarer = 0;
	/*
	whilesats som körs så länge fgets inte returnerar NULL (slut på tecken i textfilen), fgets läser in text till variabeln s.
	inläsning görs en rad i taget, eller tills 300 (i detta fall) tecken lästs in. Om en textrad i filen är längre än 300 tecken
	så kommer rader++ trigga även om raden inte är slut.
	*/
	while (fgets(s,300, cfil) != NULL){
		rader++;
		//om strstr inte returnerar NULL, så har strängen "//" hittats i s, kommentar-räknaren ökar med 1
		if (strstr(s, "//") != NULL){
			kommentarer++;
		}
	}
	//(double) framför variabeln kommentarer konverterar den till en double, för att undvika heltalsdivision vid beräkning av procent
	printf("kommentarer: %d, rader: %d. Procent: %.1f %", kommentarer,rader,(double)kommentarer/rader*100);
	return 0;
}