#include <stdio.h>

/*
Programmeringsuppgift 4.5, Sida 91

En kommun: Invånare vid början av 2015: 26000. 
Födlsar/döda per år: 0,7% / 0,6%. 
In/utflyttningar per år: 300/325. 

Mata in år (efter 2015) för att se befolkningsprognos.

*/

int main(){
	double invanare = 26000; //går säkert med float också, jag har inte riktigt koll på när man bör använda vilket datatyp än
	int ar; //variabel för inmatat år
	printf("Ange år för att visa uppskattat invånarantal för kommunen: ");
	scanf("%d", &ar);
	for(int i=2015;i<ar;i++) //i utgår från 2015 och räknar uppåt 
		invanare=invanare+(invanare*0.07)-(invanare*0.06)+300-325; //invånare sätts till invånare plus 7% nyfödda (*0,07) minus 6% döda (*0,06) +/- in-/utflyttade
	printf("Invånarantalet i kommunen uppskattas vara %.0lf i början av år %d",invanare,ar); // %.0lf är format för double-datatypen, med 0 decimalsiffror
	return 0;
}

