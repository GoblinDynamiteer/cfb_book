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

#include <stdio.h>

//Delade variabler
double temp;
int tim;
int min;

//Deklaration av funktioner i temp_rep.c
_Bool observation(double temp_in, int m_in, int t_in);
double aktuell_temp(void);
int obs_tim(void);
int obs_min(void);