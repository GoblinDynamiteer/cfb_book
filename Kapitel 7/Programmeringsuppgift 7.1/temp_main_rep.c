/* 
Programmeringsuppgift 7.1, Sida 146 - repetition
Skriv en modul som h�ller reda p� aktuell temperatur. 
Den ska ha fyra funktioner: observation, aktuell_temp, obs_tim, obs_min. 

Observation anv�nds f�r att rapportera in uppm�tt temperatur vid klockslag 
(parametrar: temp, tim, min). 

De andra funktionerna ska returna senast inl�sta temp, tim, min. 

filer: 	temp_main_rep.c
			temp_rep.c
			temp_rep.h
*/

#include "temp_rep.h"
#include "libtxt.h"

int main(){
	int tim, min, c, val;
	double temp;
	while(1){
		printf("\n\nTEMP\n1. Mata in temperatur.\n2. Visa senaste inmatning.");
		printLine('*', 40, 1);
		val = inputInt("Ange val: ");
		switch(val){
			case 1:
				do{
					temp = inputDouble("Mata in temperatur: ");
					printf("Skriv in tid: xx:xx: ");
					scanf("%d%c%d", &tim, &c, &min); //c f�ngar upp ':'
				}while(!observation(temp, min, tim));
				break;
			case 2:
				printf("Senaste inmatning: %.2f grader vid %d:%d", 
					aktuell_temp(),
					obs_tim(),
					obs_min());
				break;
			default:
				printf("Fel inmatning, avslutar!");
				return 0;
		}
	}
return 0;
}