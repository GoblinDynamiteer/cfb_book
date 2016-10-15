#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 11.1, Sida 275

Skriv en funktion som vänder på tecknen i en textsträng
med hjälp av två pekare. Den enda parametern till funktionen
ska vara textsträngen! */


void vandText(char *string){
	//Pekare som sätts till pekaren till textsträngen
	char *start = string;
	//Pekare som sätts till pekaren till textsträngen + strängens längd (-1 för att pekare börjar på noll)
	char *end = string+strlen(string)-1;
	//Variabel som håller bokstav temporärt, för varje byte av tecken 
	int tempBokstav;
	/*While-loop som kör så länge start är mindre än end, 
	bokstäver kommer byta plats från strängens båda ändar tills "mitten" möts */
	while (start < end){
		tempBokstav = *end;
		*end = *start;
		*start = tempBokstav;
		start++;
		end--;
	}
}

int main(){
	char textAttVanda[50] = "Vänd mig OK? - Vänd mig OK!";
	vandText(textAttVanda);
	printf("%s", textAttVanda);
}