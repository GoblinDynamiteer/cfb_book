
#include <stdio.h>
#include "temp.h"
#define L "\n----------------------------------\n" 

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

int main(){
	int temp, timme, minuter, val, kor = 1;
	while (kor){ //k�r whilesatsen s� l�nge variabel kor == 1
		printf("%sTEMPERATUROBSERVATION%sVal:\n1 -- Mata in observation\n2 -- Se senaste inmatning\n3 -- Avsluta\nVal: ",L,L);
		scanf("%d",&val);
		switch(val){
			case 1:
				printf("Mata in temperatur: ");
				scanf("%d", &temp);
				printf("Mata in timme: ");
				scanf("%d", &timme);
				printf("Mata in minuter: ");
				scanf("%d", &minuter);
				if (observation(timme, minuter, temp))
					printf("Inmatning OK!");
				else
					printf("%s!! OBS Inmatning inte korrekt, f�rs�k igen !!",L);
				break;
			case 2:
				printf("%sSenaste observation: kl %d:%d - %d grader.",L,obs_tim(),obs_min(),aktuell_temp());
				break;
			case 3:
				kor = 0; //S�tter kor till 0, while-satsen kommer avslutas.
				break;
			default:
				printf("Fel val!");
		}
	}
	return 0;
}