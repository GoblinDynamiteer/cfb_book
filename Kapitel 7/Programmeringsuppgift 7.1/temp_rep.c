/* 
Programmeringsuppgift 7.1, Sida 146 - repetition
Skriv en modul som håller reda på aktuell temperatur. 
Den ska ha fyra funktioner: observation, aktuell_temp, obs_tim, obs_min. 

Observation används för att rapportera in uppmätt temperatur vid klockslag 
(parametrar: temp, tim, min). 

De andra funktionerna ska returna senast inlästa temp, tim, min. 

filer: 	temp_main_rep.c
			temp_rep.c
			temp_rep.h
*/

#include "temp_rep.h"
#include "libtxt.h"

_Bool observation(double temp_in, int m_in, int t_in){
	if(temp_in < -50 || temp_in > 60){
		printf("Felaktig temp!\n");
		return 0;
	}
	if(m_in < 0 || m_in > 59){
		printf("Felaktig tidinmatning !\n");
		return 0;
	}
	if(t_in < 0 || t_in > 23){
		printf("Felaktig tidinmatning !\n");
		return 0;
	}

	temp = temp_in;
	tim = t_in;
	min = m_in;
	return 1;
}

double aktuell_temp(void){
	return temp;
}

int obs_tim(void){
	return tim;
}

int obs_min(void){
	return min;
}
