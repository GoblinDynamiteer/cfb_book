#include <stdio.h>

/* Övning 11.5, Sida 254

Bygg en egen version av strcat (se sida 203)

Tips: Börja med att ta fram en pekare till nolltecknet i slutet på den text du skall kopiera till
Kopiera sedan till detta ställe som strcpy (Sida 254) */

//strcat lägger en textrad i slutet på en annan, text ska få text+tillagg
void strcat_egen(char *text, const char *tillagg){
	/*While-sats som kör sålänge text-pekare inte är nolltecken
	 
	Författaren använder:
	------------------------------
	while(*till)  // sök nolltecknet
	till++;
	------------------------------
	
	då behöver han inte backa med en, som jag gör efter while-satsen
	*/
	while(*text++){
		;
	}
	//backar med 1, är inte helt säker på varför det måste göras, men annars kommer nolltecknet med i strängen
	*text--;
	//tillagg läggs till i slutet av text, jag antar att wilesatsen slutar när nolltecken hittas i tillagg?
	while (*text++ = *tillagg++){
		;
	}
}

int main(){
	char text[40] = "Jag ska stå först - !";
	strcat_egen(text, "! - Sedan ska jag stå!");
	printf("Text efter funktion: %s", text);
	return 0;
}