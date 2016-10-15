#include <stdio.h>
#include "temp.h"

/*
Programmeringsuppgift 7.1, Sida 146

Skriv en modul som h�ller reda p� aktuell temperatur.

Modulen ska ha fyra funktioner:
observation: 			Rapportera uppm�tt temp, kontroller att inmatade v�rden �r rimliga
							3 parametrar: tid (timme och minut), temperatur
aktuell_temp:		Returnera senaste inmatade temperatur
obs_tim:				Returnera tid (timme) f�r senaste inmatade temperatur
obs_min:				Returnera tid (minuter) f�r senaste inmatade temperatur

Filer:
temp_main.c
temp.c
temp.h
*/

//Statiska variabler som h�ller senaste inmatade v�rden f�r temp och tidpunkt
static int SenasteTemp = 0;
static int SenasteTimme = 0;
static int SenasteMinut = 0;


/*funktion f�r inmatning av temperatur vid klockslag 
h=timmar
m=minuter
t=temp
ger 1 om inmatning �r rimlig, annars 0
*/
_Bool observation(int h,int m,int t){
	/*Kontroll f�r rimlighet i inmatning
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
