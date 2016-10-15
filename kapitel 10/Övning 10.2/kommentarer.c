#include <stdio.h>
#include <string.h>

/* Skriv ett program som l�ser in en .c-fil. Programmet ska fr�ga efter filens namn.
Programmet ska unders�ka vilka rader i filen som inneh�ller kommentarer.
anta att endast // anv�nds f�r kommentering. Programmet ska skriva ut hur
m�nga procent av raderna som inneh�ller kommentarer 

Tips: Av�nds strstr

strstr(x,y) d�r x och y �r textstr�ngar, returnerar substr�ngen efter det att y hittats i x.
om str�ngen ej finns i x returneras NULL

ex: 
printf("%s\n", strstr("hejhajhoj", "haj")); //skriver ut "hajhoj"
printf("%s", strstr("hejhajhoj", "kalle")); //returnerar NULL - skriver ut (null)

*/

int main(){
	char filnamn[30], /* = "cfilmedkommentarer.c", */s[300]; //ska inneh�lla 12 st "//" och har 80 rader
	//char filnamn[30] = "5rader2kommentarer.c", s[100]; //ska inneh�lla 2 st "//" och har 5 rader
	printf("Ange filnamn: ");
	scanf("%s", filnamn);
	FILE * cfil = fopen(filnamn, "r");
	//r�knare f�r antal rader och kommentarer
	int rader = 0, kommentarer = 0;
	/*
	whilesats som k�rs s� l�nge fgets inte returnerar NULL (slut p� tecken i textfilen), fgets l�ser in text till variabeln s.
	inl�sning g�rs en rad i taget, eller tills 300 (i detta fall) tecken l�sts in. Om en textrad i filen �r l�ngre �n 300 tecken
	s� kommer rader++ trigga �ven om raden inte �r slut.
	*/
	while (fgets(s,300, cfil) != NULL){
		rader++;
		//om strstr inte returnerar NULL, s� har str�ngen "//" hittats i s, kommentar-r�knaren �kar med 1
		if (strstr(s, "//") != NULL){
			kommentarer++;
		}
	}
	//(double) framf�r variabeln kommentarer konverterar den till en double, f�r att undvika heltalsdivision vid ber�kning av procent
	printf("kommentarer: %d, rader: %d. Procent: %.1f %", kommentarer,rader,(double)kommentarer/rader*100);
	return 0;
}