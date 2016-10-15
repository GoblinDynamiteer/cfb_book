#include <stdio.h>

/*
Programmeringsuppgift 6.8, Sida 122

Skriv en funktion som avg�r om ett positivt tal �r "perfekt".

Perfekta tal �r tal d�r summan av talets produkter blir lika med talet
Jag antar att det �r del tal d�r division g�r j�mnt ut?

Faktor * Faktor = Produkt

https://www.wikiwand.com/sv/Perfekt_tal

Exempel: 
6 = 1 + 2 + 3	1
28 = 1 + 2 + 4 + 7 + 14
496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248
*/

//Funktion f�r avg�rande om ett tal �r perfekt
_Bool ar_perfekt_tal(int t){
	int summa = 0; 				//summan som ska j�mf�ras med talet
	for(int i=1;i!=t;i++){		//k�rs s� l�nge i inte �r talet
	if (t % i == 0)					//om talet �r j�mnt delbart med i, s� adderas i till summan
		summa += i;
	}
	return summa == t;		//om summan blir talet s� returneras 1, annars 0
}

int main(){
	int tal;
	printf("Ange ett tal: ");
	scanf("%d",&tal);
	if(ar_perfekt_tal(tal))	//om 1 (funktionen har returnerat 1)
		printf("Talet %d �r ett perfekt tal!", tal);
	else
		printf("Talet %d �r inte ett perfekt tal!", tal);
	return 0;
}
