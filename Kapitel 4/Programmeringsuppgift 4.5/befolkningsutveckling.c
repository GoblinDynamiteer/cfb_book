#include <stdio.h>

/*
Programmeringsuppgift 4.5, Sida 91

En kommun: Inv�nare vid b�rjan av 2015: 26000. 
F�dlsar/d�da per �r: 0,7% / 0,6%. 
In/utflyttningar per �r: 300/325. 

Mata in �r (efter 2015) f�r att se befolkningsprognos.

*/

int main(){
	double invanare = 26000; //g�r s�kert med float ocks�, jag har inte riktigt koll p� n�r man b�r anv�nda vilket datatyp �n
	int ar; //variabel f�r inmatat �r
	printf("Ange �r f�r att visa uppskattat inv�narantal f�r kommunen: ");
	scanf("%d", &ar);
	for(int i=2015;i<ar;i++) //i utg�r fr�n 2015 och r�knar upp�t 
		invanare=invanare+(invanare*0.07)-(invanare*0.06)+300-325; //inv�nare s�tts till inv�nare plus 7% nyf�dda (*0,07) minus 6% d�da (*0,06) +/- in-/utflyttade
	printf("Inv�narantalet i kommunen uppskattas vara %.0lf i b�rjan av �r %d",invanare,ar); // %.0lf �r format f�r double-datatypen, med 0 decimalsiffror
	return 0;
}

