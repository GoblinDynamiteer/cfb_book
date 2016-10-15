#include <stdio.h>
#include <string.h>

/*
Programmeringsuppgift 9.1, Sida 214

Skriv en funktion kallad 'baklanges', som kopierar en text
fr�n ett f�lt till ett annat, g�r kopieringen bakl�nges!
*/

//Funktion som kopierar en text till en str�ng fr�n en annan bakl�nges
void baklanges(char *till, char *fran){
	//R�knare f�r till-str�ngens index
	int raknare = 0;
	/* 	
	forsatsen s�tts till str�ngl�ngden av fr�n, minus 1 (sista �r nolltecken i en textstr�ng)
	satsen r�knar ned�t till noll, s� att den plockar bokst�verna bakifr�n fr�n fran-str�ngens
	*/
	for(int i=strlen(fran)-1;i>=0;i--){
		till[raknare] = fran[i];
		raknare++;
	}
	//sist till till-str�ngen skrivs ett nolltecken.
	till[raknare]='\0';
}

int main(){
	char till[30] = "";
	char fran[30] = "EPM�K NAHOJ";
	puts("---------------------------------------");
	printf("TILL INNAN FUNKTION: %s\n", fran);
	baklanges(till, fran);
	printf("TILL EFTER FUNKTION: %s\n", till);
	puts("---------------------------------------");
}