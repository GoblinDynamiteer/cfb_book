#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 300
#define TEXTFIL "kafka_vitatecken.txt"

/* Programmeringsuppgift 10.8, Sida 237

Skriv ett program som läser in en befintlig textfil, 
och som skriver ut filens innehåll i kommandofönstret.

Vid utskriften ska inga tomma rader eller rader som bara
innehåller blanka tecken skrivas ut.

tom rad = rad som enbart innehåller \n
blank rad = rad som enbart innehåller tab/mellanslag (vita tecken)

I övrigt ska texten vara samma. 

V2: Texten skrivs ut så fort ett icke-vittecken hittas. Istället för en extra
if-sats med en Booleansk variabel. Koden kunde kortas ned väsentligt.
*/

int main(){
	FILE * textfil = fopen(TEXTFIL, "r");
	char s[N];
	_Bool HoppaRad;
	printf("%s utan tomma rader:\n\n", TEXTFIL);
	//while körs så länge fgets läser tecken från textfilen till s
	while(fgets(s, N, textfil) != NULL){
		for(int i=0;i<strlen(s);i++){
			//om ett icke-vittecken hitta skrivs raden ut.
			if(!isspace(s[i])){
				printf("%s", s);
				break;
			}
		}
	}
	return 0;
}
