#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 11.1, Sida 275

Skriv en funktion som v�nder p� tecknen i en textstr�ng
med hj�lp av tv� pekare. Den enda parametern till funktionen
ska vara textstr�ngen! */


void vandText(char *string){
	//Pekare som s�tts till pekaren till textstr�ngen
	char *start = string;
	//Pekare som s�tts till pekaren till textstr�ngen + str�ngens l�ngd (-1 f�r att pekare b�rjar p� noll)
	char *end = string+strlen(string)-1;
	//Variabel som h�ller bokstav tempor�rt, f�r varje byte av tecken 
	int tempBokstav;
	/*While-loop som k�r s� l�nge start �r mindre �n end, 
	bokst�ver kommer byta plats fr�n str�ngens b�da �ndar tills "mitten" m�ts */
	while (start < end){
		tempBokstav = *end;
		*end = *start;
		*start = tempBokstav;
		start++;
		end--;
	}
}

int main(){
	char textAttVanda[50] = "V�nd mig OK? - V�nd mig OK!";
	vandText(textAttVanda);
	printf("%s", textAttVanda);
}