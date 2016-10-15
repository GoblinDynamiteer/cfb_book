#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Övning 9.10, Sida 213

Skriv en funktion remove_white, som kopierar en text till
en sträng från en annan, samt tar bort alla vita tecken.

Funktionen ska ha två pekare: to & from som parametrar.
*/

/* Funktion som kopierar text från en sträng till en annan
och plockar bort alla vita tecken. */
void remove_white(char *to, char *from){
	//raknare används för array-indexnummer i 'to'-strängen
	int raknare=0;
	//for-loop som kör så länge ett noll-tecken inte hittas i 'from'-strängen
	for(int i=0;from[i]!='\0';i++){
		//if-sats som triggar om tecken inte är ett vitt tecken (! inverterar)
		if(!isspace(from[i])){
		to[raknare] = from[i];
		raknare++;
		} 
	}
	//sätter nolltecken i slutet av strängen.
	to[raknare] = '\0';
}

int main(){
	//textsträngar för test av funktionen, samt utskrifter före och efter funktionens anrop
	char till[25] = "1 2 3 4 5 6 7 8 9 10 11";
	char fran[25] = "U T A N S P A C E";
	printf("FRÅN: %s\nTILL: %s\n", fran, till);
	remove_white(till, fran);
	puts("-------------------");
	printf("TILL EFTER FUNKTION: %s\n", till);
}