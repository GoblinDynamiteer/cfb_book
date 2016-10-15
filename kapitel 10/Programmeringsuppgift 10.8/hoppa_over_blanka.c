#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 300
#define TEXTFIL "kafka_vitatecken.txt"

/* Programmeringsuppgift 10.8, Sida 237

Skriv ett program som läser in en befintlig textfil, 
och som skriver ut filens innehåll i kommandofönstret.

Vid utskriften ska inga tomma rader eller rader som bara
innehåller blanka tecken skrivas ut.

tom rad = rad som enbart innehåller \n
blank rad = rad som enbart innehåller tab/mellanslag (vita tecken)

I övrigt ska texten vara samma. */

int main(){
	FILE * textfil = fopen(TEXTFIL, "r");
	char s[N];
	_Bool HoppaRad;
	printf("%s utan return- eller vittecken:\n\n", TEXTFIL);
	//while körs så länge fgets läser tecken från textfilen till s
	while(fgets(s, N, textfil) != NULL){
		HoppaRad = 0;
		for(int i=0;i<strlen(s);i++){
			//om ett tecken hittas på raden som inte är ett vittecken sätts HoppaRad till 0
			if(!isspace(s[i])){
				HoppaRad = 0;
				break;
			}
			//om enbart vittecken hittas sätts HoppaRad till 1
			else{
				HoppaRad = 1;
			}
		}
		//Om (!inverterad) HoppaRad är 1 och första tecknet i strängen inte är newline, så skrivs raden ut
		if(!HoppaRad && s[0] != '\n'){
			printf("%s", s);
		}
	}
	return 0;
}