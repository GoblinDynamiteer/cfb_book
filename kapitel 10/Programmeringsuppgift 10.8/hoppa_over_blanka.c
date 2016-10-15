#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 300
#define TEXTFIL "kafka_vitatecken.txt"

/* Programmeringsuppgift 10.8, Sida 237

Skriv ett program som l�ser in en befintlig textfil, 
och som skriver ut filens inneh�ll i kommandof�nstret.

Vid utskriften ska inga tomma rader eller rader som bara
inneh�ller blanka tecken skrivas ut.

tom rad = rad som enbart inneh�ller \n
blank rad = rad som enbart inneh�ller tab/mellanslag (vita tecken)

I �vrigt ska texten vara samma. */

int main(){
	FILE * textfil = fopen(TEXTFIL, "r");
	char s[N];
	_Bool HoppaRad;
	printf("%s utan return- eller vittecken:\n\n", TEXTFIL);
	//while k�rs s� l�nge fgets l�ser tecken fr�n textfilen till s
	while(fgets(s, N, textfil) != NULL){
		HoppaRad = 0;
		for(int i=0;i<strlen(s);i++){
			//om ett tecken hittas p� raden som inte �r ett vittecken s�tts HoppaRad till 0
			if(!isspace(s[i])){
				HoppaRad = 0;
				break;
			}
			//om enbart vittecken hittas s�tts HoppaRad till 1
			else{
				HoppaRad = 1;
			}
		}
		//Om (!inverterad) HoppaRad �r 1 och f�rsta tecknet i str�ngen inte �r newline, s� skrivs raden ut
		if(!HoppaRad && s[0] != '\n'){
			printf("%s", s);
		}
	}
	return 0;
}