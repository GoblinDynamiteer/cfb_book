#include <stdio.h>
#include "temp.h"

/*
Programmeringsuppgift 7.1, Sida 146

Skriv en modul som håller reda på aktuell temperatur.

Modulen ska ha fyra funktioner:
observation: 			Rapportera uppmätt temp, kontroller att inmatade värden är rimliga
							3 parametrar: tid (timme och minut), temperatur
aktuell_temp:		Returnera senaste inmatade temperatur
obs_tim:				Returnera tid (timme) för senaste inmatade temperatur
obs_min:				Returnera tid (minuter) för senaste inmatade temperatur

Filer:
temp_main.c
temp.c
temp.h
*/

//Statiska variabler som håller senaste inmatade värden för temp och tidpunkt
static int SenasteTemp = 0;
static int SenasteTimme = 0;
static int SenasteMinut = 0;


/*funktion för inmatning av temperatur vid klockslag 
h=timmar
m=minuter
t=temp
ger 1 om inmatning är rimlig, annars 0
*/
_Bool observation(int h,int m,int t){
	/*Kontroll för rimlighet i inmatning
	timme ska vara mellan 0-23
	minut ska vara mella 0-59
	temp mellan -60 till 60 */
	if (h < 24 && h > 0 && m < 60 && m > 0 && t < 60 && t > -61){
		SenasteMinut = m;
		SenasteTemp = t;
		SenasteTimme = h;
		return 1;
		}
	else {
		return 0;
	}
}

//Funktion om returnerar senaste temperatur
int aktuell_temp(void){
	return SenasteTemp;
}

//Funktion om returnerar senaste tid(h)
int obs_tim(void){
	return SenasteTimme;
}

//Funktion om returnerar senaste tid(m)
int obs_min(void){
	return SenasteMinut;
}
