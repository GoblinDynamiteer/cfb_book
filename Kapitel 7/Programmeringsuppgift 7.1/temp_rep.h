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