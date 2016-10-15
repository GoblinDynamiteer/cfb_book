#include <stdio.h>

/* �vning 11.5, Sida 254

Bygg en egen version av strcat (se sida 203)

Tips: B�rja med att ta fram en pekare till nolltecknet i slutet p� den text du skall kopiera till
Kopiera sedan till detta st�lle som strcpy (Sida 254) */

//strcat l�gger en textrad i slutet p� en annan, text ska f� text+tillagg
void strcat_egen(char *text, const char *tillagg){
	/*While-sats som k�r s�l�nge text-pekare inte �r nolltecken
	 
	F�rfattaren anv�nder:
	------------------------------
	while(*till)  // s�k nolltecknet
	till++;
	------------------------------
	
	d� beh�ver han inte backa med en, som jag g�r efter while-satsen
	*/
	while(*text++){
		;
	}
	//backar med 1, �r inte helt s�ker p� varf�r det m�ste g�ras, men annars kommer nolltecknet med i str�ngen
	*text--;
	//tillagg l�ggs till i slutet av text, jag antar att wilesatsen slutar n�r nolltecken hittas i tillagg?
	while (*text++ = *tillagg++){
		;
	}
}

int main(){
	char text[40] = "Jag ska st� f�rst - !";
	strcat_egen(text, "! - Sedan ska jag st�!");
	printf("Text efter funktion: %s", text);
	return 0;
}