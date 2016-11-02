#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <ctype.h>
#define N 300
#define TEXTFIL "kafka_vitatecken.txt"

/* Programmeringsuppgift 10.8, Sida 237 - repetition

Skriv ett program som l�ser in en befintlig textfil, 
och som skriver ut filens inneh�ll i kommandof�nstret.

Vid utskriften ska inga tomma rader eller rader som bara
inneh�ller blanka tecken skrivas ut.

tom rad = rad som enbart inneh�ller \n
blank rad = rad som enbart inneh�ller tab/mellanslag (vita tecken)

I �vrigt ska texten vara samma. */

int main(){
	FILE *fil = fopen(TEXTFIL, "r");
	char rad[N];
	while(fgets(rad, N, fil) != NULL){
		char *p = rad;
		while(*p){ //Medans inte nolltecken
			if(!isspace(*p)){ //Om inte vittecken
				printf("%s", rad);
				break;
			}
			p++;
		}
	}
	fclose(fil);
	return 0;
}