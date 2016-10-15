#include <stdio.h>
#include <string.h>

/*
Programmeringsuppgift 9.1, Sida 214

Skriv en funktion kallad 'baklanges', som kopierar en text
från ett fält till ett annat, gör kopieringen baklänges!
*/

//Funktion som kopierar en text till en sträng från en annan baklänges
void baklanges(char *till, char *fran){
	//Räknare för till-strängens index
	int raknare = 0;
	/* 	
	forsatsen sätts till stränglängden av från, minus 1 (sista är nolltecken i en textsträng)
	satsen räknar nedåt till noll, så att den plockar bokstäverna bakifrån från fran-strängens
	*/
	for(int i=strlen(fran)-1;i>=0;i--){
		till[raknare] = fran[i];
		raknare++;
	}
	//sist till till-strängen skrivs ett nolltecken.
	till[raknare]='\0';
}

int main(){
	char till[30] = "";
	char fran[30] = "EPMÄK NAHOJ";
	puts("---------------------------------------");
	printf("TILL INNAN FUNKTION: %s\n", fran);
	baklanges(till, fran);
	printf("TILL EFTER FUNKTION: %s\n", till);
	puts("---------------------------------------");
}