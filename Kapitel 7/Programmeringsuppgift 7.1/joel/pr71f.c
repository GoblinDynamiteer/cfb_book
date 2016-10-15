#include <stdio.h>
#include "pr71.h"

int timmar = 0; 
int minuter = 0;
double temperatur = 0.0;

/*_Bool observation(int tim, int min, double temp){
	
	if( (tim > 24) || (tim < 0) ||  (min > 60) || (min < 0) || (temp <-100) || (temp > 70))
		return 1; 
	else {
		timmar = tim;
		minuter = min; 
		temperatur = temp; 
		return 0;
	}	
	
}
*/
_Bool observation(int h,int m,double t){
	/*Kontroll för rimlighet i inmatning
	timme ska vara mellan 0-23
	minut ska vara mella 0-59
	temp mellan -60 till 60 */
	if (h < 24 && h > 0 && m < 60 && m > 0 && t < 60 && t > -61){
		minuter = m;
		temperatur = t;
		timmar = h;
		return 1;
		}
	else {
		return 0;
	}
}



double aktuell_temp(void){
	return temperatur;
	
	}
int obs_timmar(void){
	return timmar;
}	
int obs_minuter(void){
	return minuter; 
}