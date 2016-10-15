#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 300
#define TEXTFIL "kafka_vitatecken.txt"

/* Programmeringsuppgift 10.8, Sida 237

Skriv ett program som l�ser in en befintlig textfil, 
och som skriver ut filens inneh�ll i kommandof�nstret.

Vid utskriften ska inga tomma rader eller rader som bara
inneh�ller blanka tecken skrivas ut.

tom rad = rad som enbart inneh�ller \n
blank rad = rad som enbart inneh�ller tab/mellanslag (vita tecken)

I �vrigt ska texten vara samma. 

V2: Texten skrivs ut s� fort ett icke-vittecken hittas. Ist�llet f�r en extra
if-sats med en Booleansk variabel. Koden kunde kortas ned v�sentligt.
*/

int main(){
	FILE * textfil = fopen(TEXTFIL, "r");
	char s[N];
	_Bool HoppaRad;
	printf("%s utan tomma rader:\n\n", TEXTFIL);
	//while k�rs s� l�nge fgets l�ser tecken fr�n textfilen till s
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
