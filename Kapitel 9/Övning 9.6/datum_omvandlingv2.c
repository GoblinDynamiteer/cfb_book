#include <stdio.h>
#include <string.h>

/*
Övning 9.6, Sida 203

Gör om övning 9.5, fast använd funktionen strncpy
*/


int main(){
	char datum_sv[12];
	char datum_us[12] ="MM/DD/ÅÅÅÅ";
	printf("Ange svenskt datum som ÅÅÅÅ-MM-DD: ");
	scanf("%s", datum_sv);
	//char-arrays börjar också på 0
	/*
	
	strncpy används för att kopiera tecken från en char array till en annan
	
	strncpy(x,y,n)
	x är arrayen man vill kopiera till
	y är arrayen man vill kopiera från
	n är antal tecken
	
	för att börja på olika element i arrayen kan man skriva exempelvis
	x+1 y+5
	
	*/
	//MM Månad:
	strncpy(datum_us+0, datum_sv+5, 2);
	//datum_us[0] = datum_sv[5];
	//datum_us[1] = datum_sv[6];
	//DD Dag:
	strncpy(datum_us+3, datum_sv+8, 2);
	//datum_us[3] = datum_sv[8];
	//datum_us[4] = datum_sv[9];
	//ÅÅÅÅ År:
	strncpy(datum_us+6, datum_sv+0, 4);
	/*datum_us[6] = datum_sv[0];
	datum_us[7] = datum_sv[1];
	datum_us[8] = datum_sv[2];
	datum_us[9] = datum_sv[3];*/
	printf("Svensk datum: %s\nAmerikanskt datum: %s", datum_sv, datum_us);
	return 0;
}