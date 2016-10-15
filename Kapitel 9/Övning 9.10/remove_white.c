#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
�vning 9.10, Sida 213

Skriv en funktion remove_white, som kopierar en text till
en str�ng fr�n en annan, samt tar bort alla vita tecken.

Funktionen ska ha tv� pekare: to & from som parametrar.
*/

/* Funktion som kopierar text fr�n en str�ng till en annan
och plockar bort alla vita tecken. */
void remove_white(char *to, char *from){
	//raknare anv�nds f�r array-indexnummer i 'to'-str�ngen
	int raknare=0;
	//for-loop som k�r s� l�nge ett noll-tecken inte hittas i 'from'-str�ngen
	for(int i=0;from[i]!='\0';i++){
		//if-sats som triggar om tecken inte �r ett vitt tecken (! inverterar)
		if(!isspace(from[i])){
		to[raknare] = from[i];
		raknare++;
		} 
	}
	//s�tter nolltecken i slutet av str�ngen.
	to[raknare] = '\0';
}

int main(){
	//textstr�ngar f�r test av funktionen, samt utskrifter f�re och efter funktionens anrop
	char till[25] = "1 2 3 4 5 6 7 8 9 10 11";
	char fran[25] = "U T A N S P A C E";
	printf("FR�N: %s\nTILL: %s\n", fran, till);
	remove_white(till, fran);
	puts("-------------------");
	printf("TILL EFTER FUNKTION: %s\n", till);
}