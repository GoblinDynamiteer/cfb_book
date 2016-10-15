#include <stdio.h>

/*
Programmeringsuppgift 6.8, Sida 122

Skriv en funktion som avgör om ett positivt tal är "perfekt".

Perfekta tal är tal där summan av talets produkter blir lika med talet
Jag antar att det är del tal där division går jämnt ut?

Faktor * Faktor = Produkt

https://www.wikiwand.com/sv/Perfekt_tal

Exempel: 
6 = 1 + 2 + 3	1
28 = 1 + 2 + 4 + 7 + 14
496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248
*/

//Funktion för avgörande om ett tal är perfekt
_Bool ar_perfekt_tal(int t){
	int summa = 0; 				//summan som ska jämföras med talet
	for(int i=1;i!=t;i++){		//körs så länge i inte är talet
	if (t % i == 0)					//om talet är jämnt delbart med i, så adderas i till summan
		summa += i;
	}
	return summa == t;		//om summan blir talet så returneras 1, annars 0
}

int main(){
	int tal;
	printf("Ange ett tal: ");
	scanf("%d",&tal);
	if(ar_perfekt_tal(tal))	//om 1 (funktionen har returnerat 1)
		printf("Talet %d är ett perfekt tal!", tal);
	else
		printf("Talet %d är inte ett perfekt tal!", tal);
	return 0;
}
